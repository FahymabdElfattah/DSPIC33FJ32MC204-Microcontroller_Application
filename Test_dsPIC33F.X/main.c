#define FCY 4000000
#define _XTAL_FREQ  4000000

#include "xc.h"
#include "config.h"
#include <libpic30.h>



void init_port();
void init_PLL();

int main(void) {
    init_PLL();
    init_port();
    
    while(1){
        if(PORTCbits.RC0 == 1){
            PORTBbits.RB0 = 1;
        }
        PORTBbits.RB1 = 1;
        __delay_ms(1000);
        PORTBbits.RB1 = 0;
        __delay_ms(1000);
    }
    return 0;
}
void init_port(){
    AD1PCFGL = 0xFFFF ;
    TRISCbits.TRISC0 = 1;
    TRISCbits.TRISC1 = 1 ;
    TRISBbits.TRISB0 = 0;
    TRISBbits.TRISB1 = 0 ;
    PORTB = 0x0000 ;
}
void init_PLL(){
   // CONFIGURATION Of PLL
    PLLFBDbits.PLLDIV = 0x06 ;//M=8
    CLKDIVbits.PLLPRE = 0;//N1=2
    CLKDIVbits.PLLPOST = 0;//N2=2 
}