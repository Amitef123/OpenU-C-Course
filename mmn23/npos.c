#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>
#include "npos.h"

void seekn (int n, char *p)
{
	
	FILE *fd;
	int ch=0;
	/*findpath(p);*/
	if (!(fd=fopen(p,"r+")))
	{
		fprintf(stderr,"cannot open fil \n");/*if the file cannot open*/
		return;
	}
	fseek(fd,n-1,SEEK_SET);
	ch=fgetc(fd);
	if (ch!=EOF)/* check if n is bigger then the text in the file*/
		printf("the asci code for the letter in place %d is %d \n",n,ch);
	else
		printf("the number %d is bigger then the length of the text in the file\n",n);
	fclose(fd);
	return;
}
