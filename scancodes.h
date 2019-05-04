#include <stdint.h>

//Defines for all the special keys that aren't always sent the same way.
#define KEY_UP_ARROW 0x80
#define KEY_DN_ARROW 0x81
#define KEY_LT_ARROW 0x82
#define KEY_RT_ARROW 0x83
#define KEY_ESC 0x84
#define KEY_CMD 0x85
#define KEY_OPT 0x86
#define KEY_CTRL 0x87
#define KEY_F1 0x88
#define KEY_F2 0x89
#define KEY_F3 0x8A
#define KEY_F4 0x8B
#define KEY_F5 0x8C
#define KEY_F6 0x8D
#define KEY_F7 0x8E
#define KEY_F8 0x8F
#define KEY_F9 0x90
#define KEY_F10 0x91
#define KEY_F11 0x92
#define KEY_F12 0x93
#define KEY_SHIFT 0x94
#define KEY_BKSP 0x8

//The Sun keyboard indicates a key being released by sending its scancode + 0x80.
#define BRK_OFFSET 0x80

//Function to 
void scancodes_init();

extern uint8_t makeScanCodesLUT[255];