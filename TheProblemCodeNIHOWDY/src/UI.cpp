#include "vex.h"
#include "autons.h"


float screen = 0;
bool randint = false;
int randomInt = 0;
int seed, prevScreen;



void enterScreen(float screenNumber) {
  screen = screenNumber;

  if(screenNumber == 0) {

    //main screen

    Brain.Screen.drawImageFromFile("grad1.png", 0, 0);
    drawButton(20,20,175,50,yellow,white,1,"Match",3,prop20,true);
    drawButton(20, 93, 175, 50, red, white, 2,"Odometry",3,prop20,true);
    drawButton(230, 20, 175, 50, green, white, 4, "Settings", 3, prop20, true);
    Brain.Screen.setCursor(11, 3);
    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(prop20);
    Brain.Screen.printAt(20, 200, false, defSplash());
   // Brain.Screen.print(defSplash());
  
  } else if (screenNumber == 1) {

    //match auton selector screen

    
    //drawing buttons on feild for auton selection
    drawButton(83, 5, 75, 75, black,black ,102,"", 0, prop20,true);
    drawButton(44, 5, 39, 39, black,black ,102,"", 0, prop20,true);
    drawButton(158, 5, 39, 39, black,black ,102,"", 0, prop20,true);
  
    drawButton(6, 82, 75, 75, black,black ,101,"", 0, prop20,true);
    drawButton(6, 43, 39, 39, black,black ,101,"", 0, prop20,true);
    drawButton(6, 156, 39, 39, black,black ,101,"", 0, prop20,true);

    drawButton(160, 82, 75, 75, black,black ,104,"", 0, prop20,true);
    drawButton(196, 43, 39, 39, black,black ,104,"", 0, prop20,true);
    drawButton(196, 156, 39, 39, black,black ,104,"", 0, prop20,true);

    drawButton(83, 159, 75, 75, black,black ,103,"", 0, prop20,true);
    drawButton(44, 195, 39, 39, black,black ,103,"", 0, prop20,true);
    drawButton(158, 195, 39, 39, black,black ,103,"", 0, prop20,true);

   Brain.Screen.drawImageFromFile("Field.png.png", 0, 0);
  drawButton(238, 0, 242, 60, black,white ,1,"No Auton Selected", 1, prop30,false);
  drawButton(238, 59, 242, 60, black,white ,1,"No Auton Selected", 1, prop30,false);  
prevScreen = 1;
  autonNumber = 4;
    drawButton(238, 118, 242, 60, black,white ,301,"Skills", 1, prop30,true);
  

  drawButton(238, 177, 242, 60, black,white ,0,"Back", 1, prop30,true);
  } else if (screenNumber == 101) {
  //match screen blue left
    
    drawButton(83, 5, 75, 75, black,black ,102,"", 0, prop20,true);
    drawButton(44, 5, 39, 39, black,black ,102,"", 0, prop20,true);
    drawButton(158, 5, 39, 39, black,black ,102,"", 0, prop20,true);


    drawButton(160, 82, 75, 75, black,black ,104,"", 0, prop20,true);
    drawButton(196, 43, 39, 39, black,black ,104,"", 0, prop20,true);
    drawButton(196, 156, 39, 39, black,black ,104,"", 0, prop20,true);

    drawButton(83, 159, 75, 75, black,black ,103,"", 0, prop20,true);
    drawButton(44, 195, 39, 39, black,black ,103,"", 0, prop20,true);
    drawButton(158, 195, 39, 39, black,black ,103,"", 0, prop20,true);
    Brain.Screen.drawImageFromFile("Field.png.png", 0, 0);
  drawButton(238, 0, 242, 60, black,white ,10101,"Blue Left 1", 1, prop30,true);
  drawButton(238, 59, 242, 60, black,white ,10102,"Blue Left 2", 1, prop30,true);

  prevScreen = 101;
 autonNumber = 4;
    drawButton(238, 118, 242, 60, black,white ,301,"Skills", 1, prop30,true);
  

  drawButton(238, 177, 242, 60, black,white ,1,"Back", 1, prop30,true);
} else if (screenNumber == 10101) {
  //match screen blue left Selected 1
    
    Brain.Screen.drawImageFromFile("Field.png.png", 0, 0);
  drawButton(238, 0, 242, 60, green,white ,10101,"Blue Left 1", 1, prop30,false);
  drawButton(238, 59, 242, 60, black,white ,10102,"Blue Left 2", 1, prop30,true);
  prevScreen = 10101;

    drawButton(238, 118, 242, 60, black,white ,301,"Select", 1, prop30,true);
  
  drawButton(238, 177, 242, 60, black,white ,1,"Back", 1, prop30,true);
  autonNumber = 10101;
} else if (screenNumber == 10102) {
  //match screen blue left Selected 2
  
    drawButton(83, 5, 75, 75, black,black ,102,"", 0, prop20,true);
    drawButton(44, 5, 39, 39, black,black ,102,"", 0, prop20,true);
    drawButton(158, 5, 39, 39, black,black ,102,"", 0, prop20,true);

    drawButton(160, 82, 75, 75, black,black ,104,"", 0, prop20,true);
    drawButton(196, 43, 39, 39, black,black ,104,"", 0, prop20,true);
    drawButton(196, 156, 39, 39, black,black ,104,"", 0, prop20,true);

    drawButton(83, 159, 75, 75, black,black ,103,"", 0, prop20,true);
    drawButton(44, 195, 39, 39, black,black ,103,"", 0, prop20,true);
    drawButton(158, 195, 39, 39, black,black ,103,"", 0, prop20,true);
    Brain.Screen.drawImageFromFile("Field.png.png", 0, 0);
  drawButton(238, 0, 242, 60, black,white ,10101,"Blue Left 1", 1, prop30,true);
  drawButton(238, 59, 242, 60, green,white ,10102,"Blue Left 2", 1, prop30,false);
  prevScreen = 10102;

    drawButton(238, 118, 242, 60, black,white ,301,"Select", 1, prop30,true);
  
  drawButton(238, 177, 242, 60, black,white ,1,"Back", 1, prop30,true);
  autonNumber = 10102;
  } else if (screenNumber == 102) {
    //match screen blue center
     
  
    drawButton(6, 82, 75, 75, black,black ,101,"", 0, prop20,true);
    drawButton(6, 43, 39, 39, black,black ,101,"", 0, prop20,true);
    drawButton(6, 156, 39, 39, black,black ,101,"", 0, prop20,true);

    drawButton(160, 82, 75, 75, black,black ,104,"", 0, prop20,true);
    drawButton(196, 43, 39, 39, black,black ,104,"", 0, prop20,true);
    drawButton(196, 156, 39, 39, black,black ,104,"", 0, prop20,true);

    drawButton(83, 159, 75, 75, black,black ,103,"", 0, prop20,true);
    drawButton(44, 195, 39, 39, black,black ,103,"", 0, prop20,true);
    drawButton(158, 195, 39, 39, black,black ,103,"", 0, prop20,true);
    Brain.Screen.drawImageFromFile("Field.png.png", 0, 0);
  drawButton(238, 0, 242, 60, black,white ,10201,"Blue Center 1", 1, prop30,true);
  drawButton(238, 59, 242, 60, black,white ,10202,"Blue Center 2", 1, prop30,true);
  prevScreen = 102;
 autonNumber = 4;
    drawButton(238, 118, 242, 60, black,white ,301,"Skills", 1, prop30,true);
  
  drawButton(238, 177, 242, 60, black,white ,1,"Back", 1, prop30,true);
  } else if (screenNumber == 10201) {
  //match screen blue center Selected 1

  
    drawButton(6, 82, 75, 75, black,black ,101,"", 0, prop20,true);
    drawButton(6, 43, 39, 39, black,black ,101,"", 0, prop20,true);
    drawButton(6, 156, 39, 39, black,black ,101,"", 0, prop20,true);

    drawButton(160, 82, 75, 75, black,black ,104,"", 0, prop20,true);
    drawButton(196, 43, 39, 39, black,black ,104,"", 0, prop20,true);
    drawButton(196, 156, 39, 39, black,black ,104,"", 0, prop20,true);

    drawButton(83, 159, 75, 75, black,black ,103,"", 0, prop20,true);
    drawButton(44, 195, 39, 39, black,black ,103,"", 0, prop20,true);
    drawButton(158, 195, 39, 39, black,black ,103,"", 0, prop20,true);
    Brain.Screen.drawImageFromFile("Field.png.png", 0, 0);
  drawButton(238, 0, 242, 60, green,white ,10201,"Blue Center 1", 1, prop30,false);
  drawButton(238, 59, 242, 60, black,white ,10202,"Blue Center 2", 1, prop30,true);
  prevScreen = 10201;
 
    drawButton(238, 118, 242, 60, black,white ,301,"Select", 1, prop30,true);
  
  drawButton(238, 177, 242, 60, black,white ,1,"Back", 1, prop30,true);
  autonNumber = 10201;
  } else if (screenNumber == 10202) {
  //match screen blue center Selected 2

    drawButton(6, 82, 75, 75, black,black ,101,"", 0, prop20,true);
    drawButton(6, 43, 39, 39, black,black ,101,"", 0, prop20,true);
    drawButton(6, 156, 39, 39, black,black ,101,"", 0, prop20,true);

    drawButton(160, 82, 75, 75, black,black ,104,"", 0, prop20,true);
    drawButton(196, 43, 39, 39, black,black ,104,"", 0, prop20,true);
    drawButton(196, 156, 39, 39, black,black ,104,"", 0, prop20,true);

    drawButton(83, 159, 75, 75, black,black ,103,"", 0, prop20,true);
    drawButton(44, 195, 39, 39, black,black ,103,"", 0, prop20,true);
    drawButton(158, 195, 39, 39, black,black ,103,"", 0, prop20,true);
    Brain.Screen.drawImageFromFile("Field.png.png", 0, 0);
  drawButton(238, 0, 242, 60, black,white ,10201,"Blue Center 1", 1, prop30,true);
  drawButton(238, 59, 242, 60, green,white ,10202,"Blue Center 2", 1, prop30,false);
 
    drawButton(238, 118, 242, 60, black,white ,301,"Select", 1, prop30,true);
  
  drawButton(238, 177, 242, 60, black,white ,1,"Back", 1, prop30,true);
  autonNumber = 10202;
   } else if (screenNumber == 103) {
    //match screen red center
  
        drawButton(83, 5, 75, 75, black,black ,102,"", 0, prop20,true);
    drawButton(44, 5, 39, 39, black,black ,102,"", 0, prop20,true);
    drawButton(158, 5, 39, 39, black,black ,102,"", 0, prop20,true);
  
    drawButton(6, 82, 75, 75, black,black ,101,"", 0, prop20,true);
    drawButton(6, 43, 39, 39, black,black ,101,"", 0, prop20,true);
    drawButton(6, 156, 39, 39, black,black ,101,"", 0, prop20,true);

    drawButton(160, 82, 75, 75, black,black ,104,"", 0, prop20,true);
    drawButton(196, 43, 39, 39, black,black ,104,"", 0, prop20,true);
    drawButton(196, 156, 39, 39, black,black ,104,"", 0, prop20,true);
    Brain.Screen.drawImageFromFile("Field.png.png", 0, 0);
  drawButton(238, 0, 242, 60, black,white ,10301,"Red Center 1", 1, prop30,true);
  drawButton(238, 59, 242, 60, black,white ,10302,"Red Center 2", 1, prop30,true);
  prevScreen = 103;
autonNumber = 4;
    drawButton(238, 118, 242, 60, black,white ,301,"Skills", 1, prop30,true);
  
  drawButton(238, 177, 242, 60, black,white ,1,"Back", 1, prop30,true);
   }else if (screenNumber == 10301) {
   //match screen red center selected 1
 
        drawButton(83, 5, 75, 75, black,black ,102,"", 0, prop20,true);
    drawButton(44, 5, 39, 39, black,black ,102,"", 0, prop20,true);
    drawButton(158, 5, 39, 39, black,black ,102,"", 0, prop20,true);
  
    drawButton(6, 82, 75, 75, black,black ,101,"", 0, prop20,true);
    drawButton(6, 43, 39, 39, black,black ,101,"", 0, prop20,true);
    drawButton(6, 156, 39, 39, black,black ,101,"", 0, prop20,true);

    drawButton(160, 82, 75, 75, black,black ,104,"", 0, prop20,true);
    drawButton(196, 43, 39, 39, black,black ,104,"", 0, prop20,true);
    drawButton(196, 156, 39, 39, black,black ,104,"", 0, prop20,true);

    Brain.Screen.drawImageFromFile("Field.png.png", 0, 0);
  drawButton(238, 0, 242, 60, green,white ,10301,"Red Center 1", 1, prop30,false);
  drawButton(238, 59, 242, 60, black,white ,10302,"Red Center 2", 1, prop30,true);
  prevScreen = 10301;


    drawButton(238, 118, 242, 60, black,white ,301,"Select", 1, prop30,true);
  
  drawButton(238, 177, 242, 60, black,white ,1,"Back", 1, prop30,true);
   autonNumber = 10301;
   } else if (screenNumber == 10302) {
   //match screen red center selected 2

        drawButton(83, 5, 75, 75, black,black ,102,"", 0, prop20,true);
    drawButton(44, 5, 39, 39, black,black ,102,"", 0, prop20,true);
    drawButton(158, 5, 39, 39, black,black ,102,"", 0, prop20,true);
  
    drawButton(6, 82, 75, 75, black,black ,101,"", 0, prop20,true);
    drawButton(6, 43, 39, 39, black,black ,101,"", 0, prop20,true);
    drawButton(6, 156, 39, 39, black,black ,101,"", 0, prop20,true);

    drawButton(160, 82, 75, 75, black,black ,104,"", 0, prop20,true);
    drawButton(196, 43, 39, 39, black,black ,104,"", 0, prop20,true);
    drawButton(196, 156, 39, 39, black,black ,104,"", 0, prop20,true);
    Brain.Screen.drawImageFromFile("Field.png.png", 0, 0);
  drawButton(238, 0, 242, 60, black,white ,10301,"Red Center 1", 1, prop30,true);
  drawButton(238, 59, 242, 60, green,white ,10302,"Red Center 2", 1, prop30,false);
  prevScreen = 10302;
  
    drawButton(238, 118, 242, 60, black,white ,301,"Select", 1, prop30,true);
  
  drawButton(238, 177, 242, 60, black,white ,1,"Back", 1, prop30,true);
   autonNumber = 10302;
  } else if (screenNumber == 104) {
  //match screen red right
     
        drawButton(83, 5, 75, 75, black,black ,102,"", 0, prop20,true);
    drawButton(44, 5, 39, 39, black,black ,102,"", 0, prop20,true);
    drawButton(158, 5, 39, 39, black,black ,102,"", 0, prop20,true);
  
    drawButton(6, 82, 75, 75, black,black ,101,"", 0, prop20,true);
    drawButton(6, 43, 39, 39, black,black ,101,"", 0, prop20,true);
    drawButton(6, 156, 39, 39, black,black ,101,"", 0, prop20,true);

    drawButton(83, 159, 75, 75, black,black ,103,"", 0, prop20,true);
    drawButton(44, 195, 39, 39, black,black ,103,"", 0, prop20,true);
    drawButton(158, 195, 39, 39, black,black ,103,"", 0, prop20,true);
    Brain.Screen.drawImageFromFile("Field.png.png", 0, 0);
  drawButton(238, 0, 242, 60, black,white ,10401,"Red Right 1", 1, prop30,true);
  drawButton(238, 59, 242, 60, black,white ,10402,"Red Right 2", 1, prop30,true);
  prevScreen = 104;
  autonNumber = 4;
    drawButton(238, 118, 242, 60, black,white ,301,"Skills", 1, prop30,true);
  
  drawButton(238, 177, 242, 60, black,white ,1,"Back", 1, prop30,true);
  } else if (screenNumber == 10401) {
  //match screen red right selected 1
   
        drawButton(83, 5, 75, 75, black,black ,102,"", 0, prop20,true);
    drawButton(44, 5, 39, 39, black,black ,102,"", 0, prop20,true);
    drawButton(158, 5, 39, 39, black,black ,102,"", 0, prop20,true);
  
    drawButton(6, 82, 75, 75, black,black ,101,"", 0, prop20,true);
    drawButton(6, 43, 39, 39, black,black ,101,"", 0, prop20,true);
    drawButton(6, 156, 39, 39, black,black ,101,"", 0, prop20,true);

    drawButton(83, 159, 75, 75, black,black ,103,"", 0, prop20,true);
    drawButton(44, 195, 39, 39, black,black ,103,"", 0, prop20,true);
    drawButton(158, 195, 39, 39, black,black ,103,"", 0, prop20,true);
    Brain.Screen.drawImageFromFile("Field.png.png", 0, 0);
  drawButton(238, 0, 242, 60, green,white ,10401,"Red Right 1", 1, prop30,false);
  drawButton(238, 59, 242, 60, black,white ,10402,"Red Right 2", 1, prop30,true);
  prevScreen = 10401;
  
    drawButton(238, 118, 242, 60, black,white ,301,"Select", 1, prop30,true);
  
  drawButton(238, 177, 242, 60, black,white ,1,"Back", 1, prop30,true);
    autonNumber = 10401;
  } else if (screenNumber == 10402) {
  //match screen red right selected 2
    
        drawButton(83, 5, 75, 75, black,black ,102,"", 0, prop20,true);
    drawButton(44, 5, 39, 39, black,black ,102,"", 0, prop20,true);
    drawButton(158, 5, 39, 39, black,black ,102,"", 0, prop20,true);
  
    drawButton(6, 82, 75, 75, black,black ,101,"", 0, prop20,true);
    drawButton(6, 43, 39, 39, black,black ,101,"", 0, prop20,true);
    drawButton(6, 156, 39, 39, black,black ,101,"", 0, prop20,true);

    drawButton(83, 159, 75, 75, black,black ,103,"", 0, prop20,true);
    drawButton(44, 195, 39, 39, black,black ,103,"", 0, prop20,true);
    drawButton(158, 195, 39, 39, black,black ,103,"", 0, prop20,true);
    Brain.Screen.drawImageFromFile("Field.png.png", 0, 0);
  drawButton(238, 0, 242, 60, black,white ,10401,"Red Right 1", 1, prop30,true);
  drawButton(238, 59, 242, 60, green,white ,10402,"Red Right 2", 1, prop30,false);

  prevScreen = 10402;
    drawButton(238, 118, 242, 60, black,white ,301,"Select", 1, prop30,true);
  

  drawButton(238, 177, 242, 60, black,white ,1,"Back", 1, prop30,true);
    autonNumber = 10402;
  } else if (screenNumber == 4) {
    //settings screen
  Brain.Screen.drawImageFromFile("grad5.png", 0, 0);
  drawButton(0, 200, 60, 40, orange, white, 0, "back", 3, mono12,true);
  prevScreen = 4;
      if (testAuton == 0) {
     drawButton(250, 100, 150, 50, black,white ,3,"TEST: FALSE", 3, prop20,true);
           } else {
    drawButton(250, 100, 150, 50, yellow,white ,3,"TEST: TRUE", 3, prop20,true);
     }
     drawButton(50, 100, 150, 50, black,white ,302,"CALIBRATE", 3, prop20,true);
     drawButton(50, 20, 150, 50, black, white, 303, "TUNE PID", 3, prop20, true);
  } else if (screenNumber == 2) {

    //odom screen
    bool good = true;

    while(good == true){

      //converts doubles to char with 2 decimal places (badly)

      char buffer[50];
      snprintf(buffer, 50, "%.2f", robotX);
      const char* c = buffer;

      Brain.Screen.clearScreen();
Brain.Screen.drawImageFromFile("grad2.png", 0, 0);
      if ((drawButton(0, 200, 60, 40, orange, white, 0, "back", 3, mono12,true) == 1)) {
        good = false;
        screen = 0;
      }

      drawButton(50, 20, 90, 40, black, white, 2, c, 3, mono20,false); 
      drawButton(20, 20, 40, 40, black, white, 2, "X:", 3, mono20,false);
      snprintf(buffer, 50, "%.2f", robotY);
      const char* d = buffer;

      drawButton(50, 83, 90, 40, black, white, 2, d, 3, mono20,false); 
      drawButton(20, 83, 40, 40, black, white, 2, "Y:", 3, mono20,false);
      snprintf(buffer, 50, "%.2f", InertialSensor.heading());
      const char* e = buffer;

      drawButton(115, 146, 90, 40, black, white, 2, e, 3, mono20,false); 
      drawButton(20, 146, 94, 40, black, white, 2, "Heading:", 3, mono20,false);

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
  } else if(screenNumber == 3){
// loading config screen for testAuton false

testAuton = !testAuton;
enterScreen(prevScreen);
  } else if(screenNumber == 301) {
    //screen during a match
        bool good = true;
  if( testAuton == true){
    drawButton(0, 0, 480, 272, black, white, 3, "3", 0, mono60, false);
    wait(1, seconds);
    drawButton(0, 0, 480, 272, black, white, 3, "2", 0, mono60, false);
    wait(1, seconds);
    drawButton(0, 0, 480, 272, black, white, 3, "1", 0, mono60, false);
    wait(1, seconds);
    runAuton();
  }
    while(good == true){

      Brain.Screen.clearScreen();
Brain.Screen.drawImageFromFile("grad6.png", 0, 0);
      if ((drawButton(0, 200, 60, 40, orange, white, 0, "back", 3, mono12,true) == 1)) {
        good = false;
        screen = 0;
      }

      char buffer[50];
      snprintf(buffer, 50, "%.2f", Drivetrain.temperature(percent));
      const char* c = buffer;
      
drawButton(115, 20, 90, 40, black, white, 2, c, 3, mono20,false); 
      drawButton(20, 20, 94, 40, black, white, 2, "Temp:", 3, mono20,false);
      snprintf(buffer, 50, "%.2f", vexBatteryCapacityGet());
      const char* d = buffer;

      drawButton(115, 83, 90, 40, black, white, 2, d, 3, mono20,false); 
      drawButton(20, 83, 94, 40, black, white, 2, "Battery:", 3, mono20,false);
      snprintf(buffer, 50, "%.2f", Drivetrain.torque());
      const char* e = buffer;

      drawButton(115, 146, 90, 40, black, white, 2, e, 3, mono20,false); 
      drawButton(20, 146, 94, 40, black, white, 2, "Torque:", 3, mono20,false);

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
      wait(30, msec);
      }
  Brain.Screen.renderDisable();  
  } else if (screenNumber == 302) {
    InertialSensor.calibrate();
    drawButton(0, 0, 480, 272, black, white, 3, "CALIBRATING", 0, mono60, false);
    wait(2, seconds);
    drawButton(0, 0, 480, 272, black, white, 3, "DONE", 0, mono60, false);
    wait(0.5, seconds);
    enterScreen(4);
  } else if (screenNumber == 303) {
  //tuning PID screen
  Brain.Screen.drawImageFromFile("grad100.png", 0, 0);
        char buffer[50];
      snprintf(buffer, 50, "%.6f", drive_kP);
      const char* c = buffer;
      
  drawButton(115, 20, 90, 40, black, white, 2, c, 3, mono20,false); 
      drawButton(20, 20, 94, 40, black, white, 2, "Drive kP", 3, mono20,false);
      snprintf(buffer, 50, "%.6f", drive_kI);
      const char* d = buffer;

      drawButton(115, 83, 90, 40, black, white, 2, d, 3, mono20,false); 
      drawButton(20, 83, 94, 40, black, white, 2, "Drive kI", 3, mono20,false);
      snprintf(buffer, 50, "%.6f", drive_kD);
      const char* e = buffer;

      drawButton(115, 146, 90, 40, black, white, 2, e, 3, mono20,false); 
      drawButton(20, 146, 94, 40, black, white, 2, "Drive kD", 3, mono20,false);


           snprintf(buffer, 50, "%.6f", turn_kP);
      const char* f = buffer;
      
  drawButton(315, 20, 90, 40, black, white, 2, f, 3, mono20,false); 
      drawButton(220, 20, 94, 40, black, white, 2, "Turn kP", 3, mono20,false);
      snprintf(buffer, 50, "%.6f", turn_kI);
      const char* g = buffer;

      drawButton(315, 83, 90, 40, black, white, 2, g, 3, mono20,false); 
      drawButton(220, 83, 94, 40, black, white, 2, "Turn kI", 3, mono20,false);
      snprintf(buffer, 50, "%.6f", turn_kD);
      const char* h = buffer;

      drawButton(315, 146, 90, 40, black, white, 2, h, 3, mono20,false); 
      drawButton(220, 146, 94, 40, black, white, 2, "Turn kD", 3, mono20,false);
      drawButton(0, 200, 60, 40, orange, white, 0, "back", 3, mono12,true);
  }

  
 /*  else {Brain.Screen.print(screen);
  Brain.Screen.setCursor(1, 1);
 Brain.Screen.print(screenNumber);
 
 }
 */
  if(screenNumber != screen) {
    //this checks if a button was pressed, when the screen is redrawn
    //the screen is redrawn whenenever the brain is pressed, regardless of finger placement
    if(Brain.Screen.pressing()) {
      waitUntil(Brain.Screen.pressing() == false);
      enterScreen(screen);
    }
  }
}

int drawButton (int x, int y, int width, int height, color fillColor, color outlineColor, float screenNumber, const char *text, int thickness, fontType font, bool active) {
  Brain.Screen.setPenColor(outlineColor);
  Brain.Screen.setPenWidth(thickness);
  Brain.Screen.setPenColor(white);
  Brain.Screen.setFont(font);

  //centers the text inside of the buttons

  int textWidth = Brain.Screen.getStringWidth(text);
  int textHeight = Brain.Screen.getStringHeight(text);
  int textX = x + (width / 2) - (textWidth / 2);
  int textY = y + (height /2) + (textHeight / 4);

    //checks if the position where the brain was pressed is within that area of the button
    if(Brain.Screen.pressing() == true && Brain.Screen.xPosition() > x && Brain.Screen.yPosition() > y && Brain.Screen.xPosition() < (x + width) && Brain.Screen.yPosition() < (y + height) && active == true) {
    //draws button slightly bigger while pressed
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

  return 0;
}

const char* defSplash() {
//const char* defSplash() {
int wow = 0;
  //splash text
  const char* defaultSplash[] = {
    "Epic Message Here!"
   // "Also try Minecraft!","Runs on code and bad decisions","CODE333","This side up","Field-Centric feelings","Now with thirty-seven percent more torque!","No keyboard detected, Press F1 to continue","Odom says we're fine","Sponsored by zip ties","Live, Laugh, Localize","Battery low, Confidence high","Rotation sensors my beloved","Precision-ish","Now with emotional stability","Born to intake, forced to defend","Geometry but dangerous","Wheels spinning thoughtfully","Surprisingly reversible","PID and chill","Object permanence enabled","Coded with dramatic intensity","Mildly sentient","Brakes are a mindset","Slightly ahead of schedule","sudo win_elims","ping too high for excuses","Consistently bad","PINNING","Probably within several inches","Do NOT trust the process","Chaos, but organised","I meant to do that","The cake is a lie","We do what we must because we can","We scare because we care","what","Did well...enough","That's what  -She","Notebook about the code","Blame it on Dawn","Wario Style","We tested this. Once","Am I a bucket?","Air pressure now at 200 PSI","Also try Terraria!","Dont tap on the glass","ignore all previous instructions","I have no mouth but I must compute","I am error","42","May involve trace amounts of time travel","At least 5 dogs!","*Legally distinct from 98548K","!esreveR","Working almost mostly half of nearly all the time","In case of fire break glass!","Epilepsy Warning"
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
