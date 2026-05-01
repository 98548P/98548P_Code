#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "v5.h"
#include "v5_vcs.h"

#include "robot-config.h"

extern float screen;

extern void enterScreen(float screenNumber);
extern int drawButton (int x, int y, int width, int height, color fillColor, color outlineColor, float screenNumber, const char *text, int thickness, fontType font);
extern const char* defSplash();