#include <Arduino.h>
#include "header.h"

// Pins
const int rgb[] = {0, 6, 5, 3}; 

// LED Intensity
int H1[] = {0, 50, 100, 150, 200, 250};  

int P1 = 10; // Pause
int P2 = 70; // Pause
int P3 = 200; // Pause

int i; // Loop
int a; // outer loop
int b; // color 1
int c; // collor 2

// Button
int d = 7; // pin
int button = 0;
int on = 0;

// Main Function
void setup() 
{
  // starts serial communication and sets the speed to 9600 baud (bits per second)
  Serial.begin(9600);
  //Serial.begin(115200);

  // Output
  Serial.println("MYCROMARS");
  Serial.println("ARDUINO UNO");
  Serial.println("RGB LED");

  // Button
  pinMode( d, INPUT_PULLUP);

  // Activate: Pins 
  pinMode( rgb[1], OUTPUT);
  pinMode( rgb[2], OUTPUT);
  pinMode( rgb[3], OUTPUT);
}

// Step Function
void loop() 
{
  // Function: button
  function_button_1(&d, &button, &on);
  
  // LED: red, green, blue 
  if (on == 1){
    for (a = 1; a < 4; a++)
    {
      // LED ON
      for (i = 1; i <= 5; i++)
      {
        analogWrite( rgb[a], H1[i]);
        delay(P2);
      }

      // Function: button
      function_button_1(&d, &button, &on);
      delay(P3);
      
      // LED OFF
      for (i = 4; i >= 0; i--)
      {
        analogWrite( rgb[a], H1[i]);
        delay(P2);
      }
      delay(P1);
    }
  }
  
  // Function: button
  function_button_1(&d, &button, &on);
  
  // LED: yellow, violet, türkis
  if (on == 1){
    for (a = 1; a < 4; a++)
    {
      // Collor 1
      if (a==1 || a==2) {b = 1;}
      if (a==3) {b = 2;}
      
      // Collor 2
      if (a==1) {c = 2;}
      if (a==2 || a==3) {c = 3;}
      
      // LED ON
      for (i = 1; i <= 5; i++)
      {
        analogWrite( rgb[b], H1[i]);
        analogWrite( rgb[c], H1[i]);
        delay(P2);
      }

      // Function: button
      function_button_1(&d, &button, &on);
      delay(P3);
      
      // LED OFF
      for (i = 4; i >= 0; i--)
      {
        analogWrite( rgb[b], H1[i]);
        analogWrite( rgb[c], H1[i]);
        delay(P2);
      }
      delay(P1);
    }
  }
  
  // Function: button
  function_button_1(&d, &button, &on);

// LED white on
if (on == 1){
  for (i = 1; i <= 5; i++)
  {
    analogWrite( rgb[1], H1[i]);
    analogWrite( rgb[2], H1[i]);
    analogWrite( rgb[3], H1[i]);
    delay(P2);
  }

  // Function: button
  function_button_1(&d, &button, &on);
  delay(P3);
  
  // LED off
  for (i = 4; i >= 0; i--)
  {
    analogWrite( rgb[1], H1[i]);
    analogWrite( rgb[2], H1[i]);
    analogWrite( rgb[3], H1[i]);
    delay(P2);
  }
}

  if (on == 1){
    delay(P1);
  }
  else {
    delay(P3);
  }
}