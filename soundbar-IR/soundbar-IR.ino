/*
Important notes:
* This sketch works for attiny85, compiling for atting45 said that it has not enough space?
* First upload 8MHz boot loader:
Tools → Board → ATtiny85 (8MHz Internal)
Tools → Burn Bootloader

* Your IR led should use pin 0 or 1 as those are PWM.
Connect IR led between I/O pin 1 (physical pin number 6) and GND
No series resistor is required as this is switched using PWM
*/

#include <IRremote.h>
#include <avr/sleep.h>
 
const int irled = 1;   // irled pin on attiny should be PWM pin 0 or 1!!
IRsend irsend(irled);  // Set the GPIO to be used to sending the message.

void setup() {
  // put your setup code here, to run once:
  // we only want to run our task once
  runonce();
}

// my sleep routine that basically turns off the microcontroller and only wakes up on powercycle
void sleepforever()
{
    // not sure if setting the output pin to input pin also doesn't save power (to be investigated)?
    ADCSRA &= ~_BV(ADEN);                   // ADC off (saves power)
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);    // define the sleep mode
    sleep_enable();                         // Sets the Sleep Enable bit in the MCUCR Register (SE BIT)
    cli();                                  // Disable interrupts
    sleep_cpu();                            // Put the microcontroller to sleep
}

void loop() {
  // put your main code here, to run repeatedly:
  //
  // nothing to do here, we want single execution by runonce()
  // 
}

void runonce() {
  // we should wait around 3 sec after power up to send these codes?
  delay(3000);
  // sending POWER toggle IR code
  irsend.sendNEC(0xFFE01F, 32);
  delay(1000);
  // sending MODE toggle IR code
  irsend.sendNEC(0xFFA857, 32);
  delay(1000);
  //sending MODE toggle IR code
  irsend.sendNEC(0xFFA857, 32);
  // go to sleep to save power
  sleepforever();
}
