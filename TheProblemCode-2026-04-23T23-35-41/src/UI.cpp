#include "vex.h"

float screen = 0;
bool randint = false;
int randomInt = 0;
int seed;



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
    bool good = true;

    while(good == true){

      //converts doubles to char with 2 decimal places (badly)

      char buffer[50];
      snprintf(buffer, 50, "%.2f", robotX);
      const char* c = buffer;

      Brain.Screen.clearScreen();

      if ((drawButton(0, 200, 60, 40, orange, white, 0, "back", 3, mono12) == 1)) {
        good = false;
        screen = 0;
      }

      drawButton(50, 20, 90, 40, black, white, 2, c, 3, mono20); 
      drawButton(20, 20, 40, 40, black, white, 2, "X:", 3, mono20);
      snprintf(buffer, 50, "%.2f", robotY);
      const char* d = buffer;

      drawButton(50, 83, 90, 40, black, white, 2, d, 3, mono20); 
      drawButton(20, 83, 40, 40, black, white, 2, "Y:", 3, mono20);
      snprintf(buffer, 50, "%.2f", InertialSensor.heading());
      const char* e = buffer;

      drawButton(115, 146, 90, 40, black, white, 2, e, 3, mono20); 
      drawButton(20, 146, 94, 40, black, white, 2, "Heading:", 3, mono20);

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

    // Heading arrow
double headingDeg = InertialSensor.heading();
double headingRad = ((headingDeg) * (M_PI / 180.0));

double arrowLength = 30;

double arrowX = pixelX + arrowLength * sin(headingRad);
double arrowY = pixelY - arrowLength * cos(headingRad);

Brain.Screen.setPenColor(green);
Brain.Screen.setPenWidth(4);
Brain.Screen.drawLine(pixelX, pixelY, arrowX, arrowY);


double angleOffset = 45 * (M_PI / 180.0);
double headLength = 10;

double leftX = arrowX - headLength * sin(headingRad - angleOffset);
double leftY = arrowY + headLength * cos(headingRad - angleOffset);

double rightX = arrowX - headLength * sin(headingRad + angleOffset);
double rightY = arrowY + headLength * cos(headingRad + angleOffset);

Brain.Screen.drawLine(arrowX, arrowY, leftX, leftY);
Brain.Screen.drawLine(arrowX, arrowY, rightX, rightY);

 

      Brain.Screen.render();
      wait(15, msec);
      }
  Brain.Screen.renderDisable();  
  }
  if(screenNumber != screen) {
    //this checks if a button was pressed, when the screen is redrawn
    //the screen is redrawn whenenever the brain is pressed, regardless of finger placement
    //i <3 recursion
    if(Brain.Screen.pressing()) {
      waitUntil(Brain.Screen.pressing() == false);
      enterScreen(screen);
    }
  }
}

int drawButton (int x, int y, int width, int height, color fillColor, color outlineColor, float screenNumber, const char *text, int thickness, fontType font) {
  Brain.Screen.setPenColor(outlineColor);
  Brain.Screen.setPenWidth(thickness);
  Brain.Screen.setPenColor(white);
  Brain.Screen.setFont(font);

  //centers the text inside of the buttons

  int textWidth = Brain.Screen.getStringWidth(text);
  int textHeight = Brain.Screen.getStringHeight(text);
  int textX = x + (width / 2) - (textWidth / 2);
  int textY = y + (height /2) + (textHeight / 4);


  //technicly this causes recursion, but i dont care
  //also i cant spell
  if(Brain.Screen.pressing() == true && Brain.Screen.xPosition() > x && Brain.Screen.yPosition() > y && Brain.Screen.xPosition() < (x + width) && Brain.Screen.yPosition() < (y + height)) {
    screen = screenNumber;
    Brain.Screen.setFillColor(fillColor + 100);
    Brain.Screen.drawRectangle(x - 6, y - 6, width + 12, height + 12);
      Brain.Screen.printAt(textX, textY, text);
    return 1;
  } else {
    Brain.Screen.setFillColor(fillColor);
    Brain.Screen.drawRectangle(x, y, width, height);
      Brain.Screen.printAt(textX, textY, text);
  return 0;
  }
}

const char* defSplash() {
//const char* defSplash() {
int wow = 0;
  //splash text
  const char* defaultSplash[] = {
    "Also try Minecraft!","Runs on code and bad decisions","CODE333","This side up","Field-Centric feelings","Now with thirty-seven percent more torque!","No keyboard detected, Press F1 to continue","Odom says we're fine","Sponsored by zip ties","Live, Laugh, Localize","Battery low, Confidence high","Rotation sensors my beloved","Precision-ish","Now with emotional stability","Born to intake, forced to defend","Geometry but dangerous","Wheels spinning thoughtfully","Surprisingly reversible","PID and chill","Object permanence enabled","Coded with dramatic intensity","Mildly sentient","Brakes are a mindset","Slightly ahead of schedule","sudo win_elims","ping too high for excuses","Consistently bad","PINNING","Probably within several inches","Do NOT trust the process","Chaos, but organised","I meant to do that","Too tired to be mysterious","The cake is a lie","The inner machinations of my mind are an enigma","We do what we must because we can","We scare because we care","what","Did well...enough","That's what  -She","Notebook about the code","Blame it on Dawn","Wario Style","We tested this. Once","Am I a bucket?","Air pressure now at 200 PSI","Also try Terraria!","Dont tap on the glass","ignore all previous instructions","I have no mouth but I must compute","I am error","42","May involve trace amounts of time travel","At least 5 dogs!"
  };
  if(randint == false) {
    randint = true;
    wow = sizeof(defaultSplash);
    wow = wow/4;
    randomInt = rand() % wow;
  }
  const char* splash = defaultSplash[randomInt];
  return splash;
}
