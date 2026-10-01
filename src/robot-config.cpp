#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor leftMotorA = motor(PORT9, ratio6_1, false);
motor leftMotorB = motor(PORT10, ratio6_1, false);
motor_group LeftDriveSmart = motor_group(leftMotorA, leftMotorB);
motor rightMotorA = motor(PORT2, ratio6_1, true);
motor rightMotorB = motor(PORT4, ratio6_1, true);
motor_group RightDriveSmart = motor_group(rightMotorA, rightMotorB);
inertial DrivetrainInertial = inertial(PORT1);
smartdrive Drivetrain = smartdrive(LeftDriveSmart, RightDriveSmart, DrivetrainInertial, 319.19, 320, 40, mm, 1);
motor OUT = motor(PORT20, ratio6_1, true);
motor IN = motor(PORT19, ratio18_1, false);
motor_group OUTIN = motor_group(OUT, IN);
motor Cascade1 = motor(PORT18, ratio36_1, true);
motor Cascade2 = motor(PORT11, ratio36_1, false);
motor_group Cascade = motor_group(Cascade1, Cascade2);
motor Grabber = motor(PORT7, ratio18_1, true);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;


void vexcodeInit( void ) {
  task RemoteControl (Controlle);

 
  Brain.Screen.drawImageFromFile("98548logobrain.png", 0, 0);
  //while (DrivetrainInertial.isCalibrating()) {
 //   wait(25, msec);
 // }
  DrivetrainInertial.calibrate();
  wait(50, msec);
}

int Controlle() {

  while(1) {

    if(testAuton){
    char buffer[100];
    drawButton(0, 0, 480, 272, black, white, 3, "", 0, prop60, false);
 snprintf(buffer, 100, "%.4f",Cascade.position(deg) );
  const char* P = buffer;

  int textWidth = Brain.Screen.getStringWidth(P);
  int textHeight = Brain.Screen.getStringHeight(P);
  int textX = (480 / 2) - (textWidth / 2);
  int textY = (272 /2) + (textHeight / 4);
  Brain.Screen.printAt(textX, textY, P);
    }

      if(abs(Controller1.Axis2.position()) < 5) {
        LeftDriveSmart.stop();
      } else {
        LeftDriveSmart.spin(forward,Controller1.Axis2.position(),percent);
      }

      if(abs(Controller1.Axis3.position()) < 5) {
        RightDriveSmart.stop();
      } else {
        RightDriveSmart.spin(forward,Controller1.Axis3.position(),percent);;
      }

      if(Controller1.ButtonR1.pressing()) {
        OUTIN.spin(forward);
      } else if(Controller1.ButtonR2.pressing()) {
        OUTIN.spin(reverse);
      } else {
        OUTIN.stop();
      }

      if(Controller1.ButtonL1.pressing()) {
        if(Cascade.position(deg) <= 1555) {
          Cascade.spin(forward);
        } else {
          Cascade.stop(hold);
        }
      } else if(Controller1.ButtonL2.pressing()) {
        if(Cascade.position(deg) >= 10) {
          Cascade.spin(reverse);
        } else {
          Cascade.stop(hold);
        }
      } else {
        Cascade.stop(hold);
      }
      wait(20, msec);
  }
}

