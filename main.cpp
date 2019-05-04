#include "mbed.h"
#include "scancodes.h"

Serial usbSerial(USBTX, USBRX);

//tx = pte0, rx = pte1
//The Sun serial runs on UART1, 1200b, 8N1
Serial sunSerial(PTE0, PTE1, 1200);

/**
 * ISR for Rx on the Sun side UART (UART1)
 **/
void sunSerialRxCb(){
    //Reading the byte will clear the ISR
    uint8_t rcvdByte = sunSerial.getc();

    //Print to the USB serial (UART0)
    usbSerial.printf("Sun: %02X \r\n", rcvdByte);

    //Handle cases that need a response from the keyboard.

    //0x01 is the reset command; the Sun expects 0xFF 0x04 0x7F as a normal response
    if (rcvdByte == 0x01){
        sunSerial.putc(0xFF);
        sunSerial.putc(0x04);
        sunSerial.putc(0x7F);
        usbSerial.printf("Reset \r\n");
    }

    //0x0F is a keyboard layout request.  At this time the response is hardcoded as 0x0, which indicate US layout.
    if (rcvdByte == 0x0F){
        sunSerial.putc(0x0);
        usbSerial.printf("Layout \r\n");
    }
}

int main(){
    //Invert the Rx and Tx of the sun serial (UART1) since the Sun expects and sends out inverted UART signals
    UART1 -> S2 |= UART_S2_RXINV_MASK;
    UART1 -> C3 |= UART_C3_TXINV_MASK;

    //Register ISR to the interrupt handler, and enable Rx IRQ
    sunSerial.attach(&sunSerialRxCb, Serial::RxIrq);

    //Initialize the scancode array
    scancodes_init();
    usbSerial.printf("Ready\r\n");

    while(1){
        uint8_t rcvdByte = usbSerial.getc();
        usbSerial.printf("USB: %02X \r\n", rcvdByte);

        //Get the make scancode for the character
        uint8_t transByte = makeScanCodesLUT[rcvdByte];

        //Handle special cases (such as control keys on the keyboard)
        if(rcvdByte == 0x96) transByte = makeScanCodesLUT[KEY_CTRL];
        if(rcvdByte == 0x97) transByte = makeScanCodesLUT[KEY_CTRL] + BRK_OFFSET;
        if(rcvdByte == 0x98) transByte = 0x01;
        if(rcvdByte == 0x99) transByte = 0x81;
        
        usbSerial.printf("Sending: %02X \r\n", transByte);
        if (transByte == 0) continue; //drop unimplemented chars
        
        //Handle caps by sending shift along with the byte in question
        if (rcvdByte >= 'A' && rcvdByte <= 'Z') sunSerial.putc(KEY_SHIFT);
        sunSerial.putc(transByte);

        //Clear the shift key if the character was capital
        if (rcvdByte >= 'A' && rcvdByte <= 'Z') sunSerial.putc(KEY_SHIFT + BRK_OFFSET);

        //Except in the event of a special case (since it's preferable to leave that key pressed until explicitly broken)
        //clear the pressed key by sending the scancode + the break offset
        if (rcvdByte < 0x95) sunSerial.putc(transByte + BRK_OFFSET);

       
    }
}
