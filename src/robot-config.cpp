#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor leftMotorA = motor(PORT8, ratio6_1, false);
motor leftMotorB = motor(PORT10, ratio6_1, false);
motor_group LeftDriveSmart = motor_group(leftMotorA, leftMotorB);
motor rightMotorA = motor(PORT19, ratio6_1, true);
motor rightMotorB = motor(PORT20, ratio6_1, true);
motor_group RightDriveSmart = motor_group(rightMotorA, rightMotorB);
inertial DrivetrainInertial = inertial(PORT1);
smartdrive Drivetrain = smartdrive(LeftDriveSmart, RightDriveSmart, DrivetrainInertial, 319.19, 320, 40, mm, 1);
motor OUT = motor(PORT19, ratio6_1, false);
motor IN = motor(PORT20, ratio18_1, true);
motor_group OUTIN = motor_group(OUT, IN);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;


void vexcodeInit( void ) {
  task RemoteControl (Controlle);

 // DrivetrainInertial.calibrate();
  Brain.Screen.drawImageFromFile("98548logobrain.png", 0, 0);
  //while (DrivetrainInertial.isCalibrating()) {
 //   wait(25, msec);
 // }
  wait(50, msec);
}

int Controlle() {

  while(1) {


      if(fabs(Controller1.Axis3.position()) < 5) {
        LeftDriveSmart.stop();
      } else {
        LeftDriveSmart.spin(forward,Controller1.Axis3.position(),percent);
      }

      if(fabs(Controller1.Axis2.position()) < 5) {
        RightDriveSmart.stop();
      } else {
        RightDriveSmart.spin(forward,Controller1.Axis2.position(),percent);;
      }

      if(Controller1.ButtonR1.pressing()) {
        OUTIN.spin(forward);
      } else if(Controller1.ButtonR2.pressing()) {
        OUTIN.spin(reverse);
      } else {
        OUTIN.stop();
      }
      wait(20, msec);
  }
}

