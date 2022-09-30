This is a c code which needs the gnuplot and "wget" parkages. 

to compile:

1 Open the terminal type:
2 "chmod +x  initial.sh "
3 " ./initial.sh " to downloald the required iri files
4 " make lib " to create the shared library 
5 " chmod + x  libdir.sh
6 " ./libdir.sh " to export the library to the current directory 
         or copy and paste the contain of "libdir.sh" file in the terminal
7 " make iri "
8 " ./iri " then input the iri data profile
7 " make data 
8 " ./data "  	 to create a text file named by default "data.txt" which is used to do the numerical analysis
9 " make plot" 
10 " ./plot " to plot the desired graph
	
	Ajustment in for the graph
       ---------------------------
The graph algorithm is formated in the way to plot any data required. The parameters can be change inside the  file 
"mainData.c" and "mainPlot.c". Additional instructions are can be readed inside latter files.  




