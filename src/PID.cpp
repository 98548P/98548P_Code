#include "vex.h"

motor leftA(PORT6, ratio6_1, false);
motor leftB(PORT4, ratio6_1, false);
motor rightA(PORT10, ratio6_1, true);
motor rightB(PORT9, ratio6_1, true);

motor_group LeftDrive(leftA, leftB);
motor_group RightDrive(rightA, rightB);

inertial InertialSensor(PORT7);

float drive_kP = 0.05;
float drive_kI = 0.00;
float drive_kD = 00;
   
float turn_kP = 0.43;
float turn_kI = 0.005;
float turn_kD = 0.005;

float prevDriveError = 0;
float driveIntegral = 0;
float driveDerivative = 0.0;
float turningError = 0;
float turnIntegral = 0;
float turnDerivative = 0;

void resetMotors() {
  leftA.setPosition(0,degrees);
  leftB.setPosition(0,degrees);
  rightA.setPosition(0,degrees);
  rightB.setPosition(0,degrees);
}

float turnError(float target, float current) {
  float error = target - current;

  while (error > 180) error -= 360;
  while (error < -180) error += 360;

  return error;
}

const float trackingWheelDiameter = 2.75; // inches

float inchesToTrackingDegrees(float inches) {
  float circumference = M_PI * trackingWheelDiameter;
  return (inches / circumference) * 360.0;
}


double drivePID(float input)
{
  float error = input;
  float power;

  driveIntegral += error;

  if (driveIntegral > 50) driveIntegral = 50;
  if (driveIntegral < -50) driveIntegral = -50;

  driveDerivative = (error - prevDriveError);
  prevDriveError = error;

  power = (error*drive_kP) + (driveIntegral*drive_kI) + (driveDerivative*drive_kD);

  if (power > 100) power = 100;
  if (power < -100) power = -100;


  return power;
}



double turnPID(float turnAngle) {
  float power, turnPrevError = 0;
/*
  if (turnAngle >= 360) turnAngle -= 360;
  if (turnAngle < 0) turnAngle += 360;
*/
  turningError = turnAngle;

  turnIntegral += turningError;

  if (turnIntegral > 50) turnIntegral = 50;
  if (turnIntegral < -50) turnIntegral = -50;

  turnDerivative = (turningError - turnPrevError);
  turnPrevError = turningError;

  power = (turningError*turn_kP) + (turnIntegral*turn_kI) + (turnDerivative*turn_kD);

  if (power > 100) power = 100;
  if (power < -100) power = -100;


  return power;
}

void resetPID(){
  prevDriveError = 0;
  driveIntegral = 0;
  turningError = 0;
  turnIntegral = 0;
  driveDerivative = 0;
  driveIntegral = 0;
}

/*
void turnToHeading(float targetHeading) {
  float error, prevError, power;
  float integral = 0;
  integral = 0;
  prevError = 0;
  float derivative = 6;
  error = 6;
  while (fabs(error) > 0.5 or fabs(derivative) > 2) {
    error = turnError(targetHeading, InertialSensor.heading(degrees));
    if (fabs(error) < 20) {
      integral += error;
    } else {
      integral *= 0.9; // Slows down the integral rather than just resseting it 
    }
    if (integral > 300) integral = 300;
    if (integral < -300) integral = -300;
    derivative = (error - prevError);
    prevError = error;
    power = error*turn_kP + integral*turn_kI + derivative*turn_kD;
    if (power > 100) power = 100;
    if (power < -100) power = -100;
    // Minimum power to prevent stalling
    if (fabs(error) > 3 && fabs(power) < 5) {
      power = (power > 0) ? 5 : -5;
    }
    LeftDrive.spin(forward, power, percent);
    RightDrive.spin(reverse, power, percent);
    wait(15,msec);
  }
  Drivetrain.stop(brake);
}
*/