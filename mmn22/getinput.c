#include "getinput.h"

extern complex A, B , C , D , E , F;/*variables*/ 

char *commands[NUM_COMMAND]={"read_comp", "print_comp", "add_comp", "sub_comp", "mult_comp_real", "mult_comp_img", "mult_comp_comp", "abs_comp", "stop"};

int check_for_stop(char line[])
{
	printf("please enter command:\n");
	if(fgets(line,LINE_LEN,stdin)==NULL)
	{
		printf("\n reach EOF without stop\n");
		return 1;
	}
	printf("the line you enterd is:\n");
	printf("%s",line);
	return 0;
}

int read_command (char line[])
{
	int i=0;
	int command;
	char *p;
	char *image;
	p=line;
	for (i=0;p[i]!=0 && (p[i]==' '||p[i]=='\t');i++)/*elimnate all space and tabs in the start*/
	{
	p=p+1;
	}
	command = which_command(p);
	if (command == 10)
	{
		printf("undefined command name\n");
		return 0;
	}
	p=p+strlen(commands[command]);
	skip_spaces(p);/* get ride from all space and tabs*/
	if(p[0] == ',')
	{
		printf("ilegal comma\n");
		return 0;
	}
	
	if(command == STOP)
	{
		extra_text(p[0]);
		printf("close the program\n");
		return 1;
	}
	
	if(is_parameter(p[0])==1)
	{
		return 0;
	}
	if(command == ABS_COMP)
	{
		if(extra_text(p[1])==1)
			return 0;
		abs_comp(which_parameter(p[0]));
		return 0;
	}
	if(command == PRINT_COMP)
	{
		if(extra_text(p[1])==1)
		{
			return 0;
		}
		print_comp(which_parameter(p[0]));
		return 0;
	}
	if(p[1]!=',')
	{
		printf("missing comma \n");
		return 0;
	}
	if(command == ADD_COMP ||command == SUB_COMP || command == MULT_COMP_COMP)
	{
		if(p[2]==',')
		{
			printf("Multiple consecutive commas\n");
			return 0;
		}
		if (is_parameter(p[2])==1)
		{
			return 0;
		}
		if(extra_text(p[3])==1)
		{
			return 0;
		}
		if(command == ADD_COMP )
		{

			add_comp (which_parameter(p[0]), which_parameter(p[2]));
			return 0;
		}
		if(command == SUB_COMP)
		{
			sub_comp(which_parameter(p[0]), which_parameter(p[2]));
			return 0;
		}
		mult_comp_comp(which_parameter(p[0]), which_parameter(p[2]));
		return 0;
	}
	if(p[2]==0)
	{
		printf("Missing parameter");
		return 0;
	}
	if(p[2]==',')
	{
		printf("Multiple consecutive commas\n");
		return 0;
	}
	if(!isdigit(p[2])&&(p[2]!='-'||!isdigit(p[3])))
	{
		printf("Invalid parmeter please insert number");
		return 0;
	}
	if(command ==READ_COMP)
	{
		image= image_num(p+2);
		
		if(image[0]!=',')
		{
			printf("Missing comma");
			return 0;
		}
		if(!image[1])
		{
			printf("missing parameter %d",image[1]);
			return 0;
		}
		if(image[1]==',')
		{
			printf("Multiple consecutive commas\n");
			return 0;
		}		
		if(!isdigit(image[1])&&(image[1]!='-'||!isdigit(image[2])))
		{
			printf("Invalid parmeter please enter a number");
			return 0;
		}
		if(extra_text(*image_num(image+1))==1)
		{
			return 0;
		}
		read_comp(which_parameter(p[0]),atof(p+2),atof(image+1));
		return 0;
	}
	if(extra_text(*image_num(p+2))==1)
	{
		return 0;
	}
	if(command == MULT_COMP_REAL )
		mult_comp_real(which_parameter(p[0]),atof(p+2));
	else
		mult_comp_img(which_parameter(p[0]),atof(p+2));
	return 0;		
}




int which_command (char *p)
{
	int i=0;
	int count=0;
	while(p[i]&&p[i]!=' '&&p[i]!='\t' && p[i]!='\n')
	{
		i++;
		count++;
	}
	for(i=0;i<NUM_COMMAND;i++)
	{
		if(strlen(commands[i])==count && !strncmp(commands[i],p,count))
		{
			
			return i;
		}
	}
	return 10;	
}
void skip_spaces (char *p)
{
	int i;
	int count =0;
    	for (i = 0;p[i]; i++)
    	{
        	if (p[i]!=' ' &&p[i]!='\t'&& p[i] != '\n')
            		p[count++] = p[i]; 
	}
	p[count]='\0';
}

int extra_text(char ch)
{
	if (ch!='\n'&& ch)
	{
		printf("Extraneous text after end of command\n");
		return 1;
	}
	return 0;
}

int is_parameter(char ch)
{

	if (!ch)
	{
		printf("missing paramater\n");
		return 1;
	}
	if(ch >= 'A' && ch <= 'F')
	{
		return 0;
	}
	printf("Undefined complex variable\n");
	return 1;
}
complex *which_parameter(char x)
{
	if (x == 'A')
        	return &A;
    	if (x == 'B')
        	return &B;
    	if (x == 'C')
        	return &C;
   	if (x == 'D')
       	return &D;
  	if (x == 'E')
        	return &E;
   	if (x == 'F')
  	      	return &F;
    
	
	return NULL;
}
char *image_num(char *ch)
{
	int i=0;
	int dot;
	if (ch[0]=='-')
		i++;
	for(dot=0;isdigit(ch[i])||ch[i]=='.';i++)
	{
		if(ch[i]=='.'&&(dot||!isdigit(ch[i+1])))
			return ch+i;
		if(ch[i]=='.')
			dot = 1;
	}
	return ch+i ;
}
	

