/*
 * File:   newmain.c
 * Author: gabii
 *
 * Created on 2 de junio de 2022, 06:11 PM
 */


#include <xc.h>
#include "device_config.h.txt"

void init_ports (void);
void interrupt_int0(void);  //Interrupt high priority

#define green1 PORTDbits.RD6
#define yellow1 PORTDbits.RD5
#define red1 PORTDbits.RD4
#define green2 PORTDbits.RD2
#define yellow2 PORTDbits.RD1
#define red2 PORTDbits.RD0
#define walk1 PORTDbits.RD7
#define walk2 PORTDbits.RD3
#define button PORTBbits.RB2

void__interrupt (high_priority) interrupt_int0(void){
    _delay_ms(20);
    if (button==1);
    red1 = 1;
    red2 = 1;
    walk1=1;
    walk2=1;
    
    INTCONbits.INT0IF = 0;
    
}

void main (void){
    init_ports();
    INTCONbits.INT0IF = 0;
    INTCONbits.INT0IE = 1;
    
    while(1){
      green1=0;
      yellow1=0;
      red1=1;
      green2=1;
      yellow2=0;
      red2=0;
      _delay_ms(3000);
      
      green1=0;
      yellow1=0;
      red1=1;
      green2=0;
      yellow2=1;
      red2=0;
      _delay_ms(1000);
      
      green1=1;
      yellow1=0;
      red1=0;
      green2=0;
      yellow2=0;
      red2=1;
      _delay_ms(3000);
      
      green1=0;
      yellow1=1;
      red1=0;
      green2=0;
      yellow2=0;
      red2=1;
      _delay_ms(1000);
      
    }
    
    void init_ports(void){
        TRISD = 0b00000000;
        ANSELD = 0b00000000;  
        TRISBbits.TRISB2=1;
        ANSELBbits.ANSB2=0;
        
    }
}