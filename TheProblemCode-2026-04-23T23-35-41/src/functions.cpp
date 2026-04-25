#include "vex.h"

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
  seed = ((((((Intake.position(deg) + OuttakeMotorB.position(degrees)) - Uptake.position(degrees)) * InertialSensor.heading() + 1) + Drivetrain.rotation()) - (robotX * robotY)) * 1000);
  srand(seed);
}
