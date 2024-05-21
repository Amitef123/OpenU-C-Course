#include "getinput.h"

/* A function that initializes the complex variables to a value of 0 + 0i */
void initialize();

/* A function that performs the entire process of the program and the user interaction (of course using other functions) */
void program(char line[]);

complex A, B, C, D, E, F;

/* The main method: */
int main() 
{
    char line[LINE_LEN];
    initialize();
    program(line);
    return 0;
}


void initialize()
{
    read_comp(&A, 0, 0);
    read_comp(&B, 0, 0);
    read_comp(&C, 0, 0);
    read_comp(&D, 0, 0);
    read_comp(&E, 0, 0);
    read_comp(&F, 0, 0);
}


void program(char line[]) 
{
	int check=0;
    while (check==0) 
    { /* Until the stop command or the end of the file (there is an exit function) */
        if (check_for_stop(line)==1)
      		return; 
        if(read_command(line)==1)
        	return;
    }
}
