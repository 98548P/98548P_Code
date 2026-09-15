#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "v5.h"
#include "v5_vcs.h"

#include "robot-config.h"

extern motor leftA;
extern motor leftB;
extern motor rightA;
extern motor rightB;

extern motor_group LeftDrive;
extern motor_group RightDrive;

extern inertial InertialSensor;
extern rotation spinny;

// Drive PID. Not tuned!
extern float drive_kP;
extern float drive_kI;
extern float drive_kD;
//float drive_turn_kP = 0.1;

// Turn PID. Not tuned!
extern float turn_kP;
extern float turn_kI;
extern float turn_kD;

extern double drivePID(float input);

//extern void turnHeadingPID(float targetHeading);

extern double turnPID(float targetHeading);

extern void resetPID();

extern float prevDriveError;
extern float turnPrevError;

