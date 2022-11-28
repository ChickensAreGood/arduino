#include "DHT.h"
#define Type DHT11
int sensePin = 2;
DHT HT(sensePin, Type);
float humidity;
float tempC;
float tempF;
const int buzzer = 9;

void setup() {
  Serial.begin(9600);
  HT.begin();
  pinMode(buzzer, OUTPUT);
}

void loop() {
  int temp = HT.readTemperature();
  Serial.println(temp);
  if (!(temp > 37 && temp < 46)) {
    tone(buzzer, 1000);
    delay(1000);
    noTone(buzzer);
    delay(1000);

  }
}
