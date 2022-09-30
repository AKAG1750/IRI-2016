
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"

int main()
{
////////////////////////////////////////////////////////
/////// Adjust me to better fit the graph /////////////
///////////////////////////////////////////////////////

     Finput = "data.txt";
     k1 = 2;      // number of column of the data in the x dimension (0,..15)
     k2 = 0;        //number of column to the data in the y dimension (0,..15)
     mm = 500;      // row size of datat.txt
     sizeM = mm - 100 - 33; // ajustement with the header
     len = 15; // column size
     Title = "EDP for March 1, 2019 at 1200 UTC";
     Xlabel = "Plasma Frequency (MHz)";
     Ylabel = "Altitude (km)";
     Xrange = "[0:10]";
     Yrange = "[100:600]";
     SaveName = "EDP_Plot.png";
     GraphType = "png";

     getGraph(
         Finput,
         k1,
         k2,
         sizeM,
         len,
         Title,
         Xlabel,
         Ylabel,
         Xrange,
         Yrange,
         SaveName,
         GraphType);

     return 0;
}
