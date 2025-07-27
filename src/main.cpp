#include <Arduino.h>

#include "Ultrasonic.h"

#define lightPin 6
#define buttonPin 2
#define echoPin 4
#define sensitivityPin A2
#define speakerPin 5

#define speakerValue 128

Ultrasonic ultrasonic(echoPin);

bool active = false;

void initGpio();
void toggleActive();

void setup() {
  Serial.begin(9600);
  initGpio();
}

void loop() {
  if (active) {
    int distance = ultrasonic.MeasureInCentimeters();
    int sensitivity = analogRead(sensitivityPin) / 2;
    Serial.print("Distance: ");
    Serial.println(distance);
    Serial.print("Sensitivity: ");
    Serial.println(sensitivity);
    
    if (sensitivity > distance) {
      analogWrite(speakerPin, speakerValue);
    } else {
      analogWrite(speakerPin, 0);
    }

    if (digitalRead(buttonPin) == HIGH) {
      toggleActive();
    }
  }
  
  if (!active && digitalRead(buttonPin) == HIGH) {
    toggleActive();
  }
}

void initGpio() {
  pinMode(lightPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(echoPin, INPUT);
  pinMode(sensitivityPin, INPUT);
  pinMode(speakerPin, OUTPUT);
}

void toggleActive() {
  active = !active;
  digitalWrite(lightPin, active ? HIGH : LOW);
  analogWrite(speakerPin, 0);
  Serial.println(active ? "Active" : "Inactive");
  while (true) {
    if (digitalRead(buttonPin) == LOW) {
      break;
    }
  }
}
