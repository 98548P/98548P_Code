using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern bool RemoteControlCodeEnabled;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );
extern int Controlle();

extern inertial InertialSensor;
extern motor OUT;
extern motor IN;
extern motor_group OUTIN;
extern motor_group Cascade;
extern digital_out Pin_grabber;
extern digital_out Pin_lifter;

//Driving colsom man
extern motor leftMotorA;
extern motor leftMotorB;
extern motor_group LeftDriveSmart;
//Right side of the drivetrain
extern motor rightMotorA;
extern motor rightMotorB;
extern motor_group RightDriveSmart;
extern drivetrain Drivetrain;