#include "vex.h"

float screen = 0;
bool randint = false;
int randomInt = 0;
int seed;

void randSeed() {
  Full_intake.setStopping(coast);
  Full_intake.spin(forward);
  wait(0.5, seconds);
  Full_intake.stop();
  //massive formula gives us numbers
  seed = ((((((Intake.position(deg) + OuttakeMotorB.position(degrees)) - Uptake.position(degrees)) * InertialSensor.heading() + 1) + Drivetrain.rotation()) - (robotX * robotY)) * 1000);
  srand(seed);
}

void enterScreen(float screenNumber) {
  screenNumber = screen;
  if(screenNumber == 0) {
    //main screen
    Brain.Screen.clearScreen();
    drawButton(20,20,175,50,yellow,white,1,"match",3);
    drawButton(20, 93, 175, 50, blue, white, 2,"we supp",3);
    Brain.Screen.setCursor(11, 10);
    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(prop20);
    Brain.Screen.print(defSplash());
  } else if (screenNumber == 1) {
    //match auton selector screen
    Brain.Screen.clearScreen();
    drawButton(1,1,100,100,green, white,0,"sup",5);
    Brain.Screen.setCursor(9, 20);
    Brain.Screen.setFillColor(black);
    Brain.Screen.print(defSplash());
  }
  
  if(screenNumber != screen) {
    enterScreen(screen);
  }
}

void drawButton (int x, int y, int width, int height, color fillColor, color outlineColor, float screenNumber, const char *text, int thickness) {
  Brain.Screen.setFillColor(fillColor);
  Brain.Screen.setPenColor(outlineColor);
  Brain.Screen.setPenWidth(thickness);
  Brain.Screen.drawRectangle(x, y, width, height);
  Brain.Screen.setPenColor(white);
  Brain.Screen.setFont(prop20);
  int textWidth = Brain.Screen.getStringWidth(text);
  int textHeight = Brain.Screen.getStringHeight(text);
  int textX = x + (width / 2) - (textWidth / 2);
  int textY = y + (height /2) + (textHeight / 4);
  Brain.Screen.printAt(textX, textY, text);
  if(Brain.Screen.pressing() == true && Brain.Screen.xPosition() > x && Brain.Screen.yPosition() > y && Brain.Screen.xPosition() < (x + width) && Brain.Screen.yPosition() < (y + height)) {
    waitUntil(Brain.Screen.pressing() == false);
    screen = screenNumber;
  }
}


const char* defSplash() {
  const char* defaultSplash[] = {
    "Also try Minecraft!","Runs on code and bad decisions","CODE333","This side up","Field-Centric feelings","Now with thirty-seven percent more torque!","No keyboard detected, Press F1 to continue","Odom says we're fine","Sponsered by zip ties","Live, Laugh, Localize","Battery low, Confidence high","Rotation sensors my beloved","Precision-ish","Now with emotional stability","Born to intake, forced to defend","Geometry but dangerous","Wheels spinning thoughtfully","Surprisingly reversible","PID and chill","Object permanance enabled","Coded with dramatic intensity","Mildly sentient","Brakes are a mindset","Slightly ahead of schedule","sudo win_elims","ping too high for excuses","Consitently bad","PINNING","Probably within several inches","Do NOT trust the process","Chaos, but organised","I meant to do that","To tired to be mysterious","The cake is a lie","The inner machinations of my mind are an enigma"
  };
  randSeed();
  //if(randint == false) {
    randomInt = rand()%33;
    randint = true;
    wait(randomInt/100, seconds);
    wait(randomInt/100, seconds);
    randomInt = rand()%33;
  //}
  const char* splash = defaultSplash[randomInt];
  return splash;
}

