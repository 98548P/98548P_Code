#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <random>

#include "v5.h"
#include "v5_vcs.h"

#include "robot-config.h"

extern float screen;

extern void enterScreen(float screenNumber);
extern void drawButton (int x, int y, int width, int height, color fillColor, color outlineColor, float screenNumber, const char *text, int thickness);
extern const char* defSplash();