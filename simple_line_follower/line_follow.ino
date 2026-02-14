void linefollow()
{ 
  // Loop while:
  // Left Sensor (0) is NOT on line (Low)
  // Right Sensor (7) is NOT on line (Low)
  // Center Sensors (3 or 4) ARE on line (High)
  // Using calculated threshold
  
  while ((sensorValues[0] < threshold[0]) && (sensorValues[7] < threshold[7]) && 
         ((sensorValues[3] > threshold[3]) || (sensorValues[4] > threshold[4]))) 
  {
    PID();
    // In simple line follower, if we lose line or hit intersection, loop exits.
    // We should probably just PID forever in a simple follower unless we want to handle turns.
    // But strictly "line follow logic" usually implies PID loop.
    // If it exits, it means we found a node or lost line.
    // For simple follower, we might want to just stop or drive straight?
    // Let's keep it simple: just re-read sensors if loop breaks? 
    // Actually, the main loop calls linefollow() repeatedly.
    // So if it breaks, it goes back to loop() which calls linefollow() again.
    // We update sensors inside PID.
    qtr.readLineWhite(sensorValues);
  }
}

void PID()
{
  uint16_t position = qtr.readLineWhite(sensorValues);
  // Position is 0-7000. Center is 3500.
  
  error = 3500 - position;

  P = error;
  I = I + error;
  D = error - previousError;

  PIDvalue = (Kp * P) + (Ki * I) + (Kd * D);
  previousError = error;

  lsp = lfspeed - PIDvalue;
  rsp = lfspeed + PIDvalue;

  if (lsp > 255) {
    lsp = 255;
  }
  if (lsp < 0) {
    lsp = 0;
  }
  if (rsp > 255) {
    rsp = 255;
  }
  if (rsp < 0) {
    rsp = 0;
  }

  motor1.drive(lsp);
  motor2.drive(rsp);
}
