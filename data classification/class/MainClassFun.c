
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "input.h"
//////////////////////////////////////////////////////////////
//// Sort the table from the oldest time to the newest /////
////////////////////////////////////////////////////////////


int main()
{

  int n = 101;    // Number of character removed from the head of the data file
  int sizeM = 467; // Row size to plot
  int len = 17; // Column size 

  int i = 0, j = 0;
  char ch;

  FILE *fp = fopen("tableW.txt", "r");
  double values[len * (sizeM)];
  if (fp == NULL)
    return 1;
  for (i = 0; i < len * (sizeM); ++i)
  {
    fscanf(fp, "%lf", &values[i]);
  }
  pclose(fp); 

  double M[sizeM];
  int *MI;

  for (i = 0; i < sizeM; i++)
  {
    M[i] = 1440 * (values[i * len + 2]) + 60 * values[i * len + 3] + values[i * len + 4];
 
  }
  MI = sortIindex(M, sizeM);  // sort M

  sortTable(values, sizeM, len, n, MI);
 

  return 0;
}
