/************************************************************************
 * This program was written for use with the TinyLily Mini Processor and
 * TinyLily LEDs. The sketch will fade an LED attached to pin 3 for a few 
 * seconds, and then pin A4 will be used to blink the LED(s) attached to 
 * it for a few seconds.
 * 
 * Program Written by: Laveréna Wienclaw for TinyCircuits
 * Initiated: 7-30-2019
 * Last updated: 7-30-2019
 ************************************************************************/

#define fadePin 3   // PWM pin used for fading - Only pin 3
#define blinkPin A4 // pin used for blinking - can use any pin on the TinyLily processor

int brightness = 0;
int fadeAmount = 5; // can be used to change the brighntess increment in fadeLED()
int counter = 0;    // Used in loop() to cycle between fading and blinking LEDs

void setup() {
  pinMode(fadePin, OUTPUT);
  pinMode(blinkPin, OUTPUT);
}

void loop() {
  if(counter <= 500)
  {
    fadeLED();
  }
  else
  {
    blinkLED();
    if(counter > 520)
    {
      counter = 0;
    }
  }
  counter++;
}

// Fades an LED between on and off 
void fadeLED() {
  analogWrite(fadePin, brightness); // Set the brightness of the fade pin
  brightness += fadeAmount; // Change brightness during each function call 

  // Reverse fading direction
  if(brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }

  delay(15); // Can increase to make fading last longer, or vice versa 
}

// Toggles an LED on and off 
void blinkLED() {
  digitalWrite(blinkPin, HIGH);
  delay(100);
  digitalWrite(blinkPin, LOW);
  delay(100);
}
