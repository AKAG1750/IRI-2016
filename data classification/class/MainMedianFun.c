
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "input.h"
///////////////////////////////////////////////////////////////////////
///// Mediiam function filter function thatcalculates foF2 and hmF2 ////
///////////////////////////////////////////////////////////////////////

// Here we use the Lagrange interpolation to get a polynomial that fit the given data,
// in particular, foF2 and hmF2.

// Note that by changing the column numbers, k1 and k2 to the appropriate coulumn, other interpolation function can be  made.

int main()
{
  int i;

  int k1 = 7;

  int k2 = 12;

  double *y;

  int N = 4;

  double x[] = {4., 4.2, 4.3, 4.4}; // Example of some foF2

  y = FunLagran(x, N, k1, k2); // 7 and 12 are the column corresponding to foF2 and hmF2

  for (i = 0; i < N; i++)
  {
    printf("%lf\n", y[i]); // Result
  }

  return 0;
}
