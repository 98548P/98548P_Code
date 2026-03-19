#include "vex.h"
  
motor leftA(PORT15, ratio6_1, true);
motor leftB(PORT13, ratio6_1, true);
motor rightA(PORT17, ratio6_1, false);
motor rightB(PORT19, ratio6_1, false);

motor_group LeftDrive(leftA, leftB);
motor_group RightDrive(rightA, rightB);

inertial InertialSensor(PORT7);
rotation spinny(PORT11, false);

float drive_kP = 0.0525;
float drive_kI = 0.007;
float drive_kD = 0.0078;
float drive_turn_kP = 0.8;
   
float turn_kP = 0.42;
float turn_kI = 0.0;
float turn_kD = 0.0075;

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

const float trackingWheelDiameter = 2.0; // inches

float inchesToTrackingDegrees(float inches) {
  float circumference = M_PI * trackingWheelDiameter;
  return (inches / circumference) * 360.0;
}


double drivePID(float input)
{
  float setpoint;
  setpoint = inchesToTrackingDegrees(input);
  float error, prevError, power;
  float integral = 0;
  resetMotors();
  spinny.resetPosition();
  integral = 0;
  prevError = 0;
  float derivative = 6;
  error = 6;

  while (fabs(error) > 1 or fabs(derivative) > 4) {
    error = setpoint - spinny.position(degrees);
    integral += error;
    if (integral > 50) integral = 50;
    if (integral < -50) integral = -50;
    derivative = (error - prevError);
    prevError = error;
    power = error*drive_kP + integral*drive_kI + derivative*drive_kD;
    if (power > 100) power = 100;
    if (power < -100) power = -100;
 
     // Minimum power to prevent stalling
      if (fabs(power) < 2) {
      power = (power > 0) ? 2 : -2;
    }
    LeftDrive.spin(forward, power , percent);
    RightDrive.spin(forward, power , percent);
    wait(15,msec);
  }
  LeftDrive.stop(coast);
  RightDrive.stop(coast);
  return power;
}



double turnPID(float turnAngle) {
  float startHeading = InertialSensor.heading(deg);
  float targetHeading = startHeading + turnAngle;
  float error, prevError, power;
  float integral = 0;
  integral = 0;
  prevError = 0;
  float derivative = 6;
  error = 6;

  if (targetHeading >= 360) targetHeading -= 360;
  if (targetHeading < 0) targetHeading += 360;

  while (fabs(error) > 1 or fabs(derivative) > 2) {
    error = turnError(targetHeading, InertialSensor.heading(degrees));
      integral += error;
    if (integral > 50) integral = 50;
    if (integral < -50) integral = -50;
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
  Drivetrain.stop(coast);
  return power;
}


/*
void turnHeadingPID(float targetHeading) {
  float error, prevError, power;
  float integral = 0;
  integral = 0;
  prevError = 0;
  float derivative = 6;
  error = 6;
  while (fabs(error) > 1 or fabs(derivative) > 2) {
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