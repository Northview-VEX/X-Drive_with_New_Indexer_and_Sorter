using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor back_R;
extern motor back_L;
extern motor front_R;
extern motor front_L;
extern motor sorter;
extern motor indexer;
extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );