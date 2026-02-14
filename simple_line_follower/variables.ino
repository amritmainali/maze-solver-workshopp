#include "variables.h"

// Variable Definitions

QTRSensors qtr;
uint16_t sensorValues[NUM_SENSORS];
uint16_t threshold[NUM_SENSORS];

const int offsetA = 1;
const int offsetB = 1;
Motor motor2 = Motor(AIN1, AIN2, PWMA, offsetA, STBY);
Motor motor1 = Motor(BIN1, BIN2, PWMB, offsetB, STBY);

int P = 0;
int D = 0;
int I = 0;
int previousError = 0;
int PIDvalue = 0;
int error = 0;
int lsp = 0;
int rsp = 0;
int lfspeed = 150; 
int turnspeed = 100;
float Kp = 0.06;
float Kd = 1.0;
float Ki = 0;

const int callibrateButton = 11;
const int goButton = 2;
