#include "vex.h"
#include "opControl.h"

using namespace vex;

void joyStickControl ()
{
  //Get the raw sums of appropriate joystick axes
  double front_left = (double)(Controller1.Axis3.position(pct) + Controller1.Axis4.position(pct) + Controller1.Axis1.position(pct));
  double back_left = (double)(Controller1.Axis3.position(pct) - Controller1.Axis4.position(pct) + Controller1.Axis1.position(pct));
  double front_right = (double)(Controller1.Axis3.position(pct) - Controller1.Axis4.position(pct) - Controller1.Axis1.position(pct));
  double back_right = (double)(Controller1.Axis3.position(pct) + Controller1.Axis4.position(pct) - Controller1.Axis1.position(pct));

  //Find the largest raw sum or 100
  double max_raw_value = std::max(front_left,std::max(back_left,std::max(front_right,std::max(back_right,100.0))));
  
  //Scale down each value if there was one larger than 100, otherwise leave them alone
  //The largest value will be scaled down to 100, and the others will be reduced by the same factor
  front_left = front_left / max_raw_value * 100;
  back_left = back_left / max_raw_value * 100;
  front_right = front_right / max_raw_value * 100;
  back_right = back_right / max_raw_value * 100;

  //Write the scaled sums out to the various motors
  front_L.spin(fwd, front_left, velocityUnits::pct);
  back_L.spin(fwd, back_left, velocityUnits::pct);
  front_R.spin(fwd, front_right, velocityUnits::pct);
  back_R.spin(fwd, back_right, velocityUnits::pct);
}

void manualIndexerControl()
{
  if (Controller1.ButtonR1.pressing())
  {
    indexer.spin(fwd, 100, pct);
    sorter.spin(fwd, 100, pct);
  }

  else if (Controller1.ButtonR2.pressing())
  {
    indexer.spin(fwd, 100, pct);
    sorter.spin(fwd, -100, pct);
  }

  else
  {
    indexer.stop(brake);
    sorter.stop(brake);
  }

}
