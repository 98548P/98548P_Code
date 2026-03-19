/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Colson Gibby                                              */
/*    Created:      Wed Jan 28 2026                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Coloring             digital_out   A               
// Blockingle           digital_out   B               
// FlippyDownyThingy    digital_out   C               
// ColorSensor          optical       11              
// Drivetrain           drivetrain    15, 13, 17, 19, 7
// Flap                 digital_out   E               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "odom.h"
#include "Images.h"

using namespace vex;

competition Competition;

// Do NOT touch anything above this line you WILL break something.

////////////////////////////////////////////
//
//
//        2ND ROBOT CONFIGURATION
//
//                                                     
//////////////////////////////////////////// 

bool Goal = true;

motor Intake = motor(PORT9, ratio18_1, false);
motor Uptake = motor(PORT10, ratio18_1, true);
motor OuttakeMotorB = motor(PORT8, ratio6_1, Goal);
motor_group Full_intake = motor_group(Intake, Uptake, OuttakeMotorB);



////////////////////////////////////////////
//
//
//          VARIABLES AND EVENTS
//
//                                                      
////////////////////////////////////////////

int Brain_precision = 0, Console_precision = 0, Controller1_precision = 0;

float myVariable, auton, one;

bool test, cal, blocked, up, team;

//bool control = true;

bool stuck = false;


event message1 = event();
event redleftwin = event();
event redleft5rin = event();
event redrightgoalrush = event();
event redrightwin = event();
event blueleftgoal = event();
event blueleftwin = event();
event bluerightwin = event();
event blurright5ring = event();
event skki = event();

////////////////////////////////////////////
//
//
//             AUTON SELECTOR
//
//                                                      
////////////////////////////////////////////

int whenStarted1() {
  auton = 0.0;
  one = 0.0;
  test = false;
  myVariable = 0.0;
  Brain.Screen.setPenColor(white);
  Brain.Screen.setFillColor(red);
  Brain.Screen.drawRectangle(0, 0, 240, 120);
  Brain.Screen.setFillColor(blue);
  Brain.Screen.drawRectangle(239, 119, 240, 120);
  Brain.Screen.setFillColor(green);
  Brain.Screen.drawRectangle(239, 0, 240, 120);
  Brain.Screen.setFillColor(yellow);
  Brain.Screen.drawRectangle(0, 119, 240, 120);
  Brain.Screen.setCursor(2, 3);
  Brain.Screen.setFillColor(red);
  Brain.Screen.setPenColor(black);
  Brain.Screen.setFont(mono40);
  Brain.Screen.print("Options");
  Brain.Screen.setCursor(2, 16);
  Brain.Screen.setFillColor(green);
  Brain.Screen.print("Skills");
  Brain.Screen.setCursor(5, 16);
  Brain.Screen.setFillColor(blue);
  Brain.Screen.print("Match");
  Brain.Screen.setCursor(5, 5);
  Brain.Screen.setFillColor(yellow);
  Brain.Screen.print("Test");
  ColorSensor.setLight(ledState::on);
  ColorSensor.setLightPower(67,percent);
  while (1) {
    if (team == false) {
      if (ColorSensor.hue() <= 20) { //Red Hue Maximum
        Coloring.set(true);
      }
      else {
        Coloring.set(false);
      }
    }
    else {
      if (ColorSensor.hue() >= 200) { //Blue Hue Minimum
        Coloring.set(true);
      }
      else {
        Coloring.set(false);
      }
    }
    wait(40,msec);
  }
}




void onevent_Brain_screen_pressed_0() {
  if (myVariable == 0.0) {
    if ((Brain.Screen.yPosition() < 239.0 && Brain.Screen.xPosition() > 239.0) && (Brain.Screen.yPosition() > 119.0 && Brain.Screen.xPosition() < 479.0)) {
      Brain.Screen.clearScreen();
      wait(0.3, seconds);
      Brain.Screen.setFillColor(red);
      Brain.Screen.drawRectangle(0, 0, 240, 120);
      Brain.Screen.setFillColor(blue);
      Brain.Screen.drawRectangle(239, 119, 240, 120);
      Brain.Screen.setFillColor(red);
      Brain.Screen.drawRectangle(239, 0, 240, 120);
      Brain.Screen.setFillColor(blue);
      Brain.Screen.drawRectangle(0, 119, 240, 120);
      Brain.Screen.setCursor(2, 5);
      Brain.Screen.setFillColor(red);
      Brain.Screen.setPenColor(black);
      Brain.Screen.setFont(mono40);
      Brain.Screen.print("Left");
      Brain.Screen.setCursor(2, 16);
      Brain.Screen.setFillColor(red);
      Brain.Screen.print("Right");
      Brain.Screen.setCursor(5, 16);
      Brain.Screen.setFillColor(blue);
      Brain.Screen.print("Right");
      Brain.Screen.setCursor(5, 5);
      Brain.Screen.setFillColor(blue);
      Brain.Screen.print("Left");
      myVariable = 1.0;
    } else if ((Brain.Screen.yPosition() < 119.0 && Brain.Screen.xPosition() > 239.0) && (Brain.Screen.yPosition() > 0.0 && Brain.Screen.xPosition() < 479.0)) {
      Brain.Screen.clearScreen();
      if (test) {
        wait(3,seconds);
        skki.broadcast();
      }
      else {
        auton = 1.0;
      }
    } else if ((Brain.Screen.yPosition() < 119.0 && Brain.Screen.xPosition() > 0.0) && (Brain.Screen.yPosition() > 0.0 && Brain.Screen.xPosition() < 239.0)) {
        myVariable = 67;
        Controller1.rumble("-.-.");
        //DrivetrainInertial.calibrate();
        Brain.Screen.clearScreen();
        wait(0.3,seconds);

  Brain.Screen.clearScreen();


  Brain.Screen.setCursor(1, 1); 

  while(myVariable == 67){
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1); 
   Brain.Screen.print(robotX); 
    Brain.Screen.setCursor(2, 1);
   Brain.Screen.print(robotY); 
  int gridSize = 6;
  int squareSize = 35;

  int startX = 235;
  int startY = 15;

  for(int row = 0; row < gridSize; row++) {

    for(int col = 0; col < gridSize; col++) {

      int x = startX + col * squareSize;
      int y = startY + row * squareSize;
      Brain.Screen.setFillColor(black);
      Brain.Screen.drawRectangle(x, y, squareSize, squareSize);

    }

  }
   // convert robot position
double pixelX = (squareSize * (gridSize/2)) + (startX + (robotX / 24) * squareSize);
double pixelY = startY + (squareSize * (gridSize/2)) - (robotY / 24) * squareSize;

// draw robot
Brain.Screen.setFillColor(red);
Brain.Screen.drawCircle(pixelX, pixelY, 5);

  Brain.Screen.render();
   wait(15, msec);
  }
      
      
      
      //Controller1.rumble("-.-.");
      //DrivetrainInertial.calibrate();
    } else if ((Brain.Screen.yPosition() < 239.0 && Brain.Screen.xPosition() > 0.0) && (Brain.Screen.yPosition() > 119.0 && Brain.Screen.xPosition() < 239.0)) {
      Controller1.rumble("..-.");

      test = true;
    } else {

    }
  } else if (myVariable == 1.0) {
    if ((Brain.Screen.yPosition() < 239.0 && Brain.Screen.xPosition() > 239.0) && (Brain.Screen.yPosition() > 119.0 && Brain.Screen.xPosition() < 479.0)) {
      Brain.Screen.clearScreen();
      wait(0.3, seconds);
      Brain.Screen.setPenColor(white);
      Brain.Screen.setFillColor(red);
      Brain.Screen.drawRectangle(0, 0, 239, 239);
      Brain.Screen.setFillColor(blue);
      Brain.Screen.drawRectangle(239, 0, 240, 239);
      Brain.Screen.setCursor(5, 3);
      Brain.Screen.setFillColor(red);
      Brain.Screen.print("Winpoint");
      Brain.Screen.setCursor(5, 16);
      Brain.Screen.setFillColor(blue);
      Brain.Screen.print("win");
      one = 1.0;
      myVariable = 2.0;
    } else if ((Brain.Screen.yPosition() < 119.0 && Brain.Screen.xPosition() > 239.0) && (Brain.Screen.yPosition() > 0.0 && Brain.Screen.xPosition() < 479.0)) {
      Brain.Screen.clearScreen();
      wait(0.3, seconds);
      Brain.Screen.setPenColor(white);
      Brain.Screen.setFillColor(red);
      Brain.Screen.drawRectangle(0, 0, 239, 239);
      Brain.Screen.setFillColor(blue);
      Brain.Screen.drawRectangle(239, 0, 240, 239);
      Brain.Screen.setCursor(5, 3);
      Brain.Screen.setFillColor(red);
      Brain.Screen.print("Winpoint");
      Brain.Screen.setCursor(5, 15);
      Brain.Screen.setFillColor(blue);
      Brain.Screen.print("win");
      one = 2.0;
      myVariable = 2.0;
    } else if ((Brain.Screen.yPosition() < 119.0 && Brain.Screen.xPosition() > 0.0) && (Brain.Screen.yPosition() > 0.0 && Brain.Screen.xPosition() < 239.0)) {
      Brain.Screen.clearScreen();
      wait(0.3, seconds);
      Brain.Screen.setPenColor(white);
      Brain.Screen.setFillColor(red);
      Brain.Screen.drawRectangle(0, 0, 239, 239);
      Brain.Screen.setFillColor(blue);
      Brain.Screen.drawRectangle(239, 0, 240, 239);
      Brain.Screen.setCursor(5, 3);
      Brain.Screen.setFillColor(red);
      Brain.Screen.print("Winpoint");
      Brain.Screen.setCursor(5, 16);
      Brain.Screen.setFillColor(blue);
      Brain.Screen.print("win");
      one = 3.0;
      myVariable = 2.0;
    } else if ((Brain.Screen.yPosition() < 239.0 && Brain.Screen.xPosition() > 0.0) && (Brain.Screen.yPosition() > 119.0 && Brain.Screen.xPosition() < 239.0)) {
      Brain.Screen.clearScreen();
      wait(0.3, seconds);
      Brain.Screen.setPenColor(white);
      Brain.Screen.setFillColor(red);
      Brain.Screen.drawRectangle(0, 0, 239, 239);
      Brain.Screen.setFillColor(blue);
      Brain.Screen.drawRectangle(239, 0, 240, 239);
      Brain.Screen.setCursor(5, 3);
      Brain.Screen.setFillColor(red);
      Brain.Screen.print("Winpoint");
      Brain.Screen.setCursor(5, 15);
      Brain.Screen.setFillColor(blue);
      Brain.Screen.print("win");
      one = 4.0;
      myVariable = 2.0;
    } else {
    }
  } else if (myVariable == 2.0) {
    if ((Brain.Screen.yPosition() < 239.0 && Brain.Screen.xPosition() > 0.0) && (Brain.Screen.yPosition() > 0.0 && Brain.Screen.xPosition() < 239.0)) {
      Brain.Screen.clearScreen();
      if (one == 1.0) {
        if (test) {
          wait(3.0, seconds);
          bluerightwin.broadcast();
          team = false;
          drawLogo();
        }
        else {
          auton = 6.0;
          team = false;
          drawLogo();
        }
      } else if (one == 2.0) {
        if (test) {
          wait(3.0, seconds);
          redrightwin.broadcast();
          team = true;
          drawLogo();
        }
        else {
          auton = 7.0;
          team = true;
           drawLogo();
        }
      } else if (one == 3.0) {
        if (test) {
          wait(3.0, seconds);
          redleftwin.broadcast();
          team = true;
          drawLogo();
        }
        else {
          auton = 8.0;
          team = true;
          drawLogo();
        }
      } else if (one == 4.0) {
        if (test) {
          wait(3.0, seconds);
          blueleftwin.broadcast();
          team = false;
          drawLogo();
        }
        else {
          auton = 9.0;
          team = false;
          drawLogo();
        }
      } else {
      }
    } else if ((Brain.Screen.yPosition() < 239.0 && Brain.Screen.xPosition() > 239.0) && (Brain.Screen.yPosition() > 0.0 && Brain.Screen.xPosition() < 479.0)) {
      Brain.Screen.clearScreen();
      if (one == 1.0) {
        if (test) {
          wait(3.0, seconds);
          blurright5ring.broadcast();
          team = false;
          drawLogo();
        }
        else {
          auton = 2.0;
          team = false;
          drawLogo();
        }
      } else if (one == 2.0) {
        if (test) {
          wait(3.0, seconds);
          redrightgoalrush.broadcast();
          team = true;
          drawLogo();
        }
        else {
          auton = 3.0;
          team = true;
          drawLogo();
        }
      } else if (one == 3.0) {
        if (test) {
          wait(3.0, seconds);
          redleft5rin.broadcast();
          team = true;
          drawLogo();
        }
        else {
          auton = 4.0;
          team = true;
          drawLogo();
        }
      } else if (one == 4.0) {
        if (test) {
          wait(3.0, seconds);
          blueleftgoal.broadcast();
          team = false;
          drawLogo();
        }
        else {
          auton = 5.0;
          team = false;
          drawLogo();
        }
      } else {
      }
    } else {
    }
  } else {
  }
}


int onauton_autonomous_0() {
  if (auton == 1.0) {
    skki.broadcast();
  } else if (auton == 2.0) {
    blurright5ring.broadcast();
  } else if (auton == 3.0) {
    redrightgoalrush.broadcast();
  } else if (auton == 4.0) {
    redleft5rin.broadcast();
  } else if (auton == 5.0) {
    blueleftgoal.broadcast();
  } else if (auton == 6.0) {

    bluerightwin.broadcast();
  } else if (auton == 7.0) {
    redrightwin.broadcast();
  } else {
    if (auton == 8.0) {
      redleftwin.broadcast();
    } else if (auton == 9.0) {
      blueleftwin.broadcast();
    } else {
    }
  }
  return 0;
}

////////////////////////////////////////////
//
//
//                 AUTONS
//
//                                                      
////////////////////////////////////////////

void clearLoaders() {
  wait(0.4,seconds);
  Drivetrain.driveFor(forward,2,inches);
  wait(0.4,seconds);
  Drivetrain.driveFor(reverse,2,inches);
  wait(0.4,seconds);
  Drivetrain.driveFor(forward,2,inches);
  wait(0.4,seconds);
  Drivetrain.driveFor(reverse,2,inches);
  wait(0.4,seconds);
  Drivetrain.driveFor(forward,2,inches);
  wait(0.4,seconds);
  Drivetrain.driveFor(reverse,2,inches);
  wait(0.4,seconds);
  Drivetrain.driveFor(forward,2,inches);
  wait(0.4,seconds);
  Drivetrain.driveFor(reverse,2,inches);
  wait(0.4,seconds);
  Drivetrain.driveFor(forward,3,inches);
  wait(0.4,seconds);
  Drivetrain.driveFor(reverse,2,inches);
  wait(0.4,seconds);
  Drivetrain.driveFor(forward,2,inches);
  wait(0.4,seconds);
  Drivetrain.driveFor(reverse,2,inches);
}

void onevent_blueleftgoal_0() {

}


void onevent_blueleftwin_0() {
  Drivetrain.setDriveVelocity(90,percent);
  OuttakeMotorB.setVelocity(74,percent);
  drivePID(18);
  turnPID(-45);
  drivePID(6);
  turnPID(45);
  drivePID(7);
  Full_intake.spin(forward);
  OuttakeMotorB.stop(hold);
  FlippyDownyThingy.set(true);
  drivePID(10);
  turnPID(-135);
  drivePID(-14);
  OuttakeMotorB.spin(reverse);
  OuttakeMotorB.setBrake(brake);
  //wait(2,sec);
  //drivePID(48);
  //turnPID(-44.5);
  //drivePID(15);
}


void onevent_bluerightwin_0() {
  drivePID(18);
  turnPID(45);
  drivePID(6);
  turnPID(-45);
  drivePID(6);
  Full_intake.spin(forward);
  OuttakeMotorB.stop(hold);
  FlippyDownyThingy.set(true);
  drivePID(14);
  wait(1, sec);
  turnPID(-45);
  FlippyDownyThingy.set(false);
  drivePID(11);
  Full_intake.stop();
  Full_intake.spin(reverse);
  OuttakeMotorB.stop();
}


void onevent_blurright5ring_0() {
 Drivetrain.driveFor(forward,10,inches);
}


void onevent_redleft5rin_0() {
}

void onevent_redleftwin_0() {
  Drivetrain.setDriveVelocity(90,percent);
  OuttakeMotorB.setVelocity(74,percent);
  drivePID(18);
  turnPID(-45);
  drivePID(6);
  turnPID(45);
  drivePID(7);
  Full_intake.spin(forward);
  OuttakeMotorB.stop(hold);
  FlippyDownyThingy.set(true);
  drivePID(10);
  turnPID(-135);
  drivePID(-14);
  OuttakeMotorB.spin(reverse);
  OuttakeMotorB.setBrake(brake);
  //wait(2,sec);
  //drivePID(48);
  //turnPID(-44.5);
  //drivePID(15);

  
}


void onevent_redrightgoalrush_0() {
  Full_intake.spin(forward);
}


void onevent_redrightwin_0() {
  drivePID(18);
  turnPID(45);
  drivePID(6);
  turnPID(-45);
  drivePID(6);
  Full_intake.spin(forward);
  OuttakeMotorB.stop(hold);
  FlippyDownyThingy.set(true);
  drivePID(14);
  wait(1, sec);
  turnPID(-45);
  FlippyDownyThingy.set(false);
  drivePID(11);
  Full_intake.stop();
  Full_intake.spin(reverse);
  OuttakeMotorB.stop();
}


void onevent_skki_0() {
/*
  drivePID(30);
  FlippyDownyThingy.set(true);
  turnPID(-90);
  Full_intake.spin(forward);
  drivePID(4.5);
  clearLoaders();
  turnHeadingPID(180);
  drivePID(-10);
  turnPID(45);
  FlippyDownyThingy.set(false);
  drivePID(-20);
  turnPID(135);
  drivePID(60);
  turnPID(-45);
  drivePID(20);
  FlippyDownyThingy.set(true);
  turnPID(45);
  drivePID(12);
  clearLoaders();
  turnHeadingPID(0);
  */

//drivePID(-18);
Drivetrain.setDriveVelocity(100,percent);
Drivetrain.driveFor(forward, 40, inches);
 // Drivetrain.driveFor(reverse,25,inches);
  
  
  //ippitsyuppity.set(true);

  /*
  Blockingleblock.set(true);
  Drivetrain.setDriveVelocity(20,percent);
  Drivetrain.setTurnVelocity(3.5,percent);
  Drivetrain.driveFor(forward,24,inches);
  Drivetrain.turnFor(left,50,degrees);
  Full_intake.spin(forward);
  Drivetrain.setDriveVelocity(20,percent);
  Drivetrain.driveFor(forward,25,inches);
  Drivetrain.turnFor(left,26,degrees);
  Drivetrain.driveFor(forward,18,inches);
  Full_intake.spin(reverse);
  Drivetrain.driveFor(reverse,3,inches);
  wait(5,seconds);
  Drivetrain.driveFor(reverse,50,inches);
  Drivetrain.turnFor(left,180,degrees);
  Drivetrain.turnFor(right,34,degrees);
  FlippyDownyThingy.set(true);
  Drivetrain.driveFor(forward,20,inches);
  */
}


////////////////////////////////////////////
//
//
//             CONTROLLER INPUT
//
//                                                      
////////////////////////////////////////////

void onevent_Controller1ButtonY_pressed_0() {
  if(test == true){
    turnPID(-90);
  }
}

void onevent_Controller1ButtonX_pressed_0() {

}


void onevent_Controller1ButtonR2_pressed_0() {

}


void onevent_Controller1ButtonR1_pressed_0() {

}


void onevent_Controller1ButtonR2_released_0() {

}



void Flip() {
  if(up){
    FlippyDownyThingy.set(false);
    up = !up;
  }
  else {
    FlippyDownyThingy.set(true);
    up = !up;
  }
}



void controllerinput() {
      while(1) {
       if (Controller1.ButtonR1.pressing()) {
          Intake.spin(forward);
          Uptake.spin(forward);
          stuck = false;
          OuttakeMotorB.setStopping(hold);
        } else if (Controller1.ButtonR2.pressing()) {
         Full_intake.spin(reverse);
         stuck = false;
        } else if (Controller1.ButtonL1.pressing()) {
          if (stuck){
            Goal = false;
            stuck = false;
            motor OuttakeMotorB = motor(PORT8, ratio6_1, Goal);
            Full_intake.spin(reverse);
            wait(0.6,seconds);
            Full_intake.stop();
          }
          Goal = true;
          motor OuttakeMotorB = motor(PORT8, ratio6_1, Goal);
          Full_intake.spin(forward);
        } else if(Controller1.ButtonL2.pressing()){
          Goal = false;
          stuck = false;
          motor OuttakeMotorB = motor(PORT8, ratio6_1, Goal);
          Full_intake.spin(forward);
        } else {
         Full_intake.stop();
         OuttakeMotorB.setStopping(coast);
        }
    wait(20, msec);
  }
}




void whenStarted2(){
  ColorSensor.setLight(ledState::on);
  ColorSensor.setLightPower(100,percent);
  while (1) {
    if (team == false) {
      if (ColorSensor.hue() <= 20) { //Red Hue Maximum
      //  control = false;
      //  OuttakeMotorB.stop();
      //  OuttakeMotorB.spin(reverse);
       // wait(1,seconds);
       // control = true;
      }
      else {

      }
    }
    else {
      if (ColorSensor.hue() >= 200) { //Blue Hue Minimum
       // control = false;
       // OuttakeMotorB.stop();
      //  OuttakeMotorB.spin(reverse);
       // wait(1,seconds);
       // control = true;
      }
      else {

      }
    }
    wait(15,msec);
  }
}

void Top_Goal(){
  Goal = true;
  motor OuttakeMotorB = motor(PORT8, ratio6_1, Goal);
}

void Middle_Goal(){
  Goal = false;
  motor OuttakeMotorB = motor(PORT8, ratio6_1, Goal);
}

void pid(){
  if(test == true) {
     drivePID(40);
  } else {
     if(cal){
    cal = !cal;
    Flap.set(true);
  }else {
    cal = !cal;
    Flap.set(false);
  }
  
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
  blueleftgoal(onevent_blueleftgoal_0);
  blueleftwin(onevent_blueleftwin_0);
  bluerightwin(onevent_bluerightwin_0);
  blurright5ring(onevent_blurright5ring_0);
  redleft5rin(onevent_redleft5rin_0);
  redleftwin(onevent_redleftwin_0);
  redrightgoalrush(onevent_redrightgoalrush_0);
  redrightwin(onevent_redrightwin_0);
  Intake.setVelocity(100,percent);
  Uptake.setVelocity(100,percent);
  OuttakeMotorB.setVelocity(100,percent);
  skki(onevent_skki_0);
  Controller1.ButtonA.pressed(Flip);
  Drivetrain.setDriveVelocity(90,percent);
  Controller1.ButtonR1.pressed(controllerinput);
  Controller1.ButtonUp.pressed(Top_Goal);
  Controller1.ButtonDown.pressed(Middle_Goal);
  Controller1.ButtonX.pressed(pid);
  Controller1.ButtonY.pressed(onevent_Controller1ButtonY_pressed_0);
  task startObom = task(startOdom);
  whenStarted1();
}