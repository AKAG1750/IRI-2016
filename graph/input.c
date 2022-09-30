#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

//#include "input.h"

void getData(char *Finput, char *Foutput, int m, int n)
{

  int i = 0;

  // FILE* fp;
  char ch;
  // Opening file in reading mode
  FILE *fp = fopen(Finput, "r");
  FILE *temp = fopen(Foutput, "w");

  while (((ch = fgetc(fp)) != EOF) && (i < m))
  {
    if (i > n)
    {
      fprintf(temp, "%c", ch);
    }
    i++;
  }
  fclose(fp);
  fclose(temp);
}

void getGraph(
    char *Finput,
    int k1,
    int k2,
    int sizeM,
    int len,
    char *Title,
    char *Xlabel,
    char *Ylabel,
    char *Xrange,
    char *Yrange,
    char *SaveName,
    char *GraphType)
{

  FILE *fp = fopen(Finput, "r");
  FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
  double values[len * sizeM];
  int j;

  for (j = 0; j < len * sizeM; ++j)
  {
    fscanf(fp, "%lf", &values[j]);
    // printf("%lf         \n",values[j]);
  }
  printf("         \n");
  fclose(fp);
  // sizeM =10;
  fprintf(gnuplotPipe, "plot '-' \n");
  for (j = 0; j < sizeM; j++)
  {
    fprintf(gnuplotPipe, "%lf %lf \n", values[j * len + k1], values[j * len + k2]);
    // printf(   "%lf %lf \n",values[j*len+k1],values[j*len+k2]);
  }

  fprintf(gnuplotPipe, "e\n");
  fprintf(gnuplotPipe, "set terminal %s  \n", GraphType);
  fprintf(gnuplotPipe, "set output  '%s' \n", SaveName);
  fprintf(gnuplotPipe, "set title   '%s' \n", Title);
  fprintf(gnuplotPipe, "set xlabel  '%s' \n", Xlabel);
  fprintf(gnuplotPipe, "set ylabel  '%s' \n", Ylabel);
  fprintf(gnuplotPipe, "set xrange   %s  \n", Xrange);
  fprintf(gnuplotPipe, "set yrange   %s  \n", Yrange);
  fprintf(gnuplotPipe, "refresh\n");
}
