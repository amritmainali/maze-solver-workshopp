void botleft ()
{
  motor1.drive(-1 * turnspeed);
  motor2.drive(turnspeed);
  delay(150);
  
  // Wait until Center sensor sees line
  qtr.readLineWhite(sensorValues);
  // While Center (3 or 4) < threshold (White/Background)
  while ((sensorValues[3] < threshold[3]) && (sensorValues[4] < threshold[4]))
  {
    qtr.readLineWhite(sensorValues);
    motor1.drive(-1 * turnspeed);
    motor2.drive(turnspeed);
  }
  motor1.drive(0);
  motor2.drive(0);
  delay(50);
}

void botright ()
{
  motor1.drive(turnspeed);
  motor2.drive(-1 * turnspeed);
  delay(150);
  
  qtr.readLineWhite(sensorValues);
  while ((sensorValues[3] < threshold[3]) && (sensorValues[4] < threshold[4]))
  {
    qtr.readLineWhite(sensorValues);
    motor1.drive(turnspeed);
    motor2.drive(-1 * turnspeed);
  }
  motor1.drive(0);
  motor2.drive(0);
  delay(50);
}

void botstraight ()
{
  motor1.drive(lfspeed);
  motor2.drive(lfspeed);
}

void botinchforward ()
{
  motor1.drive(turnspeed);
  motor2.drive(turnspeed);
  delay(10);
}
void botstop ()
{
  motor1.drive(0);
  motor2.drive(0);
}
void botuturn ()
{
  digitalWrite(13, HIGH);   //debugging
  motor2.drive(-1 * turnspeed);
  motor1.drive(turnspeed);
  delay(300);
  
  qtr.readLineWhite(sensorValues);
  while ((sensorValues[3] < threshold[3]) && (sensorValues[4] < threshold[4]))
  {
    qtr.readLineWhite(sensorValues);
    motor2.drive(-1 * turnspeed);
    motor1.drive(turnspeed);
  }
  motor1.drive(0);
  motor2.drive(0);
  delay(50);
}
