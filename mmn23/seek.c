#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>
#include "npos.h"

int main (int argc, char *argv[])
{
	int n;
	int i=1;
	if(argc<3)/*check how many paramter enters */
	{
		printf("please insert number and files you want to check\n");
		exit(0);
	}
	n=atoi(argv[i]);/* insert n the place of the letter*/
	if (n!=atof(argv[i])||n<1)
	{
		printf("first paramter must be a natural number bigger then zero \n");
		exit(0);
	}
	for(i=2;i<argc;i++)
	{
		printf("check for file %s:\n",argv[i]);
		seekn(n,argv[i]);/* call program seek to search for n*/
	}
	printf("program is finish \n");
	exit(0);
} 
