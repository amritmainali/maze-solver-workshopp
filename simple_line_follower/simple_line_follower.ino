#include "variables.h"

void setup() {
  Serial.begin(9600);

  // IR control pin
  pinMode(IR_PIN, OUTPUT);
  digitalWrite(IR_PIN, HIGH);   // Turn IR LEDs ON

  pinMode(callibrateButton, INPUT_PULLUP);
  pinMode(goButton, INPUT_PULLUP);
  
  // LED Pins
  pinMode(8, OUTPUT); 
  pinMode(13, OUTPUT);

  qtr.setTypeAnalog();
  qtr.setSensorPins((const uint8_t[]){
    A0, A1, A2, A3, A4, A5, A6, A7
  }, NUM_SENSORS);

  delay(1000);
  Serial.println("Press Calibrate Button to start calibration...");
}

void loop() {
  // Wait for Calibrate Button
  while (digitalRead(callibrateButton) == HIGH) {}
  delay(500);
  
  Serial.println("Calibrating...");
  // Calibrate
  for (int i = 0; i < 200; i++) {
    qtr.calibrate();
    delay(10);
  }
  calculateThresholds();
  Serial.println("Calibration Done!");

  // Wait for Go Button
  while (digitalRead(goButton) == HIGH) {}
  delay(500);
  Serial.println("Go!");

  // Simple Line Follow Loop
  while (1) {
    linefollow();
  }
}
