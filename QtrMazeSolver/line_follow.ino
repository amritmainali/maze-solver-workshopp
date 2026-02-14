void linefollow()
{ 
  paths = 0;
  while ((analogRead(0) < threshold[0] ) && (analogRead(6) < threshold[6])&& (analogRead(3) > threshold[3])) //threshold[6] lai 770
  {
    PID();
  }
  lightsoff();
}
void PID()
{
  int error =  analogRead(2) - analogRead(4) ;//2 * analogRead(1) + analogRead(2) - analogRead(4) - 2 * analogRead(5);

  P = error;
  I = I + error;
  D = error - previousError;

  PIDvalue = (Kp * P) + (Ki * I) + (Kd * D);
  previousError = error;

  lsp = lfspeed - PIDvalue;
  rsp = lfspeed + PIDvalue;

  if (lsp > 200) {
    lsp = 200;
  }
  if (lsp < 0) {
    lsp = 0;
  }
  if (rsp > 200) {
    rsp = 200;
  }
  if (rsp < 0) {
    rsp = 0;
  }

  motor1.drive(lsp);
  motor2.drive(rsp);
}
