mycomp: mycomp.o getinput.o complex.o
	gcc -g -ansi mycomp.o getinput.o complex.o -o mycomp -lm

mycomp.o: mycomp.c getinput.h
	gcc -c -Wall -ansi -pedantic mycomp.c -o mycomp.o

getinput.o: getinput.c complex.o getinput.h 
	gcc -c -Wall -ansi -pedantic getinput.c -o getinput.o

complex.o: complex.c complex.h
	gcc -c -Wall -ansi -pedantic complex.c -o complex.o -lm
