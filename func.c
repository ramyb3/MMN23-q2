#include "mmn23.h"

/* gets program from user argument and creating same program with no comments */
void comments(FILE *fp, FILE *p)
{	
	int c, slash=47, asterisk=42;	
 	/* 42=='*' in ascii */
 	/* 47=='/' in ascii */
 	
	while(p!=NULL)/* check if the program from user didn't end */
	{
		c=fgetc(p);	/* gets next char */
				
		if(c!=slash&&c!=EOF)/* check if there isn't '/' or program didn't end */		
		fprintf(fp, "%c", c);/* writing to new file with no comments */
	
		if(c==slash) /* check if there's '/' - if comment start */
		{								
			c=fgetc(p); /* gets next char */
						
			if(c!=asterisk) /* check if there isn't '*' after '/' */
			fprintf(fp, "%c%c", slash, c);/* writing to new file with no comments */			
			
			if(c==asterisk) /* check if there's '*' after '/' */
			{
				c=fgetc(p); /* gets next char */
				
				while(c!=asterisk) /* check if there isn't '*' after '*' */
				{
					c=fgetc(p); /* gets next char */
				
					if(c==asterisk) /* check if there's '*' */
					{
						c=fgetc(p);	/* gets next char */					
							
						if(c==slash) /* check if there's '/' after '*' - end of comment */
						{
							c=fgetc(p);	/* gets next char */						
							fprintf(fp, "%c", c); /* writing to new file with no comments */
							break;/*end nested loop*/
						}
					}
				}
			
				while(c==asterisk) /* check if there's '*' */
				c=fgetc(p);	/* gets next char */				
			}			
		}
		
		if(feof(p)) /* check if the user program ended */
		break;
    }
        	
	fclose(p); /* closing program from user */
}

/* gets program with no comments and creating same program with no #include ".h" files */
void change(FILE *fp, char *token)
{
	/* decleration of variables */
	char s[max], str[max], header[]="#include";
	char *temp;

	FILE *p, *fd;
	
	fd=fopen(token,"w");/* creating program with same name in c2 type program */
	
	while(1)/* endless loop */
	{			
		fgets(s, max, fp);/* gets the line from program with no comments */
		
		if(feof(fp)) /* check if the program with no comments ended */
		break;
		
		/* check if there's header file in this line from no comments program */	   		
		if(strstr(s,header)!=NULL)
		{	
			/* temp gets the name of the header file */
			temp=strtok(s,"\"");
			temp=strtok(NULL,"\"");
		
			p=fopen(temp,"r"); /* reading the header file */			
			
			while(1)/* endless loop */
			{				
				fgets(str,max,p); /* gets the line from header file */
			
				if(feof(p)) /* check if the header file ended */
				break;
										
				fprintf(fd,"%s",str); /* writing to new file .c2 type program */	
			}		
		}			
		/* check if there isn't header file in this line from no comments program */
		if(strstr(s,header)==NULL)				
		fprintf(fd,"%s",s);	/* writing to new file .c2 type program */
	}
	
	/* closing programs with .c2 type and header files of the user */
	fclose(p);
	fclose(fd);
}
