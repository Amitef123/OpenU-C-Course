magic: magic.o build.o getinput.o
	gcc -g -ansi -Wall -pedantic magic.o build.o getinput.o -o magic
magic.o: magic.c data.h
	gcc -c -ansi -Wall magic.c -o magic.o
build.o: build.c data.h
	gcc -c -ansi -Wall build.c -o build.o
getinput.o: getinput.c data.h
	gcc -c -ansi -Wall getinput.c -o getinput.o

