/*
 * File:   main.c
 * Author: gabii
 *
 * Created on 30 de mayo de 2022, 12:59 PM
 */


#include <xc.h>

//Libraries/headers

#include "device_config.h.txt"
#include <math.h>

//Directive section

#define _XTAL_FREQ 1000000 
#define DELAY_SWEEP 300 

//Data type section

enum exponent{ bbase = 2, limit = 8 }; 
enum por_dir{ output, input };
enum por_ACDC { digital, analog };   
enum resistor_state { set_ON, res_ON }; 
enum led_state { led_OFF, led_ON };
enum button_state { pushed, no_pushed };

//function declaration/section

void portsInit( void ) {
ANSELB = digital;
TRISB  = 0x00;
ANSELD = digital;
TRISD  = 0xFF;

} 

//Main section

void main( void ){
    portsInit();
    char molePosition, buttonStatus = 0;
    while(1){
        unsigned char num = rand() % 8 ;
        switch(num) {
            case 0:
                molePosition = 0x01;
                break;
            case 1:
                molePosition = 0x02;
                break;
            case 2:
                molePosition = 0x04;
                break;
            case 3:
                molePosition = 0x08;
                break;
            case 4:
                molePosition = 0x10;
                break;
            case 5:
                molePosition = 0x20;
                break;
            case 6:
                molePosition = 0x40;
                break;
            default:
                molePosition = 0x80;
                break;
        }

        LATA = molePosition;
        __delay_ms(1000);
        buttonStatus = ~PORTD;
        if (molePosition == buttonStatus)
        {
            for (unsigned char i = 0; i < 7; i++){
                LATA = (unsigned char) pow(2, i);
                __delay_ms(100);
            }
            for (unsigned char i = 7; i > 0; i--){
                LATA = (unsigned char) pow(2, i);
                __delay_ms(100);
            }   
            LATA = 0x01;
            __delay_ms(100);
        }
    }
}



