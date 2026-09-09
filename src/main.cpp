
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
  // starts serial communication and sets the speed to 9600 baud (bits per second)
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
  // Function: button
  function_button_1(PIN_a, &Button_press, &LED_ON);
  
  if (LED_ON == 1)
  {
    blink_1(PIN_rgb, LED_intensity, a, i, &PIN_b, &PIN_c, P1, P2, P3, PIN_a, &Button_press, &LED_ON);
    /*
    // LED ON: red, green, blue 
    for (a = 1; a < 4; a++)
    {
      // LED ON
      for (i = 1; i <= 5; i++)
      {
        analogWrite( rgb[a], H1[i]);

        delay(P2);

        // Function: button
        function_button_1(&d, &button, &on);

        if (on == 0)
        {break;}
      }

      // Function: button
      function_button_1(&d, &button, &on);

      delay(P3);

      // Function: button
      function_button_1(&d, &button, &on);
      
      // LED OFF
      for (i = 4; i >= 0; i--)
      {
        analogWrite( rgb[a], H1[i]);

        delay(P2);

        // Function: button
        function_button_1(&d, &button, &on);
      }

      if (on == 0)
        {break;}

      delay(P1);
    }
      */
  
    // Function: button
    function_button_1(PIN_a, &Button_press, &LED_ON);
    
    if (LED_ON == 1)
    {
      // LED ON: yellow, violet, türkis
      for (a = 1; a < 4; a++)
      {
        // Collor 1
        if (a==1 || a==2) {PIN_b = 1;}
        if (a==3) {PIN_b = 2;}
        
        // Collor 2
        if (a==1) {PIN_c = 2;}
        if (a==2 || a==3) {PIN_c = 3;}
        
        // LED ON
        for (i = 1; i <= 5; i++)
        {
          analogWrite( PIN_rgb[PIN_b], LED_intensity[i]);
          analogWrite( PIN_rgb[PIN_c], LED_intensity[i]);

          delay(P2);

          // Function: button
          function_button_1(PIN_a, &Button_press, &LED_ON);

          if (LED_ON == 0)
          {break;}
        }

        // Function: button
        function_button_1(PIN_a, &Button_press, &LED_ON);

        delay(P3);

        // Function: button
        function_button_1(PIN_a, &Button_press, &LED_ON);
        
        // LED OFF
        for (i = 4; i >= 0; i--)
        {
          analogWrite(PIN_rgb[PIN_b], LED_intensity[i]);
          analogWrite(PIN_rgb[PIN_c], LED_intensity[i]);

          delay(P2);

          // Function: button
          function_button_1(PIN_a, &Button_press, &LED_ON);
        }

        if (LED_ON == 0)
        {break;}

        delay(P1);
      }
    }
    
    // Function: button
    function_button_1(PIN_a, &Button_press, &LED_ON);

    if (LED_ON == 1)
    {
      // LED ON: white
      for (i = 1; i <= 5; i++)
      {
        analogWrite(PIN_rgb[1], LED_intensity[i]);
        analogWrite(PIN_rgb[2], LED_intensity[i]);
        analogWrite(PIN_rgb[3], LED_intensity[i]);

        delay(P2);

        // Function: button
        function_button_1(PIN_a, &Button_press, &LED_ON);

        if (LED_ON == 0)
        {break;}
      }

      // Function: button
      function_button_1(PIN_a, &Button_press, &LED_ON);

      delay(P3);

      // Function: button
      function_button_1(PIN_a, &Button_press, &LED_ON);
    
      // LED off
      for (i = 4; i >= 0; i--)
      {
        analogWrite(PIN_rgb[1], LED_intensity[i]);
        analogWrite(PIN_rgb[2], LED_intensity[i]);
        analogWrite(PIN_rgb[3], LED_intensity[i]);

        delay(P2);

        // Function: button
        function_button_1(PIN_a, &Button_press, &LED_ON);
      }
    }

    delay(P3);
  }
  else{
    delay(P1);
  }
}
// END