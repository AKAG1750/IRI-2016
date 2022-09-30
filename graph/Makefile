#-----------------
#   Compiler
#------------------ 
CCG =gcc

CC = gcc 

CF = gfortran
#------------------
#   Libraries
#------------------

LIBRARY      = 
ITINCLUDE3  =   #-I/... # when include files are requested
ITINCLUDE   = ${ITINCLUDE3}
ITLIB       = #-L/usr/lib/ # directory where the required libraries are

#----------------------------
#   Compilation options
#----------------------------
FFLAGS=-O3 -Wall -Wextra -std=gnu #optimization (for level 3) flags, compiler warnings and the strictest adherence to the latest standards

INCLUDE_PATH = -I./ ${ITINCLUDE}
LDFLAGS      = #--enable-auto-import #-Wl#,--enable-auto-import 
LIBRARY      =   -L. -lslib 
WARN         = #-Wno-deprecated  
DEFINES      =-O3 -Wall -Wextra  
 
 

SOURCEIRI=  irisub.for irifun.for iritec.for iridreg.for igrf.for cira.for iriflip.for
SOURCEINP= input.c  
SOURCEMI= iritest.for
SOURCEMAIND= mainData.c
SOURCEMAINP= mainPlot.c

OBJIRI=$(subst .for,.o,$(SOURCEIRI))  
OBJINP=$(subst .c,.o,$(SOURCEINP)) 
OBJMI=$(subst .for,.o,$(SOURCEMI))
OBJMAIND=$(subst .c,.o,$(SOURCEMAIND))
OBJMAINP=$(subst .c,.o,$(SOURCEMAINP))

TESTOBJ =    ${OBJIRI}  ${OBJINP}

 
%.o: %.c   ;  ${CC} ${DEFINES}  -std=gnu17  -fpic -o $@ -c $< 
#%.o: %.c   ;  ${CC} ${DEFINES}  -std=c17  -fpic -o $@ -c $< 
%.o: %.for ;  $(CF) ${DEFINES}  -std=c17  -fpic -o $@ -c $< 
 

#----------------------------
#   Files to be compiled
#---------------------------- 
 
TARGET  = slib.so
TARGETLIB  =libslib.so

.PHONY:lib 
lib: 	${TESTOBJ} 
	${CC} ${DEFINES}  -std=c17 -shared -o ${TARGET} ${TESTOBJ} 
	${CC} ${DEFINES}  -std=c17 -shared -o ${TARGETLIB} ${TESTOBJ} 
  

iri: 	${TARGETLIB}  ${OBJMI}
	${FC}  ${DEFINES}  -std=c17  -o iri ${OBJMI} ${TARGETLIB} 
	
	
#plot: 	${TARGETLIB}  ${OBJMAIN}
#	${FC}  ${DEFINES}  -std=c17  -o plot ${OBJMAIN} ${TARGETLIB} 

data: 	${OBJINP}  ${OBJMAIND}
	${FC}  ${DEFINES}  -std=c17  -o data ${OBJMAIND} ${OBJINP} 


plot: 	${OBJINP}  ${OBJMAINP}
	${CC}  ${DEFINES}  -std=gnu17  -o plot ${OBJMAINP} ${OBJINP} 
	

.PHONY: cleandata
cleandata: 
	@rm -f *.mod *.o     ${OBJMAIND} data ${OBJINP}
	
.PHONY: cleanplot
cleanplot: 
	@rm -f *.mod *.o     ${OBJMAINP} plot ${OBJINP}
	
	
.PHONY: clean
clean: 
	@rm -f *.mod *.o ${TARGET} ${TARGETLIB} ${OBJMI}  ${OBJMAIN} iri plot fort.7 
