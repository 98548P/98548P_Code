#include "vex.h"

float autonNumber;

int testAuton = 0;

void SkillAuton () {

}

void BlueLeft1 () {

}

void BlueLeft2 () {

}

void BlueCenter1 () {

}

void BlueCenter2 () {

}

void RedCenter1 () {

}

void RedCenter2 () {

}

void RedRight1 () {

}

void RedRight2 () {

}

float runAuton() {
  if ( autonNumber == 4 ) {
    SkillAuton();
  } else if ( autonNumber == 10101 ) {
    BlueLeft1();
  } else if ( autonNumber == 10102 ) {
    BlueLeft2();
  } else if ( autonNumber == 10201) {
    BlueCenter1();
  } else if ( autonNumber == 10202) {
    BlueCenter2();
  } else if ( autonNumber == 10301) {
    RedCenter1();
  } else if ( autonNumber == 10302 ) {
    RedCenter2();
  } else if ( autonNumber == 10401 ) {
    RedRight1();
  } else if ( autonNumber == 10402) {
    RedRight2();
  }
  return 0;
}

