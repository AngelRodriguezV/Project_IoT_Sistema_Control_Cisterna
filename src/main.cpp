#include <Arduino.h>

#define SOUND_VELOCITY 0.034

long duration;
float distanceCm;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(D1, OUTPUT);
  pinMode(D0, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(D1, LOW);
  delayMicroseconds(2);

  digitalWrite(D1, HIGH);
  delayMicroseconds(10);
  digitalWrite(D1, LOW);

  duration = pulseIn(D0, HIGH);

  distanceCm = duration * SOUND_VELOCITY / 2;

  Serial.println("Distance (cm): ");
  Serial.println(distanceCm);

  delay(1000);
}
