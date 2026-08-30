#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);

int result = 0;
int a = 0;

char buffer[40]; // Speicherplatz für den Text erstellen


void setup() {
  Serial.begin(115200);
  Serial.println("Hello, Arduino");

  pinMode(2, OUTPUT);

  result = myFunction(100, 200);
  //Serial.println(result);


  sprintf(buffer, "Das Ergebnis ist: %d", result);
  Serial.println(buffer);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (a == 0){
    a = 1;
    Serial.println("Hello from Loop");
  }

  digitalWrite(2, HIGH);
  delay(200);
  digitalWrite(2, LOW);
  delay(200);
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}