/*
  Simple blink for attiny

  Turns a LED on for one second, then off for one second, repeatedly.

  Hardware:
  * Connect your attiny to an arduino which is setup as ISP
  * Connect an LED to pin 3 (= gpio4) and GND with a 330 ohm series resistor
  This pin should not be used by the programmer so you can attach it while it's on the programmer board

  For programming Attiny25/45/85 using arduino as ISP:
  Arduino IDE settings:
  Tools → Board → Attiny25/45/85 (no bootloader)
  Tools → Chip → select either attiny25 or 45 or 85
  Tools → Programmer → Arduino as ISP

  For some purposes (like IR) it's important that you 
  First upload 8MHz boot loader:
  Tools → Clock Source (only set on bootload) → 8MHz (Internal)
  Tools → Burn Bootloader

  Upload your code by choosing:
  Sketch -> Upload using programmer
*/

int ledpin = 4;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin ledpin as an output.
  pinMode(ledpin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(ledpin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                   // wait for a second
  digitalWrite(ledpin, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                   // wait for a second
}
