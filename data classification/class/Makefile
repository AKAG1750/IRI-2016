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
ITLIB       = #-L/usr/lib/ # directory where the required libraries are

#----------------------------
#   Compilation options
#----------------------------
FFLAGS=-O3 -Wall -Wextra -std=gnu #optimization (for level 3) flags, compiler warnings and the strictest adherence to the latest standards

INCLUDE_PATH = -I./ ${ITINCLUDE}
LDFLAGS      = #--enable-auto-import #-Wl#,--enable-auto-import 
WARN         = #-Wno-deprecated  
DEFINES      =-O3 -Wall -Wextra  
  

SOURCEC= input.c
OBJC=$(subst .c,.o,$(SOURCEC))

 
SOURCEDATA= getData.c
OBJDATA=$(subst .c,.o,$(SOURCEDATA))

 
SOURCEFUN= MainMedianFun.c
OBJFUN=$(subst .c,.o,$(SOURCEFUN)) 

 
SOURCECLASS= MainClassFun.c
OBJCLASS=$(subst .c,.o,$(SOURCECLASS))
 
 
%.o: %.c   ;  ${CC} ${DEFINES}  -std=c17    -o $@ -c $< 
 

#----------------------------
#   Files to be compiled
#----------------------------  
  
	
TESTDATA =    ${OBJDATA} ${OBJC} 
data: 	${TESTDATA}  
	${CC}  ${DEFINES}  -std=c17  -o data   ${TESTDATA} 
	

TESTCLASS =    ${OBJCLASS}   ${OBJC}
class: 	${TESTCLASS}  
	${CC}  ${DEFINES}  -std=c17  -o class   ${TESTCLASS}  
	

TESTFUN =    ${OBJFUN}   ${OBJC}
fun: 	${TESTFUN}  
	${CC}  ${DEFINES}  -std=c17  -o fun   ${TESTFUN}  
	
.PHONY: clean
clean: 
	@rm -f *.mod *.o  data fun class ${OBJSORT} ${TESTSORT} ${TESTFUN} ${TESTDATA} 
