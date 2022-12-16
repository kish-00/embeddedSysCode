
//Drum machine
// ToneWithoutDelay - demonstrate flash w/o delay using a tone


#include <avr/io.h>
#include "delay.h"
#include "pinMode.h"
#include "sysclock.h"
#include "digitalWrite.h"

// Defaults
#define MAX_FLASHERS 3
#define MAX_BEEPERS 3
#define DEFAULT_ON 100
#define DEFAULT_OFF 100

//flasher
// struct contains the variables required to maintain pin, state and time
struct flasher 
{
   volatile uint8_t pin;    // Uno pin 
   uint8_t state;           // Is pin HIGH or LOW
   uint16_t on;             // Time on
   uint16_t off;            // Time off
   uint16_t elapsed;        // Time elapsed sinced last in loop
} ;

// now setup an array of structs to easily manage them, we can 
// reference each struct by a subscript just like an array
struct flasher flashers[MAX_FLASHERS];

// and initializes the member variables and state, and sets LED pin to OUTPUT
void init_flasher(uint8_t index, uint8_t pin, uint8_t state, uint16_t on, uint16_t off,\
        uint16_t elapsed)
{
    flashers[index].pin = pin;
    flashers[index].state = state;
    flashers[index].on = on;
    flashers[index].off = off;
    flashers[index].elapsed = elapsed;

    pinMode(pin, OUTPUT);
    return ;
}

// update is similar to Classy update in that it checks the time and changes
void update_flasher (uint8_t flasherID) 
{
    // Based on adafruit lesson on classes
    uint16_t now = millis();

    if((flashers[flasherID].state == HIGH) &&\
        (now - flashers[flasherID].elapsed >= flashers[flasherID].on))
    {
        flashers[flasherID].state = LOW;  // Turn it off
        flashers[flasherID].elapsed = now;  // Remember the time
        digitalWrite(flashers[flasherID].pin, LOW);
    }
    else if ((flashers[flasherID].state == LOW) &&\
        (now - flashers[flasherID].elapsed >= flashers[flasherID].off))
    {
        flashers[flasherID].state = HIGH;  // turn it on
        flashers[flasherID].elapsed = now;   // Remember the time
        digitalWrite(flashers[flasherID].pin, HIGH);
    }
    return;
}

//beeper
struct beeper 
{
   volatile uint8_t pin;    // Uno pin 
   uint8_t state;           // Is pin HIGH or LOW
   uint8_t pitch; 
   uint16_t on;             // Time on
   uint16_t off;            // Time off
   uint16_t elapsed;        // Time elapsed sinced last in loop
} ;


struct beeper beepers[MAX_BEEPERS];

// and initializes the member variables and state, and sets LED pin to OUTPUT
void init_beeper(uint8_t index, uint8_t pin, uint8_t pitch, uint8_t state, uint16_t on, uint16_t off,\
        uint16_t elapsed)
{
    beepers[index].pin = pin;
    beepers[index].state = state;
    beepers[index].pitch = pitch;
    beepers[index].on = on;
    beepers[index].off = off;
    beepers[index].elapsed = elapsed;

    pinMode(pin, OUTPUT);
    return ;
}

// update is similar to Classy update in that it checks the time and changes
void update_beeper(uint8_t beeperID) 
{
    // Based on adafruit lesson on classes
    uint16_t now = millis();

    if((beepers[beeperID].state == HIGH) &&\
        (now - beepers[beeperID].elapsed >= beeper[beeperID].on))
    {
        beepers[beeperID].state = LOW;  // Turn it off
        beepers[beeperID].elapsed = now;  // Remember the time
        digitalWrite(beepers[beeperID].pin, LOW);
    }
    else if ((beepers[beeperID].state == LOW) &&\
        (now - beepers[beeperID].elapsed >= beepers[beeperID].off))
    {
        beepers[beeperID].state = HIGH;  // turn it on
        beepers[beeperID].elapsed = now;   // Remember the time
        digitalWrite(beepers[beeperID].pin, HIGH);
    }
    return;
}



int main(void)
{
    init_sysclock_2 ();

    // initialize each flasher (struct: {pin, state, on, off, elapsed})
    // in comparison to Classy example, each LED only requires 1 line of code :)
    // AND update MAX_FLASHERS to number of flashers
    init_flasher(0, 3, LOW, DEFAULT_ON, DEFAULT_OFF, 0);
    init_flasher(1, 5, LOW, DEFAULT_ON << 1, DEFAULT_OFF << 1, 0);
    init_flasher(2, 6, LOW, DEFAULT_ON << 2, DEFAULT_OFF << 2, 0);
    
    init_beeper(0, 3, LOW, 4, DEFAULT_ON, DEFAULT_OFF, 0);
    init_beeper(1, 5, LOW, 6, DEFAULT_ON << 1, DEFAULT_OFF << 1, 0);
    init_beeper(2, 6, LOW, 8, DEFAULT_ON << 2, DEFAULT_OFF << 2, 0);

    // in this case, we simply increment through our array of structs
    while (1)
    {
    for (uint8_t flasher_cntr=0; flasher_cntr < MAX_FLASHERS; ++flasher_cntr)
        {
            update_flasher(flasher_cntr);
            update_beeper(flasher_cntr);
        }
    }
    return 0; 
}

