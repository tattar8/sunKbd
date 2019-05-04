#include "scancodes.h"
#include <stdint.h>

uint8_t makeScanCodesLUT[255];

//a hack, should change to statically initialize later.  Only done
//because the LUT isn't fully complete yet.
void scancodes_init(){
    makeScanCodesLUT['a'] = 0x4D;
    makeScanCodesLUT['b'] = 0x68;
    makeScanCodesLUT['c'] = 0x66;
    makeScanCodesLUT['d'] = 0x4F;
    makeScanCodesLUT['e'] = 0x38;
    makeScanCodesLUT['f'] = 0x50;
    makeScanCodesLUT['g'] = 0x51;
    makeScanCodesLUT['h'] = 0x52;
    makeScanCodesLUT['i'] = 0x3D;
    makeScanCodesLUT['j'] = 0x53;
    makeScanCodesLUT['k'] = 0x54;
    makeScanCodesLUT['l'] = 0x55;
    makeScanCodesLUT['m'] = 0x6A;
    makeScanCodesLUT['n'] = 0x69;
    makeScanCodesLUT['o'] = 0x3E;
    makeScanCodesLUT['p'] = 0x3F;
    makeScanCodesLUT['q'] = 0x36;
    makeScanCodesLUT['r'] = 0x39;
    makeScanCodesLUT['s'] = 0x4E;
    makeScanCodesLUT['t'] = 0x3A;
    makeScanCodesLUT['u'] = 0x3C;
    makeScanCodesLUT['v'] = 0x67;
    makeScanCodesLUT['w'] = 0x37;
    makeScanCodesLUT['x'] = 0x65;
    makeScanCodesLUT['y'] = 0x3B;
    makeScanCodesLUT['z'] = 0x64;
    makeScanCodesLUT['.'] = 0x6C;
    makeScanCodesLUT[' '] = 0x79;
    makeScanCodesLUT['0'] = 0x27;
    makeScanCodesLUT['1'] = 0x1E;
    makeScanCodesLUT['2'] = 0x1F;
    makeScanCodesLUT['3'] = 0x20;
    makeScanCodesLUT['4'] = 0x21;
    makeScanCodesLUT['5'] = 0x22;
    makeScanCodesLUT['6'] = 0x23;
    makeScanCodesLUT['7'] = 0x24;
    makeScanCodesLUT['8'] = 0x25;
    makeScanCodesLUT['9'] = 0x26;
    makeScanCodesLUT['-'] = 0x28;
    makeScanCodesLUT['/'] = 0x2E;
 

    makeScanCodesLUT['\r'] = 0x59;
    makeScanCodesLUT[KEY_SHIFT] = 0x6E;
    makeScanCodesLUT[KEY_CMD] = 0x13;
    makeScanCodesLUT[KEY_CTRL] = 0x4C;
    makeScanCodesLUT['\t'] = 0x35;
    makeScanCodesLUT[KEY_UP_ARROW] = 0x45;
    makeScanCodesLUT[KEY_DN_ARROW] = 0x71;
    makeScanCodesLUT[KEY_LT_ARROW] = 0x5B;
    makeScanCodesLUT[KEY_RT_ARROW] = 0x5D;
    makeScanCodesLUT[KEY_BKSP] =  0x2B;

}