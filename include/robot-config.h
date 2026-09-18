using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern smartdrive Drivetrain;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );
extern int Controlle();

extern controller Controller1;
extern motor leftMotorA;
extern motor leftMotorB ;
extern motor_group LeftDriveSmart;
extern motor rightMotorA ;
extern motor rightMotorB ;
extern motor_group RightDriveSmart;
extern inertial DrivetrainInertial ;
extern smartdrive Drivetrain ;
extern motor OUT ;
extern motor IN ;
extern motor_group OUTIN ;