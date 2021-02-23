/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       X-Drive_Test_Code                                         */
/*    Author:       Team 71811N                                               */
/*    Created:      Sun July 26 2020                                          */
/*    Description:  Test code for our x-drive                                 */
/*                                                                            */
/*----------------------------------------------------------------------------*/
//
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "v5.h"
#include "v5_vcs.h"

#include "robot-config.h"

#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)