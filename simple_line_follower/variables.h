#ifndef VARIABLES_H
#define VARIABLES_H

#include <Arduino.h>
#include <QTRSensors.h>
#include <SparkFun_TB6612.h>

// Macros
#define NUM_SENSORS 8
#define IR_PIN 12
#define AIN1 3
#define BIN1 6
#define AIN2 4
#define BIN2 7
#define PWMA 9
#define PWMB 10
#define STBY 5

// Extern Declarations
extern QTRSensors qtr;
extern uint16_t sensorValues[NUM_SENSORS];
extern uint16_t threshold[NUM_SENSORS];

// Motor Control Variables
extern const int offsetA;
extern const int offsetB;
extern Motor motor2;
extern Motor motor1;

// PID Variables
extern int P;
extern int D;
extern int I;
extern int previousError;
extern int PIDvalue;
extern int error;
extern int lsp;
extern int rsp;
extern int lfspeed;
extern int turnspeed;
extern float Kp;
extern float Kd;
extern float Ki;

// Button Pins
extern const int callibrateButton;
extern const int goButton;

#endif
