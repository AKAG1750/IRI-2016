#!/bin/bash

#chmod +x initial.sh

#curl -O -L "https://irimodel.org/IRI-2016/00_iri.tar";
wget -c https://irimodel.org/IRI-2016/00_iri.tar &&  tar -xvf 00_iri.tar 
wget -c http://irimodel.org/indices/apf107.dat
wget -c http://irimodel.org/indices/ig_rz.dat

wget -c http://irimodel.org/COMMON_FILES/00_ccir-ursi.tar &&  tar -xvf 00_ccir-ursi.tar
#tar  -xvf 00_iri.tar 
 
 #for file in *.asc; do 
 #wget -c  http://irimodel.org/COMMON_FILES/ "$file" 
 #done
 
#wget -c  http://irimodel.org/COMMON_FILES/ccir{11..22}.asc
#wget -c  http://irimodel.org/COMMON_FILES/ursi{11..22}.asc

 #wget -r -l1    http://irimodel.org/COMMON_FILES/ -A.asc
 #mv "$(pwd)"/COMMON_FILES/
#http://irimodel.org/COMMON_FILES/ccir11.asc
#for file in *.for; do 
 #  mv -- "$file" "${file%.for}.F"
#done

 #f2c -c *.f
  
 
 # for file in *.dat; do 
    # rm -- "$file"  
# done

 # for file in *.for; do 
    # rm -- "$file"  
# done
 
#f77 -o iri iritest.for irisub.for irifun.for iritec.for iridreg.for igrf.for cira.for iriflip.for
#./iri

#SOURCEIRI= iritest.for irisub.for irifun.for iritec.for iridreg.for igrf.for cira.for iriflip.for irifun.for cira.for 
 # iritec.for iridreg.for igrf.for cira.for iriflip.for     iritec.for iridreg.for igrf.for 
   
 

export LD_LIBRARY_PATH="$(pwd)":$LD_LIBRARY_PATH
# echo $LD_LIBRARY_PATH