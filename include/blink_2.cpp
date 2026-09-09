#include <Arduino.h>
#include "../include/button_1.h"

void blink_2(const int *PIN_rgb1, 
              const int *LED_intensity1, 
              int a1, int i1,
              int *PIN_b1, int *PIN_c1,
              int P1_1, int P2_1, int P3_1,
              int PIN_a2, int *Button_press2, int *LED_ON2
              )
{
  Serial.println("Blink 2");

  // LED ON: red, green, blue 
  for (int a1 = 1; a1 < 4; a1++)
  {
    // Collor 1
    if (a1==1 || a1==2) {*PIN_b1 = 1;}
    if (a1==3) {*PIN_b1 = 2;}
    
    // Collor 2
    if (a1==1) {*PIN_c1 = 2;}
    if (a1==2 || a1==3) {*PIN_c1 = 3;}

    if (*LED_ON2 == 1)
    {
      // LED ON
      for (i1 = 1; i1 <= 5; i1++)
      {
        // Function: button OFF
        if (*LED_ON2 == 1){button_1(PIN_a2, Button_press2, LED_ON2);}
        if (*LED_ON2 == 0){break;}

        analogWrite( PIN_rgb1[*PIN_b1], LED_intensity1[i1]);
        analogWrite( PIN_rgb1[*PIN_c1], LED_intensity1[i1]);

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

          analogWrite( PIN_rgb1[*PIN_b1], LED_intensity1[i1]);
          analogWrite( PIN_rgb1[*PIN_c1], LED_intensity1[i1]);

        delay(P2_1);
      }
    }
    else if (*LED_ON2 == 0){break;}

    delay(P1_1);
  }
}