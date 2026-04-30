#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "v5.h"
#include "v5_vcs.h"

#include "robot-config.h"

extern rotation forwardWheel;
extern rotation strafeWheel;

extern double wrapAngle(double angle);
extern double degToInches(double deg);
extern void calculateOdometry();
extern int startOdom();

extern double robotX;
extern double robotY;

extern void driveToPoint(double goalX, double goalY, bool reverse);
//extern void driveToPose(double goalX, double goalY, double goalHeading, bool reverse);