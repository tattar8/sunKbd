# sunKbd
Code to emulate a Sun proprietary keyboard (Mouse will be emulated in the future). Partially implemented using the Mbed OS 2.1 abstraction layer.

The Sun keyboard communicates over inverted UART, running at 1200 baud, 8N1.  Each key on the keyboard sends a defined 1-byte scan code when pressed and released.  The break code is always 0x80 added to the press/make code.

This project automatically responds to certain commands from the Sun host, namely those that are needed to convince the host that the keyboard is actually present.  Currently, the project is hard coded to report to the host that the attached keyboard uses the US layout.

This project targets the Freescale/NXP KL46Z Freedom board, using two of its hardware UARTs.
#### Usage
This project encodes ASCII letters received over UART0 (9600, 8N1) into the corresponding scancodes and outputs them over UART1.  For special keys, the following bytes can be sent:
0x80 - Up arrow
0x81 - Down arrow
0x82 - Left arrow
0x83 - Right arrow
0x84 - Esc
0x85 - Alt
0x86 - Opt
0x87 - Control
0x88-0x93 - F1-F12
0x94 - Shift

The following are special cases used where the break code isn't automatically sent (to facilitate key combinations):
0x96 - Control Press
0x97 - Control Release
0x98 - Stop Press
0x99 - Stop Release

