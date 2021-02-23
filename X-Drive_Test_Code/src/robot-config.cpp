#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor back_R = motor(PORT1, ratio18_1, true);
motor back_L = motor(PORT10, ratio18_1, false);
motor front_R = motor(PORT11, ratio18_1, true);
motor front_L = motor(PORT20, ratio18_1, false);
motor sorter = motor(PORT15, ratio6_1, true);
motor indexer = motor(PORT16, ratio6_1, true);
controller Controller1 = controller(primary);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}