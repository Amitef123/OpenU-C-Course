#include <stdio.h> 
#include <string.h>
#include <ctype.h>
#define LENGTH 101

void print(char line[]);
void checkline (char line[]);
int checkspecial(char line[]);
int skipcomments(char line[],int i);
char line[LENGTH];
char par[LENGTH];
int allbalance=0;

void checkline (char line[])/*check the balance of the all project and print for each line if it balance and at the end it print if the all project is balanced */
{
	char par[LENGTH];
	char cvalue= 5+'"';
	int i,j=-1,balance=0;
	print(line);
	balance=checkspecial(line);
	if(balance==0 && line[0]!='\n')
	{
		for(i=0;i<(strlen(line));i++)
		{
			if ((line[i]=='/'&&line[i+1]=='*')||line[i]=='"'||line[i]==cvalue)
			{
				i=skipcomments(line,i);
			}
			if (line[i]=='{'||line[i]=='['||line[i]=='(')
			{
				j=j+1;
				par[j] = line[i];
			}
			if (line[i]=='}'||line[i]==']'||line[i]==')')
			{
	
				if (line[i]=='}')
				{
					if(j<0||par[j]!='{')
					{
						balance=1;
						allbalance=1;
					}
					else
					{
						j=j-1;
					}
				}
				if (line[i]==']')
				{
					if(j<0||par[j]!='[')
					{
						balance=1;
						allbalance=1;
					}
				else
					{
					j=j-1;
					}
				}
				if (line[i]==')')
				{
					if(j<0||par[j]!='(')
					{
						balance=1;
						allbalance=1;
					}
				else
					{
					j=j-1;
					}
				}
			}
		}
	}
	if (balance==1)
	{
		printf("the line is not balance \n");
	}
	else
	{
		printf("the line is balance \n");
	}
	

}

void print(char line[])/*print the line that chacked */
{
	int d=0;
	for(;d<strlen(line);d++)
	{
		printf("%c",line[d]);
	}
}
int checkspecial(char line[]) 
/*if the line is special then isSpecial value equal 1 else isSpecial equal to 0 or 2  */
{
	int i=0;
	int isSpecial=0;
	for(;i<strlen(line)-1&&isSpecial<1;i++)
	{
		if(isspace(line[i]))
			i++;
		if (line[i]=='{'||line[i]=='}')
		{
			isSpecial++;
			i++;
		}
		if (line[i]!='{'&&line[i]!='}'&&!isspace(line[i]))
		{
			isSpecial=isSpecial+2;
		}
	}	
		if (isSpecial==1)
			return 1;
	return 0;
}
int skipcomments(char line[],int i)/*skip the phrase that in comment */
{
	int k=i+1;
	char cvalue= 5+'"';
	for (;k<strlen(line);k++)
	{
		if(line[k]=='*'&&line[k+1]=='/')
			return k+2;
		if(line[k]=='"'&&line[i]==line[k])
			return k+1;
		if(line[k]==cvalue &&line[i]==line[k])
			return k+1;
	}
	return k+1;
}


int main() 
{
	printf("Please enter your C program to check balance\n"); 
	while (fgets(line,LENGTH,stdin))
	{
		checkline(line);
	}
	if (allbalance==0)
	{
		printf("the program is balance \n");
	}
	else
	{
		printf("the program is not balance \n");
	}
	
	return 0;
}


