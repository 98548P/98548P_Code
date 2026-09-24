#include "odom.h"
#include "UI.h"
#include "functions.h"

using namespace vex;

#include "vex.h"
#include <iostream>

using namespace std;

int Picount = 0;

double factorial(int n) {
    double fact = 1.0;
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

int randomInt(int max) {
    int random = rand()%max;
    return random;
}

void randSeed() {
  Uptake.setStopping(coast);
  Uptake.spin(vex::forward);
  wait(0.5, seconds);
  Uptake.stop();
  wait(0.5,seconds);
  //entropy
  //srand(((((((Intake.position(deg) + OuttakeMotorB.position(degrees)) - Uptake.position(degrees)) * InertialSensor.heading() + 1) + Drivetrain.rotation()) - (robotX * robotY)) * 1000));
        srand((Brain.Timer.time(msec)));
        
}
//lester
/*
double calculatePI(double n) {
    double pi = 3.0;
    double sign = 1.0;
    
    for (int i = 1; i <= n; i++) {
        double term = 2.0 * i;
        pi += sign * (4.0 / (term * (term + 1.0) * (term + 2.0)));
        sign *= -1.0; // Alternate between addition and subtraction
    }
    return pi;
}


void PIcount()  {
    std::setprecision(100);
  Picount = Picount + 1;
  char buffer[100];
    drawButton(0, 0, 480, 272, black, white, 3, "", 0, mono15, false);
 snprintf(buffer, 100, "%.30f",calculatePI(100) );
  const char* P = buffer;

  int textWidth = Brain.Screen.getStringWidth(P);
  int textHeight = Brain.Screen.getStringHeight(P);
  int textX = (480 / 2) - (textWidth);
  int textY = (272 /2) + (textHeight / 4);
  Brain.Screen.printAt(textX, textY, P);

}

*/