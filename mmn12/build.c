#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>
#include "data.h"

extern int N;
static int countvalue=0;
int checkEnd();

int * buildMatrix(int *P)
{
	int i,j,inNum,countnum=0;
	P = malloc(N*N*sizeof(int));
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			inNum = getNum();
			if (inNum==-1)
			{
				clearMatrix(P);
				return NULL;
			}
			countnum=countnum+1;
			countvalue=countvalue+(inNum-countnum);
			*(P+N*i+j)=inNum;
		}
	}
	if(!checkEnd())
	{
		printf("Erorr to much value");
		clearMatrix(P);
		return NULL;
	}
	return P;
}	

void clearMatrix(int *P)
{
	free (P);
}

int isMagicSquare(int *P)
{
	enum {F,T};
	int isMagic = T;
	int magicNumber=0,i,j;

	for (i=0;i<N;i++)
	{
		magicNumber=magicNumber+ *(P+i);
	}
	printf("sum magic number %d \n",magicNumber);
	int sumRow,sumCol;
	for(i=0;i<N;i++)
	{
		sumRow=0;
		sumCol=0;
		for (j=0;j<N;j++)
		{
			sumRow += *(P+N*i+j);
			sumCol += *(P+N*j+i);
		}
		if (sumRow!=magicNumber||sumCol!=magicNumber)
		{
			isMagic = F;
		}
	}
	
	if(isMagic == F)
	{
		printf("the Row or Col are not equal\n");
	}
	if (countvalue!=0)
	{
		isMagic = F;
	}	
	int leftDiag=0,rightDiag=0;
	for (i=0 ; i<N ; i++)
	{
		leftDiag += *(P+i*N+i);
		rightDiag += *(P+(N-i)*N-i-1);
	}
	if(leftDiag !=magicNumber||rightDiag !=magicNumber)
	{
		printf("the diagonal are not equal to the magic number\n");
		isMagic = F;
	}
	return isMagic;
}
void printMatrix(int *P)
{
	int i,j;
	for (i=0;i<N;i++)
	{
		printf("|");
		for (j=0;j<N;j++)
		{
			printf("%4d\t",*(P+N*i+j));
		}
		printf("|\n");
	}
	
}
