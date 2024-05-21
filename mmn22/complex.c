#include "complex.h"
#include <math.h>

void read_comp (complex *var , double real, double image)
{
	var->real = real;
	var->image = image;
}

void print_comp(complex *var)/*a+bi or a-bi*/
{
	printf("%f",var->real);
	if (var->image >=0) /*change the image's promoter*/
		printf("+(%f)i\n",var->image);
	else
		printf("-(%f)i\n",-(var->image));
}

void add_comp(complex *varA, complex *varB)/*a+c)+(b+d)i*/
{
	complex tmp;

	tmp.real = varA->real+varB->real;
	tmp.image= varA->image + varB->image;
	
	print_comp(&tmp);

}

void sub_comp(complex *varA, complex *varB)/*(a-c)+(b-d)i*/
{
	complex tmp;
	tmp.real = varA->real-varB->real;
	tmp.image= varA->image -varB->image;
	print_comp(&tmp);
	
}

void mult_comp_real (complex *varA, double num)/*ma+(mb)i*/
{
	complex tmp;
	tmp.real = varA->real * num;
	tmp.image= varA->image * num;
	print_comp(&tmp);
}

void mult_comp_img(complex *varA, double num)/*-mb+(ma)i*/
{
	complex tmp;
	tmp.real = -(varA->image * num);
	tmp.image= varA->real * num;
	
	print_comp(&tmp);
}

void mult_comp_comp(complex *varA, complex *varB)/*ac-bd)+(ab+bc)i*/
{
	complex tmp;
	tmp.real = (varA->real * varB->real)-(varA->image * varB->image);
	tmp.image= (varA->real * varB->image) + (varA->image * varB->real);
	
	print_comp(&tmp);
}

void abs_comp(complex *varA)/*sqrt(a^2+b^2)*/
{
	printf("%f", sqrt((varA->real*varA->real)+(varA->image * varA->image)));
}

