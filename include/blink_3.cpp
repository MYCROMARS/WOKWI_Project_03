#include <Arduino.h>
#include "../include/button_1.h"

void blink_3(const int *PIN_rgb1, 
              const int *LED_intensity1, 
              int a1, int i1,
              int *PIN_b1, int *PIN_c1,
              int P1_1, int P2_1, int P3_1,
              int PIN_a2, int *Button_press2, int *LED_ON2
              )
{
  Serial.println("Blink 3");

    if (*LED_ON2 == 1)
    {
      // LED ON: White
      for (i1 = 1; i1 <= 5; i1++)
      {
        // Function: button OFF
        if (*LED_ON2 == 1){button_1(PIN_a2, Button_press2, LED_ON2);}
        if (*LED_ON2 == 0){break;}

        analogWrite( PIN_rgb1[1], LED_intensity1[i1]);
        analogWrite( PIN_rgb1[2], LED_intensity1[i1]);
        analogWrite( PIN_rgb1[3], LED_intensity1[i1]);

        delay(P2_1);
      }

      // Function: button
      if (*LED_ON2 == 1){button_1(PIN_a2, Button_press2, LED_ON2);}

      delay(P3_1);

      // LED OFF
      for (i1 = 4; i1 >= 0; i1--)
      {
        // Function: button
        if (*LED_ON2 == 1){button_1(PIN_a2, Button_press2, LED_ON2);}

          analogWrite( PIN_rgb1[1], LED_intensity1[i1]);
          analogWrite( PIN_rgb1[2], LED_intensity1[i1]);
          analogWrite( PIN_rgb1[3], LED_intensity1[i1]);

        delay(P2_1);
      }
    }
}