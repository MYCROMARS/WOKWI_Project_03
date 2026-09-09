
void function_button_1(int x, int *y, int *z){
  // LED green
  //digitalWrite(x, HIGH);

  //Serial.println("LED green has Power");

  if (digitalRead(x) == LOW)
  {  
    if (*y == 0){
      *y = 1;
 
      // Switch ON/OFF
      if (*z == 0) {
        *z = 1;
        Serial.println("ON");
      }
      else if (*z == 1)
      {
        *z = 0; 
        Serial.println("OFF");
      }
    }
  }
  else {
    // button free
    *y = 0;
  }
}