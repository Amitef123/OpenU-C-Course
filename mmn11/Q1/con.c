#include <stdio.h> 
#include <string.h>
#include <ctype.h>
#define LENGTH 81
char s1[LENGTH];
char s2[LENGTH];

void contract (char s1[],char s2[]) /*this function get two string and make a contraction for s1 and save it in s2*/
{
	int i,place=0,counter=0;
	for(i=0;i<(strlen(s1));i++)
	{
		
		while (s1[i]==(-1+s1[i+1]))
		{
			counter++;
			i++;
		}

		if (counter==0)
		{
			s2[place]=s1[i];
			place=place+1;
		}
		if (counter==1)
		{
			s2[place]=s1[i-1];
			s2[place+1]=s1[i];
			place=place+2;
			counter=0;
		}
		if (counter>1)
		{
			s2[place]=s1[i-counter];
			s2[place+1]='-';
			s2[place+2]=s1[i];
			place=place+3;
			counter=0;
		}
	}	
}



void print(char line[])
{
	int d=0;
	for(;d<strlen(line);d++)
	{
		printf("%c",line[d]);
	}
}

int main() 
{
	
	printf("Please enter string:\n"); 
	fgets(s1, LENGTH, stdin);
	printf("The text is : %s\n",s1);
	contract(s1,s2);
	printf("The contraction is :");
	print(s2);
	
	return 0;

} 


