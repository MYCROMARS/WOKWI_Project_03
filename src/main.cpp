#include <Arduino.h>
#include "header.h"

// Create & assign *************************************
const int P1 = 10; // Pause
const int P2 = 70; // Pause
const int P3 = 200; // Pause

int a; // outer loop
int i; // inner Loop

// Pin Input: Button 
const int PIN_a = 7; // pin

int Button_press = 0;
int LED_ON = 0;

// Pin Output: LED
int PIN_b; // color 1
int PIN_c; // collor 2

// Pins
const int PIN_rgb[] = {0, 6, 5, 3}; 

// LED Intensity
const int LED_intensity[] = {0, 50, 100, 150, 200, 250};  


// Main Function ***************************************
void setup() 
{
  // start serial communication and sets the speed to 9600 baud (bits per second)
  Serial.begin(9600);
  //Serial.begin(115200);

  // Output
  Serial.println("MYCROMARS");
  Serial.println("ARDUINO UNO");
  Serial.println("RGB LED");

  // Button
  pinMode( PIN_a, INPUT_PULLUP);

  // Activate: Pins 
  pinMode( PIN_rgb[1], OUTPUT);
  pinMode( PIN_rgb[2], OUTPUT);
  pinMode( PIN_rgb[3], OUTPUT);
}

// Step Function ***************************************
void loop() 
{
  // Function: button ON/OFF
  button_1(PIN_a, &Button_press, &LED_ON);
  
  // Blink 1
  if (LED_ON == 1)
  {
    // Function: Blink 1
    blink_1(PIN_rgb, LED_intensity, a, i, &PIN_b, &PIN_c, P1, P2, P3, PIN_a, &Button_press, &LED_ON);
  }

  // Function: button OFF
  if (LED_ON == 1){button_1(PIN_a, &Button_press, &LED_ON);}
    
  
  // Blink 2
  if (LED_ON == 1)
  {
    // Function: Blink 2
    blink_2(PIN_rgb, LED_intensity, a, i, &PIN_b, &PIN_c, P1, P2, P3, PIN_a, &Button_press, &LED_ON);
  }

  // Function: button OFF
  if (LED_ON == 1){button_1(PIN_a, &Button_press, &LED_ON);}


  // Blink 3
  if (LED_ON == 1)
  {
    // Function: Blink 3
    blink_3(PIN_rgb, LED_intensity, a, i, &PIN_b, &PIN_c, P1, P2, P3, PIN_a, &Button_press, &LED_ON);
  }
  
  // Delay
  if (LED_ON == 1){
    delay(P3);
  }
  else{
    delay(P1);
  }
  
}
// END