void calibrate() {
  for (int i = 0; i < 7; i++) {
    minValues[i] = analogRead(i);
    maxValues[i] = analogRead(i);
  }

  for (int i = 0; i < 1500; i++) {
    motor1.drive(50);
    motor2.drive(-50);

    for (int i = 0; i < 7; i++) {
      if (analogRead(i) < minValues[i]) {
        minValues[i] = analogRead(i);
      }
      if (analogRead(i) > maxValues[i]) {
        maxValues[i] = analogRead(i);
      }
    }
  }
  for (int i = 0; i < 3000; i++) {
    motor1.drive(50);
    motor2.drive(-50);

    for (int i = 0; i < 7; i++) {
      if (analogRead(i) < minValues[i]) {
        minValues[i] = analogRead(i);
      }
      if (analogRead(i) > maxValues[i]) {
        maxValues[i] = analogRead(i);
      }
    }
  }

  for (int i = 0; i < 7; i++) {
    threshold[i] =( (minValues[i] + maxValues[i]) / 2) + sensorThreshold;
    Serial.print(threshold[i]);
    Serial.print("   ");
  }
  Serial.println();

  threshold[6] =800 ; //temporary test

  motor1.drive(0);
  motor2.drive(0);
}