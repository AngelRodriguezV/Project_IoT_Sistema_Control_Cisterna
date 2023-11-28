#include <Arduino.h>
#include <NewPing.h>

#define SOUND_VELOCITY 0.034

#define TRIGGER_PIN_1 D1
#define ECHO_PIN_1 D2
#define TRIGGER_PIN_2 D3
#define ECHO_PIN_2 D4

NewPing sonar1(TRIGGER_PIN_1, ECHO_PIN_1, 200);
NewPing sonar2(TRIGGER_PIN_2, ECHO_PIN_2, 200);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(50);

  unsigned int distance1 = sonar1.ping_cm();
  unsigned int distance2 = sonar2.ping_cm();

  Serial.print("Distance Sensor 1: ");
  Serial.print(distance1);
  Serial.print(" cm\t");

  Serial.print("Distance Sensor 2: ");
  Serial.print(distance2);
  Serial.println(" cm");
}