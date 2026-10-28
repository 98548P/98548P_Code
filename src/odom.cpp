#include "vex.h"
#include "robot-config.h"

rotation forwardWheel(PORT5, true);
rotation strafeWheel(PORT15, false);

double robotX = 0;
double robotY = 0;
double prevForward = 0;
double prevSide = 0;
double prevHeading = 0;
double robotHeading = 0;

double forwardOffset = 0;  // inches
double sideOffset = 0;     // inches


double wrapAngle(double angle){

  while(angle > M_PI) angle -= 2*M_PI;
  while(angle < -M_PI) angle += 2*M_PI;

  return angle;
}

double degToInches(double deg){
  return (deg / 360.0) * (M_PI * 2.75);
}


void calculateOdometry(){

  // Read sensors
  double forward = degToInches(forwardWheel.position(deg));
  double side = degToInches(strafeWheel.position(deg));
 //double forward = (forwardWheel.position(turns) * 2.75 * M_PI);
// double side = (strafeWheel.position(turns) * 2.75 * M_PI);
  double heading = InertialSensor.rotation(deg) * M_PI / 180.0;
  robotHeading = heading;
  // Calculate deltas
  double dForward = forward - prevForward;
  double dSide = side - prevSide;
  double dHeading = wrapAngle(heading - prevHeading);

  prevForward = forward;
  prevSide = side;
  prevHeading = heading;


  // Remove rotation caused by wheel offsets
  

  double localX;
  double localY;

  
  // ARC MOTION CORRECTION i think
  if(abs(dHeading) <= 0.00001){

      localY = dForward;
      localX = dSide;

  }else{
      /*
      2 * sin(dHeading / 2);
      */
      double sinTerm = 2 * sin(dHeading / 2);
      /*
      sinTerm * (correctedForward / dHeading)
      */
      localX = sinTerm * ((dSide / dHeading) - sideOffset);
/*
sinTerm * (correctedSide / dHeading);
*/
      localY = sinTerm * ((dForward / dHeading) + forwardOffset);
  }
  

  // Rotate to field frame
/*
robotHeading - (dHeading/2);
*/
  double avgHeading = heading - (dHeading/2);

//  double fieldX = localY = (correctedForward / dHeading) * 2 * sin(dHeading / 2);
//  double fieldY = localX = (correctedSide   / dHeading) * 2 * sin(dHeading / 2);
/*
localX * cos(avgHeading) - localY * sin(avgHeading);
*/
  double fieldX = localY * cos(avgHeading) - localX * sin(avgHeading);
  /*
localY * sin(avgHeading) + localX * cos(avgHeading);
*/        
  double fieldY = localY * sin(avgHeading) + localX * cos(avgHeading);
 
  // Update position
  robotX += fieldX;
  robotY += fieldY;
  
}


int startOdom(){

  forwardWheel.resetPosition();
  strafeWheel.resetPosition();
  prevForward = 0;
  prevSide = 0;
  while(1){
    calculateOdometry();
    wait(15,msec);
  }
  return 0;
}

void driveToPoint(double goalX, double goalY, bool reverse) {
  RemoteControlCodeEnabled = false;
  resetPID();
  double headingError;
  while(1){
  double dx = (goalX- robotX);
  double dy = (goalY - robotY);

  double d = sqrt((dx * dx)+ (dy * dy));
  if (reverse == true){
  headingError = wrapAngle(atan2(dy, dx) - (robotHeading + M_PI) );
  } else {
  headingError = wrapAngle(atan2(dy, dx) - robotHeading);
  }

  double headingErrorDeg = headingError * (180 / M_PI);
  double drivePower = drivePID(d);
  double turnPower = turnPID(headingErrorDeg);
  if( (fabs(prevDriveError) < 0.5) && (fabs(turnPrevError) < 0.5) ){
    LeftDrive.stop();
    RightDrive.stop();
    break;
  }

  drivePower = drivePower * cos(headingError);
  if(reverse == true){
    drivePower = -drivePower;
  RightDrive.spin(forward, (drivePower - turnPower), percent);
  LeftDrive.spin(forward, (drivePower + turnPower), percent);
  } else {
  RightDrive.spin(forward, (drivePower - turnPower), percent);
  LeftDrive.spin(forward, (drivePower + turnPower), percent);
  }
  wait(15, msec);
  }
  RemoteControlCodeEnabled = true;
}

/*
void driveToPose(double goalX, double goalY, double goalHeading, bool reverse) {
  */
//}

void lookAtPoint(double goalX, double goalY, bool reverse) {
RemoteControlCodeEnabled = false;
  resetPID();
  double headingError;
  while(1){
  double dx = (goalX - robotX);
  double dy = (goalY - robotY);
  if (reverse == true){
  headingError = wrapAngle(atan2(dy, dx) - (robotHeading + M_PI) );
  } else {
  headingError = wrapAngle(atan2(dy, dx) - robotHeading);
  }
 double headingErrorDeg = headingError * (180 / M_PI);

  double turnPower = turnPID(headingErrorDeg);

  if( (fabs(turnPrevError) < 0.5) ){
    Drivetrain.stop();
    break;
  }


  RightDrive.spin(forward, (turnPower), percent);
  LeftDrive.spin(vex::reverse, (turnPower), percent);

wait(15, msec);
  }
  RemoteControlCodeEnabled = true;
}
