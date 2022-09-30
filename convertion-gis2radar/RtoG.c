
#include <math.h>
#include <stdio.h>
#define _USE_MATH_DEFINES

#include "input.h"

////////////////////////////////////////////////////////////////
///// Convertion from radar coordinates to GIS coordinates /////
///////////////////////////////////////////////////////////////


int main(void)
{
//                    for a the South and western location, put multiple the coordinate by -1
       glonInit = -75;   //  Initial locattion Longitude in degree
       glatInit = 37;    // Initial location Latitude in degree
       range = 1422.319;  // Range
       bearing = 154.963217; // Bearing
       RtoG(range,
            bearing,
            glonInit,
            glatInit,
            &glonFinal,
            &glatFinal);

       printf("------------------------------------\n");
       printf("Longitude is   %lf deg\nLatitude is  %lf deg\n", glonFinal, glatFinal);

       return 0;
}
