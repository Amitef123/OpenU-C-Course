
#include <stdio.h>
#include <math.h>

/* the complex number struct */
typedef struct complex {
    double real;
    double image;
} complex;

/*insert the complex number to the paramter*/
void read_comp(complex* var, double real, double image);

/*print the complex number*/
void print_comp(complex *var);

/*sums two complex number*/
void add_comp(complex* varA, complex* varB);

/*substract two complex number*/
void sub_comp(complex *varA, complex *varB);

/*multiple a complex with number*/
void mult_comp_real(complex *varA, double num);

/*multiple a complex number with imagenry number*/
void mult_comp_img(complex *varA, double num);

/*multiple two complex number*/
void mult_comp_comp(complex *varA, complex *varB);

/*return the absouote value of a number*/
void abs_comp(complex *varA);

