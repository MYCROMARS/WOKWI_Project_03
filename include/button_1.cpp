#include <Arduino.h>

void button_1(int PIN_a1, int *Button_press1, int *LED_ON1){
  // LED green
  //digitalWrite(x, HIGH);

  //Serial.println("LED green has Power");

  if (digitalRead(PIN_a1) == LOW)
  {  
    if (*Button_press1 == 0){
      *Button_press1 = 1;
 
      // Switch ON/OFF
      if (*LED_ON1 == 0) {
        *LED_ON1 = 1;
        Serial.println("ON");
      }
      else if (*LED_ON1 == 1)
      {
        *LED_ON1 = 0; 
        Serial.println("OFF");
      }
    }
  }
  else {
    // button free
    *Button_press1 = 0;
  }
}