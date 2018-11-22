#include "chario.h"
#define JTAG_UART_DATA ((volatile unsigned int *) 0x10001000)
#define JTAG_UART_STATUS ((volatile unsigned int *) 0x10001004)

void PrintChar(int ch){
    unsigned int wstatus;
    do
    {
        wstatus = *JTAG_UART_STATUS;
        wstatus = wstatus & 0xFFFF0000;
    } while (wstatus == 0);
    *JTAG_UART_DATA = ch;
}

void PrintString (char *s){
    int i;
    i = 0;
    while (s[i] != 0)
    {
        PrintChar(s[i]);
        i++;
    }
}
