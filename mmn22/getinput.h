
#include "complex.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h> 

#define LINE_LEN 100
#define NUM_COMMAND 9

/* numbers to identify the command names */
enum names {
    READ_COMP, PRINT_COMP, ADD_COMP, SUB_COMP, MULT_COMP_REAL, MULT_COMP_IMG, MULT_COMP_COMP, ABS_COMP, STOP
};

/* check the exsitens of a line and print it */
int check_for_stop(char line[]);

/* operate the recived command, and print error in specifc cases */
int read_command(char line[]);

/*read the command and translate it to a number*/
int which_command(char *p);

/* elimante all the white spaces in string */
void skip_spaces(char *p);

/*check for extra text and print errror*/
int extra_text(char ch);

/*check if the charcater is paramte*/
int is_parameter(char ch);

/* get char and return a pointer to the complex */
complex *which_parameter(char x);


/*return a pointer to the imagenary number (or the next number) */
char *image_num(char *num);






