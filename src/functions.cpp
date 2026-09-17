#include "vex.h"

int Picount = 0;



int randomInt(int max) {
    int random = rand()%max;
    return random;
}

void randSeed() {
  Uptake.setStopping(coast);
  Uptake.spin(forward);
  wait(0.5, seconds);
  Uptake.stop();
  wait(0.5,seconds);
  //entropy
  //srand(((((((Intake.position(deg) + OuttakeMotorB.position(degrees)) - Uptake.position(degrees)) * InertialSensor.heading() + 1) + Drivetrain.rotation()) - (robotX * robotY)) * 1000));
        srand((Brain.Timer.time(msec)));
}



double calculatePI(double n) {
// Source - https://stackoverflow.com/q/70123672
// Posted by dapet, modified by community. See post 'Timeline' for change history
// Retrieved 2026-09-17, License - CC BY-SA 4.0
    int i;
    double x,y, distance;
    double num_point_circle = 0;
    double num_point_total = 0;
    double final;

    for (i=0; i<n; i++)
    {
    x = (double)rand() / RAND_MAX;
    y = (double)rand() / RAND_MAX;
        distance = sqrt(x*x + y*y);
        if (distance <= 1)
        {
            num_point_circle+=1;
        }
        num_point_total+=1;
    }
    final = ((4 * num_point_circle) / num_point_total);
    return final;

}

void PIcount()  {
  Picount = Picount + 1;
  char buffer[50];
  snprintf(buffer, 50, "%.10f",calculatePI(10) );
  const char* P = buffer;
  drawButton(0, 0, 480, 272, black, white, 3, P, 0, mono60, false);
  
}