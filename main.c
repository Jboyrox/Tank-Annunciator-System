#include <stdio.h>
#include"header1.h"
int main()
{
  
    int error = 0;
    char state='A';
    setupGPIO();
    while(!error)
    {
        switch (state)
        {
        case 'A': // Green , Flashing Yellow, Flashing Red
        setLED(Green_PIN_17, ON);
        setLED(Yellow_PIN_18, ON);
        setLED(Red_PIN_19, ON);
        delay(DELAY);
        setLED(Yellow_PIN_18, OFF);
        error = setLED(Red_PIN_19, OFF);
        delay(DELAY);
        if(checkBot(TST_PIN_2))// TST switch is not pressed.
            {
                
                state='B';
            }

            
            break;
        case 'B':// Green 
        setLED(Green_PIN_17, ON);
        setLED(Yellow_PIN_18, OFF);
        error = setLED(Red_PIN_19, OFF);
        delay(DELAY);
        if(!checkBot(TST_PIN_2) && checkBot(FLA_PIN_7))// TST_PIN button is pressed and FLA Switch is off.
            {
               
                state='A';
            }
            else if(!checkBot(FLA_PIN_7)) // FLA Switch is on.
            {
                
                state='C';
            }

            
            break;
        case 'C'://Flashing Yellow
        setLED(Green_PIN_17, OFF);
        setLED(Red_PIN_19, OFF);
        setLED(Yellow_PIN_18, ON);
        delay(DELAY);
        error=setLED(Yellow_PIN_18, OFF);
        delay(DELAY);
         if(checkBot(OLA_PIN_8) && checkBot(FLA_PIN_7))// OLA Switch and FLA Switch is turned off.
            {
                
                state='B';
            }
         else if (checkBot(OLA_PIN_8) && !checkBot(FLA_PIN_7) && !checkBot(ACK_PIN_9))// OLA Switch is off, FLA Switch is on and the ACK button is pressed.
         {
            state='D';
         }



            
            break;
        
        
        case 'D'://Yellow
        setLED(Green_PIN_17, OFF);
        setLED(Yellow_PIN_18, ON);
        error = setLED(Red_PIN_19, OFF);
        delay(DELAY);
            if(checkBot(OLA_PIN_8) && checkBot(FLA_PIN_7))// OLA Switch and FLA Switch is turned off.
            {
                
                state='C';
            }
            else if(!checkBot(OLA_PIN_8))//OLA Switch is turned on.
            {
                
                state='E';
            }

            
            break;
        case 'E':// Flashing Red
        setLED(Green_PIN_17, OFF);
        setLED(Yellow_PIN_18, OFF);
        setLED(Red_PIN_19, ON);
        delay(DELAY);
        error = setLED(Red_PIN_19, OFF);
        delay(DELAY);            
        if(!checkBot(ACK_PIN_9)) //ACK button is pressed
            {
                
                state='F';
            }

            
            break;
        case 'F':// Red
        setLED(Green_PIN_17, OFF);
            setLED(Yellow_PIN_18, OFF);
            error = setLED(Red_PIN_19, ON);
            delay(DELAY);            
            if(checkBot(OLA_PIN_8)) // OLA Switch is turned off.
            {
               
                state='D';
            }

            
            break;
        
        default:
            break;
        }
    }
    return 0;
}