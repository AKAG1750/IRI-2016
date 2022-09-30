#-----------------
#   Compiler
#------------------  
CC = gcc
#------------------
#   Libraries
#------------------

LIBRARY      = 
ITINCLUDE3  =   #-I/... # when include files are requested
ITINCLUDE   = ${ITINCLUDE3} 

#----------------------------
#   Compilation options
#----------------------------
FFLAGS=-O3 -Wall -Wextra -std=gnu #optimization (for level 3) flags, compiler warnings and the strictest adherence to the latest standards

INCLUDE_PATH = -I./ ${ITINCLUDE}
LDFLAGS      = #--enable-auto-import #-Wl#,--enable-auto-import 
WARN         = #-Wno-deprecated  
DEFINES      =-O3 -Wall -Wextra   
 
SOURCEC= input.c
SOURCEG= GIS2Radar.c  
SOURCER= RtoG.c
  
OBJC=$(subst .c,.o,$(SOURCEC))
OBJG=$(subst .c,.o,$(SOURCEG))
OBJR=$(subst .c,.o,$(SOURCER))
 
   
%.o: %.c   ;  ${CC} ${DEFINES}  -lm -std=gnu17  -o $@ -c $< 



#----------------------------
#   Files to be compiled
#---------------------------- 
 
  
gis2radar:${OBJC} ${OBJG} 
	${CC}  ${DEFINES} -std=gnu17  -o gis2radar ${OBJC} ${OBJG} -lm 


r2g: 	${OBJC} ${OBJR}  
	${CC}  ${DEFINES} -std=gnu17 -o r2g ${OBJC} ${OBJR} -lm  



.PHONY: clean
clean: 
	@rm -f *.mod *.o  r2g ${OBJC} ${OBJR} gis2radar ${OBJC} ${OBJG} 
