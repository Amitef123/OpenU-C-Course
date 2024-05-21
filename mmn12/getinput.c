#include <stdio.h>
#include <ctype.h>
#include "data.h"

int getNum()
{
	int num=0;
	char c;
	while(isspace(c = getchar()));
	if(c == EOF)
	{
		printf("Error not enough value \n");
		return -1;
	}
	else
	{
		while (c!=EOF&&!isspace(c))
		{
			if(c>='0'&&c<='9')
			{
				num=num*10+((int)(c-'0'));
			}
			else
			{
				printf("error the value is not a digit \n");
				return -1;
			}
			c=getchar();
		}
	}
	return num;
}

int checkEnd()
{
	char c;
	while (isspace(c=getchar()));
	return (c!=EOF)? 0 : 1 ;
}
