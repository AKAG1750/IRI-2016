#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES

double range;
double bearing;
double glonInit;
double glatInit;
double glonFinal;
double glatFinal;

double deg2rad(double x);
double rad2deg(double x);

void GIS2Radar(double *range,
               double *bearing,
               double glonInit,
               double glatInit,
               double glonFinal,
               double glatFinal);

int RtoG(double range,
         double bearing,
         double glonInit,
         double glatInit,
         double *glonFinal,
         double *glatFinal);
