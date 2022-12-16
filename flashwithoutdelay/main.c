
// FlashWithoutDelay

#include "pinMode.h"
#include "digitalWrite.h"
#include "sysclock.h"

struct flasher 
{
   volatile uint8_t pin;    // Uno pin 
   uint8_t state;           // Is pin HIGH or LOW
   uint16_t on;             // Time on
   uint16_t off;            // Time off
   uint16_t elapsed;        // Time elapsed sinced last in loop
} ;

int main (void)
{
  // Set up a system tick of 1 millisec (1kHz)
  init_sysclock_2 ();
  
  //create and initialize flasher Variables
  struct flasher flasher0 = {10, LOW, 250, 750, 0};
  struct flasher flasher1 = {12, LOW, 150, 150, 0};
  

  // set the digital pin as output:
  pinMode(flasher0.pin, OUTPUT);
  pinMode(flasher1.pin, OUTPUT);

    while(1)
    {
        // check to see if it's time to blink the LED
        uint16_t currentMillis = millis();

        //flasher0
        if ((flasher0.state == HIGH) && (currentMillis - flasher0.elapsed >= flasher0.On)) 
        {
        // save the last time you blinked the LED and change state
        flasher0.elapsed = currentMillis;   
        flasher0.state = LOW;
        digitalWrite(flasher0.pin, flasher0.state);
        }
        if ((flasher0.State == LOW) && (currentMillis - flasher0.state >= flasher0.off)) 
        {
        // save the last time you blinked the LED and change state
        flasher0.elapsed = currentMillis;   
        flasher0.state = HIGH;
        digitalWrite(flasher0.pin, flasher0.state);
        }
        
        //flasher1
        if ((flasher1.state == HIGH) && (currentMillis - flasher1.elapsed >= flasher1.On)) 
        {
        // save the last time you blinked the LED and change state
        flasher1.elapsed = currentMillis;   
        flasher1.state = LOW;
        digitalWrite(flasher1.pin, flasher1.state);
        }
        if ((flasher1.State == LOW) && (currentMillis - flasher1.state >= flasher1.off)) 
        {
        // save the last time you blinked the LED and change state
        flasher1.elapsed = currentMillis;   
        flasher1.state = HIGH;
        digitalWrite(flasher1.pin, flasher1.state);
        }
    }
}


