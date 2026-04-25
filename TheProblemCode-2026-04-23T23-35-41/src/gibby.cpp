#include "vex.h"
#include "strings.h"

float screen = 0;
bool randint = false;
int randomInt = 0;
int seed;

void randSeed() {
  Uptake.setStopping(coast);
  Uptake.spin(forward);
  wait(0.5, seconds);
  Uptake.stop();
  wait(0.5,seconds);
  //massive formula gives us numbers
  seed = ((((((Intake.position(deg) + OuttakeMotorB.position(degrees)) - Uptake.position(degrees)) * InertialSensor.heading() + 1) + Drivetrain.rotation()) - (robotX * robotY)) * 1000);
  srand(seed);
}

void enterScreen(float screenNumber) {
  screen = screenNumber;
  if(screenNumber == 0) {
    //main screen
    Brain.Screen.clearScreen();
    drawButton(20,20,175,50,yellow,white,1,"Match",3,prop20);
    drawButton(20, 93, 175, 50, red, white, 2,"Odometry",3,prop20);
    Brain.Screen.setCursor(11, 3);
    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(prop20);
    Brain.Screen.print(defSplash());
  } else if (screenNumber == 1) {
    //match auton selector screen
    Brain.Screen.clearScreen();
    drawButton(1,1,100,100,green, white,0,"button",5,prop20);
    Brain.Screen.setCursor(9, 20);
    Brain.Screen.setFillColor(black);
    Brain.Screen.print(defSplash());
  } else if (screenNumber == 2) {
    //odom screen
      while(screenNumber == 2){
        char buffer[50];
        snprintf(buffer, 50, "%.2f", robotX);
        const char* c = buffer;
    Brain.Screen.clearScreen();
    drawButton(20, 20, 90, 40, blue, white, 2, c, 3,prop10); 
    snprintf(buffer, 50, "%.2f", robotY);
    const char* d = buffer;
    drawButton(20, 83, 90, 40, blue, white, 2, d, 3,prop10); 
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
Brain.Screen.drawCircle(pixelX, pixelY, 10);
Brain.Screen.render();
wait(15, msec);
      }
  }
  
  if(screenNumber != screen) {
    enterScreen(screen);
  }
}

void drawButton (int x, int y, int width, int height, color fillColor, color outlineColor, float screenNumber, const char *text, int thickness, const char *font) {
  Brain.Screen.setFillColor(fillColor);
  Brain.Screen.setPenColor(outlineColor);
  Brain.Screen.setPenWidth(thickness);
  Brain.Screen.drawRectangle(x, y, width, height);
  Brain.Screen.setPenColor(white);
  Brain.Screen.setFont(font);
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
    "Also try Minecraft!","Runs on code and bad decisions","CODE333","This side up","Field-Centric feelings","Now with thirty-seven percent more torque!","No keyboard detected, Press F1 to continue","Odom says we're fine","Sponsored by zip ties","Live, Laugh, Localize","Battery low, Confidence high","Rotation sensors my beloved","Precision-ish","Now with emotional stability","Born to intake, forced to defend","Geometry but dangerous","Wheels spinning thoughtfully","Surprisingly reversible","PID and chill","Object permanence enabled","Coded with dramatic intensity","Mildly sentient","Brakes are a mindset","Slightly ahead of schedule","sudo win_elims","ping too high for excuses","Consistently bad","PINNING","Probably within several inches","Do NOT trust the process","Chaos, but organised","I meant to do that","Too tired to be mysterious","The cake is a lie","The inner machinations of my mind are an enigma","We do what we must because we can","We scare because we care","what","You may have a very minor case of serious brain damage","So im glad i got burned think of all the things we learned","Notebook about the code","Blame it on Dawn","Wario Style","We tested this. Once"
  };
  if(randint == false) {
    randSeed();
    randint = true;
   // randomInt = rand()%44;
    randomInt = rand() % ((sizeof(defaultSplash)) / (sizeof(defaultSplash[0])));
  }
  const char* splash = defaultSplash[randomInt];
  return splash;
}

