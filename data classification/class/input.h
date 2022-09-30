	#ifndef FUNCS_H
	#define FUNCS_H 
	
#include <stdio.h>
 //int i,j,k;
  
double  Lagrange(double * x,double * y, int N, double  var) ;
    
void GetNumData(int n);

//void sortIindex(double*  M, int sizeM, int MI[] );

int *sortIindex(double*  M, int sizeM );

void sortTable(double*  values, int sizeM, int len, int n, int * MI);

double *FunLagran(double *x, int N, int v1, int v2);
 
 #endif
