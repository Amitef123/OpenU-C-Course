#include <stdio.h>
#include "data.h"
#define DEFAULT_N 3

int N=DEFAULT_N;

int main()
{
	int *p = NULL; 
	printf("The matrix size %dX%d \n", N,N);
	p = buildMatrix(p);
	if(p!=NULL)
	{	

		printf("\nThe matrix is: \n");
		printMatrix(p);
		if(isMagicSquare(p))
		{
			printf("True: matrix is magic square\n");
		}
		else
		{
			printf("False: matrix is NOT magic square\n");
		}
	}
	else
	{
		printf("ERROR in creating the Matrix.\n");
	}
	return 0;
}
