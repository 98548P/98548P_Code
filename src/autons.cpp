#include "vex.h"
#include "robot-config.h"
using namespace vex;

float autonNumber;

int testAuton = 0;

void SkillAuton () {

  Drivetrain.setDriveVelocity(100,percent);
  /*
  
  Drivetrain.drive(forward);
  wait(0.4,seconds);
  OUTIN.stop();
  Drivetrain.turnFor(330,degrees);
  Drivetrain.stop();
  for (size_t i = 0; i < 2; i++) {
    Drivetrain.drive(forward);
    wait(2,seconds);
    Drivetrain.stop();
    Drivetrain.drive(reverse);
    wait(0.2,seconds);
    Drivetrain.stop();
  }
  */
  Drivetrain.drive(forward);
  wait(0.8,sec);
  Drivetrain.stop();
}

void BlueLeft1 () {
  Pin_claw.set(true);
Pin_grabber.set(true);
  Drivetrain.setStopping(brake);
  Drivetrain.setDriveVelocity(100,percent);
  Brain.Screen.clearScreen();
  Brain.resetTimer();
  leftMotorA.spin(forward);
  wait (0.4, sec);
  leftMotorA.stop();
  Drivetrain.turnFor(330,degrees);
  Drivetrain.stop();
  for (int i = 0; i < 2; i++) {
    Drivetrain.drive(forward);
    wait(2,seconds);
    Drivetrain.stop();
    Drivetrain.drive(reverse);
    wait(0.2,seconds);
    Drivetrain.stop();
  }
  Drivetrain.drive(reverse);
  wait(0.4,seconds);
  Drivetrain.stop();
}

void BlueLeft2 () {
  Pin_grabber.set(true);
  driveToPoint(0,24,false);
  Pin_lifter.set(true);
 // Cascade.spinTo(2.2,rev);
  driveToPoint(24,24,false);
  Pin_grabber.set(false);
}

void BlueCenter1 () {

}

void BlueCenter2 () {

}

void RedCenter1 () {
  driveToPoint(0,24,true);

}

void RedCenter2 () {
  driveToPoint(0,24,false);
}

void RedRight1 () {
  setPos(0,-63,0);


}

void RedRight2 () {
driveToPoint(0,-24,false);
}

float runAuton() {
  RemoteControlCodeEnabled = false;
  if ( autonNumber == 4 ) {
    SkillAuton();
  } else if ( autonNumber == 10101 ) {
    BlueLeft1();
  } else if ( autonNumber == 10102 ) {
    BlueLeft2();
  } else if ( autonNumber == 10201) {
    BlueCenter1();
  } else if ( autonNumber == 10202) {
    BlueCenter2();
  } else if ( autonNumber == 10301) {
    RedCenter1();
  } else if ( autonNumber == 10302 ) {
    RedCenter2();
  } else if ( autonNumber == 10401 ) {
    RedRight1();
  } else if ( autonNumber == 10402) {
    RedRight2();
  }
  RemoteControlCodeEnabled = true;
  return 0;
}