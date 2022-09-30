
#include <stdio.h>
char *Fileinput;
char *Fileoutput;

// void getData(FILE*  fp, FILE * temp, int m, int n);
void getData(char *Finput, char *Foutput, int m, int n);

char *Finput;
int k1;
int k2;
int mm;
int sizeM;
int len;
char *Title;
char *Xlabel;
char *Ylabel;
char *Xrange;
char *Yrange;
char *SaveName;
char *GraphType;

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
    char *GraphType);
