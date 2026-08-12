#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Drivetrain           drivetrain    1, 2, 3, 4, 5   
// ---- END VEXCODE CONFIGURED DEVICES ----
#include "odom.h"
#include "Images.h"
#include "UI.h"
#include "functions.h"

using namespace vex;

competition Competition;

////////////////////////////////////////////
//
//
//        MORE ROBOT CONFIGURATION
//
//                                                     
//////////////////////////////////////////// 

bool Goal = true;

motor Intake = motor(PORT9, ratio18_1, false);
motor Uptake = motor(PORT10, ratio18_1, true);
motor OuttakeMotorB = motor(PORT8, ratio6_1, Goal);
motor_group Full_intake = motor_group(Intake, Uptake, OuttakeMotorB);


int Brain_precision = 0, Console_precision = 0, Controller1_precision = 0;


////////////////////////////////////////////
//
//
//             AUTON SELECTOR
//
//                                                      
////////////////////////////////////////////


void onevent_Brain_screen_pressed_0() {
  enterScreen(screen);
}


int onauton_autonomous_0() {
  return 0;
}



////////////////////////////////////////////
//
//
//             CONTROLLER INPUT
//
//                                                      
////////////////////////////////////////////

void onevent_Controller1ButtonY_pressed_0() {

}

void onevent_Controller1ButtonX_pressed_0() {

}


void onevent_Controller1ButtonR2_pressed_0() {

}


void onevent_Controller1ButtonR1_pressed_0() {

}


void onevent_Controller1ButtonR2_released_0() {

}

void onevent_Controller1ButtonA_pressed_0() {
  if(screen == 303){
    driveToPoint(0, 40, false);
  } else {
    
  }
}

void onevent_Controller1ButtonB_pressed_0() {
  if(screen == 303){
    lookAtPoint(0, 0, false);
  } else {

  }
}

////////////////////////////////////////////
//
//
//           MATCH CONFIGURATION
//
//                                                      
////////////////////////////////////////////


void VEXcode_driver_task() {
  // Start the driver control tasks....




  while(Competition.isDriverControl() && Competition.isEnabled()) {this_thread::sleep_for(10);}

  return;
}

void VEXcode_auton_task() {
  // Start the auton control tasks....

  vex::task auto0(onauton_autonomous_0);
  runAuton();
  while(Competition.isAutonomous() && Competition.isEnabled()) {this_thread::sleep_for(10);}
  auto0.stop();
  return;
}
 

int main() {
  vex::competition::bStopTasksBetweenModes = false;
  
  Competition.autonomous(VEXcode_auton_task);
  Competition.drivercontrol(VEXcode_driver_task);

  wait(15, msec);
  
  Full_intake.setVelocity(200, rpm);

      

  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // register event handlers
  Brain.Screen.pressed(onevent_Brain_screen_pressed_0);
  Intake.setVelocity(100,percent);
  Uptake.setVelocity(100,percent);
  OuttakeMotorB.setVelocity(100,percent);
  Controller1.ButtonA.pressed(onevent_Controller1ButtonA_pressed_0);
  Controller1.ButtonB.pressed(onevent_Controller1ButtonB_pressed_0);
  //Drivetrain.setDriveVelocity();
  //Controller1.ButtonR1.pressed();
  //Controller1.ButtonUp.pressed();
  //Controller1.ButtonDown.pressed();
  //Controller1.ButtonX.pressed();
  Controller1.ButtonY.pressed(onevent_Controller1ButtonY_pressed_0);
  randSeed();
  task startObom = task(startOdom);
  enterScreen(0);
}