#include <Arduino.h>

#define SOUND_VELOCITY 0.034

long durationS1;
float distanceCmS1;
long durationS2;
float distanceCmS2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(D0, OUTPUT); // Trig D0
  pinMode(D1, INPUT); // Echo D1
  pinMode(D5, OUTPUT); // Trig D5
  pinMode(D6, INPUT); // Echo D6
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(D0, LOW); 
  digitalWrite(D5, LOW); 
  delayMicroseconds(2);

  digitalWrite(D0, HIGH);
  digitalWrite(D5, HIGH);
  delayMicroseconds(10);
  digitalWrite(D0, LOW);
  digitalWrite(D5, LOW);

  durationS1 = pulseIn(D1, HIGH);
  durationS2 = pulseIn(D6, HIGH);

  distanceCmS1 = durationS1 * SOUND_VELOCITY / 2;
  distanceCmS2 = durationS2 * SOUND_VELOCITY / 2;

  Serial.println("DistanceS1 (cm): ");
  Serial.println(distanceCmS1);
  Serial.println("DistanceS2 (cm): ");
  Serial.println(distanceCmS2);

  delay(1000);
}