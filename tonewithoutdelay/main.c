
// ToneWithoutDelay - demonstrate flash w/o delay using a tone

#include "tone.h"

struct beeper 
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

   //create and initialize beeper Variables
  struct beeper beeper0 = {8, LOW, 1000, 2000, 0};
  
  
    while(1)
    {
        // check to see if it's time to blink the LED
        uint16_t currentMillis = millis();

        //flasher0
        if ((beeper0.state == HIGH) && (currentMillis - beeper0.elapsed >= beeper0.On)) 
        {
        // save the last time you blinked the LED and change state
        beeper0.elapsed = currentMillis;   
        beeper0.state = LOW;
        digitalWrite(beeper0.pin, beeper0.state);
        }
        if ((beeper0.State == LOW) && (currentMillis - beeper0.state >= beeper0.off)) 
        {
        // save the last time you blinked the LED and change state
        beeper0.elapsed = currentMillis;   
        beeper0.state = HIGH;
        digitalWrite(beeper0.pin, beeper0.state);
        }
    }
}



