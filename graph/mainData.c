

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"

int main()
{

     int m = 200000;   // maximum number  of character needed 
     int n = 1403;     // number of header character to be removed
     Fileinput = "fort.7";
     Fileoutput = "data.txt";  // create me to perform numerical analysis

     getData(Fileinput, Fileoutput, m, n);

     return 0;
}
