#include "mmn23.h"

int main (int argc, char *argv[])/* get arguments from user */
{
	/* decleration of variables */
	FILE *fp, *p;	
    char c[]=".c", temp[20];
    char *token;
      
    /* if there isn't 2 arguments or the program isn't c program, 
    the program will end, and error will be printed */
 	if ((argc!=2)||(strstr(argv[1],c)==NULL))
 	{
		printf("ERROR!!\nTRY AGAIN!\n");
 		exit(0);
 	}
	/* copy string from 2nd argument */
	strcpy(temp,argv[1]);
	
	token=strtok(temp,".");	/* gets the name of the user's program */
	strcat(token,".c1"); /* changing the name of the user's program to c1 program */		
	 	
 	p=fopen(argv[1], "r");/* reading program from user argument */
 	fp=fopen(token, "w");/* creating program with same name */
 	 	
 	comments(fp,p);/* erasing comments */
 	
 	fclose(fp);/* closing program with no comments */
 	
 	fp=fopen(token, "r");/* reading program with no comments */
 	
 	/* changing the name of the user's program to c2 program */
 	token[strlen(token)-1]='2';
 	
 	change(fp,token);/*creating new file - c2 program */
 	
 	fclose(fp);/* closing program with no comments */
	    		
return 0;
}
