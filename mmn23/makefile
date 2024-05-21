seek: seek.o npos.o
	gcc -g -ansi seek.o npos.o -o seek

seek.o: seek.c npos.h
	gcc -c -Wall -ansi -pedantic seek.c -o seek.o

npos.o: npos.c npos.h 
	gcc -c -Wall -ansi -pedantic npos.c -o npos.o

