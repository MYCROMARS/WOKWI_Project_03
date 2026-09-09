#include <Arduino.h>
#include "../include/function_button_1.h"

void blink_1(const int *PIN_rgb1, 
              const int *LED_intensity1, 
              int a1, int i1,
              int *PIN_b1, int *PIN_c1,
              int P1_1, int P2_1, int P3_1,
              int PIN_a1, int *Button_press1, int *LED_ON1
              )
{
  Serial.println("HELLO WORLD");

  // LED ON: red, green, blue 
  for (int a1 = 1; a1 < 4; a1++)
  {
    if (*LED_ON1 == 1)
    {
      // LED ON
      for (i1 = 1; i1 <= 5; i1++)
      {
        // Function: button
        function_button_1(PIN_a1, Button_press1, LED_ON1);

        analogWrite( PIN_rgb1[a1], LED_intensity1[i1]);

        delay(P2_1);
      }

      // Function: button
      function_button_1(PIN_a1, Button_press1, LED_ON1);

      delay(P3_1);

      // LED OFF
      for (i1 = 4; i1 >= 0; i1--)
      {
        // Function: button
        function_button_1(PIN_a1, Button_press1, LED_ON1);

        analogWrite( PIN_rgb1[a1], LED_intensity1[i1]);

        delay(P2_1);
    
      delay(P1_1);
      }
    }
  }
}