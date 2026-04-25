#include "vex.h"

rotation forwardWheel(PORT16, false);
rotation strafeWheel(PORT11, true);

double robotX = 0;
double robotY = 0;
double prevForward = 0;
double prevSide = 0;
double prevHeading = 0;
double robotHeading = 0;

double forwardOffset = 1.25;  // inches
double sideOffset = 2.9;     // inches


double wrapAngle(double angle){

  while(angle > M_PI) angle -= 2*M_PI;
  while(angle < -M_PI) angle += 2*M_PI;

  return angle;
}

double degToInches(double deg){
  return (deg / 360.0) * (M_PI * 2);
}


void calculateOdometry(){

  // Read sensors
  double forward = degToInches(forwardWheel.position(deg));
  double side = degToInches(strafeWheel.position(deg));
  double heading = InertialSensor.heading(deg) * M_PI / 180.0;

  // Calculate deltas
  double dForward = forward - prevForward;
  double dSide = side - prevSide;
  double dHeading = (heading - prevHeading);

  prevForward = forward;
  prevSide = side;
  prevHeading = heading;

  // Remove rotation caused by wheel offsets
  double correctedForward = dForward - (forwardOffset * dHeading);
  double correctedSide = dSide - (sideOffset * dHeading);

  double localX;
  double localY;

  // ARC MOTION CORRECTION i think
  if(fabs(dHeading) < 0.0001){

      localY = correctedSide;
      localX = correctedForward;

  }else{

      double sinTerm = 2 * sin(dHeading / 2);

      localX = sinTerm * (correctedForward / dHeading);
      localY = sinTerm * (correctedSide / dHeading);
  }

  robotHeading = heading; // keep it rapped

  // Rotate to field frame
  double avgHeading = robotHeading - (dHeading/2);

//  double fieldX = localY = (correctedForward / dHeading) * 2 * sin(dHeading / 2);
//  double fieldY = localX = (correctedSide   / dHeading) * 2 * sin(dHeading / 2);
  
  double fieldX = localX * cos(avgHeading) + localY * sin(avgHeading);
  double fieldY = localY * cos(avgHeading) - localX * sin(avgHeading);
 
  // Update position
  robotX += fieldX;
  robotY += fieldY;
  
  
}


int startOdom(){
  forwardWheel.resetPosition();
  strafeWheel.resetPosition();
  while(1){
    calculateOdometry();
    wait(15,msec);
  }
  return 0;
}

void driveToPoint(double goalX, double goalY, bool reverse) {
  resetPID();
  while(1){
  double dx = (robotX - goalX);
  double dy = (robotY - goalY);

  double d = sqrt((dx * dx)+ (dy * dy));
  double headingError = wrapAngle(atan2(dy, dx) - robotHeading);

  double drivePower = drivePID(d);
  double turnPower = turnPID(headingError);
  if( (fabs(prevDriveError) < 0.5) && (fabs(turnPrevError) < 0.5) ){
    Drivetrain.stop();
    break;
  }

  drivePower = drivePower * cos(headingError);

  RightDrive.spin(forward, (drivePower - turnPower), percent);
  LeftDrive.spin(forward, (drivePower + turnPower), percent);
  }
}

/*
void driveToPose(double goalX, double goalY, double goalHeading, bool reverse) {
  */
//}

void lookAtPoint(double goalX, double goalY, bool reverse) {
  
}
