/*
 * File:   main.c
 * Author: Roanne Khaled Mohamed
 *
 * Created on April 4, 2020, 6:24 PM
 */
#define F_CPU 16000000UL


#include <avr/io.h>
#include <util/delay.h>
#include "Config.h"
#include "DIO.h"
#include "lcd.h"


#define BUTTON2         2 // In portD
#define LED2            3 // OUT portD

#define BUTTON1         4// In portB
#define LED1            7 //OUT portC

#define BUTTON0         0// In portB
#define LED0            2 // OUT portC

#define Buzzer         3

#define portA           1
#define portB           2
#define portC           3
#define portD           4


char *statement;

int i = 0;
//char h[]="hello world";
char x_0[] = "LED0 is ON";
char y_0[] = "LED0 is OFF";
char x_1[] = "LED1 is ON";
char y_1[] = "LED1 is OFF";
char x_2[] = "LED2 is ON";
char y_2[] = "LED2 is OFF";
char flag2 = 0;char flag1 = 0;char flag0 = 0;

int main(void) 
{




    LCD_Init();//initiating the Lcd as out
    //examples:
    //LCD_Char("A");
    //LCD_String(statement);// It didnot appear anything wrong
    //LCD_String(h);
    LCD_Clear();
     
    resetPIN(Buzzer, portA); // Turn Buzzer OFF
    PINDas(BUTTON2, IN);
    PINDas(LED2, OUT);
    resetPIN(LED2, portD); // initialization// LED2 init OFF
                          // initial state =0
    
    // FOR MULTIPLE LED 
    PINBas(BUTTON1, IN);
    PINCas(LED1, OUT);
    resetPIN(LED1, portC);
    
    PINBas(BUTTON0, IN);
    PINCas(LED0, OUT);
    resetPIN(LED0, portC);
   // LCD_String(y);
    while (1)
    {
        
          // 
            /*togglePIND(LED);
            if (PIND & 1<<LED)
            {
                LCD_Clear();
                LCD_String(x);
            }else
            {
               LCD_Clear();
                LCD_String(y); 
            }
             *}
        */ 
         
        if (isPressedD(BUTTON2)) 
        {
            flag2 ^= 1;
            togglePIND(LED2);

            if (flag2) {
                LCD_Clear();
                LCD_String(x_2);
            } else {
                LCD_Clear();
                LCD_String(y_2);
            }
            _delay_ms(200);
        }
        else if(isPressedB(BUTTON1)) 
        {
            flag1 ^= 1;
              togglePINC(LED1);

            if (flag1) {
                LCD_Clear();
                LCD_String(x_1);
            } else {
                LCD_Clear();
                LCD_String(y_1);
            }
            _delay_ms(200);
        }
        else if (isPressedB(BUTTON0)) 
        {
            flag0 ^= 1;
            togglePINC(LED0);

            if (flag0) {
                LCD_Clear();
                LCD_String(x_0);
            } else {
                LCD_Clear();
                LCD_String(y_0);
            }
            _delay_ms(200);
        }
        
    }
}
