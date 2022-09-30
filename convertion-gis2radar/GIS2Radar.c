
#include <math.h>
#include <stdio.h>
#define _USE_MATH_DEFINES

#include "input.h"


////////////////////////////////////////////////////////////////
///// Convertion from GIS coordinates to radar coordinates /////
///////////////////////////////////////////////////////////////


int main(void)
{

  glonInit = -75;  //Initial location longitude in degree
  glatInit = 37;   //Initial location latidude in degree
  glonFinal = -66; //Final location longitude in degree
  glatFinal = 18;  //Final location latidude  in degree

  GIS2Radar(&range,
            &bearing,
            glonInit,
            glatInit,
            glonFinal,
            glatFinal); 
  printf("------------------------------------\n");
  printf(" Bearing is     %lf  deg  \n Range is       %lf miles \n", bearing, range);

  return 0;
}
