#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES

double deg2rad(double x)
{
   return M_PI * x / 180 - 2 * M_PI * floor(x / 360);
}

double rad2deg(double x)
{
   double deg;
   if (x < 0)
      deg = 180 * x / M_PI + 360 * floor(x / (2 * M_PI));
   else
      deg = 180 * x / M_PI - 360 * floor(x / (2 * M_PI));
   return deg;
}

void GIS2Radar(double *range,
               double *bearing,
               double glonInit,
               double glatInit,
               double glonFinal,
               double glatFinal)
{
   double mpi = M_PI / 180;
   double LonIni = deg2rad(glonInit);
   double LatIni = deg2rad(glatInit);
   double LonFin = deg2rad(glonFinal);
   double LatFin = deg2rad(glatFinal);
   double Diff = fabs(LonFin - LonIni);
   double x = cos(LatFin) * sin(Diff);
   double y = cos(LatIni) * sin(LatFin) - cos(LatFin) * sin(LatIni) * cos(Diff);
   *bearing = atan2(x, y) / mpi;
   *range = (atan2(x, y) / mpi) * 3963;
}

void RtoG(double range,
          double bearing,
          double glonInit,
          double glatInit,
          double *glonFinal,
          double *glatFinal)
{

   double LonIni = deg2rad(glonInit);
   double LatIni = deg2rad(glatInit);
   double angudist = range / 3963;
   double BearingR = deg2rad(bearing);
   double LatFin = asin(sin(LatIni) * cos(angudist) + cos(LatIni) * sin(angudist) * cos(BearingR));
   double LonFin = LonIni + atan2(sin(BearingR) * sin(angudist) * cos(LatIni), cos(angudist) - sin(LatIni) * sin(LatFin));

   *glonFinal = rad2deg(LonFin);
   *glatFinal = rad2deg(LatFin);
}
