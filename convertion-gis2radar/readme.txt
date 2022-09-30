These codes are used to convert radar coordinates (bearing, range) to GIS coordinates (lat, lon) and vice versa in c.

To compile:
1 open either "GIS2Radar.c" or "RtoG.c" to input the desired convertion data.
2 open the terminal and type
 a- "make gis2radar" or "r2g" given the desired convertion 
 b- "./gis2radar " or "./r2g" to get the result


To compile without the makefile, type:

1 "gcc GIS2Radar.c input.c -lm -o run"
2 "./run" to compile


Additional note can be read in the files
