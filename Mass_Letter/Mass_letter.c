#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void append(char *file1,char *file2);
int num_recipients(char *file);
void insert_info(char *file1,char *file2,char *file3);
void replace(char *file,char *x,char *y);

/*
 * This program takes a letter and mass produces it to be directed
 * to each of the people on the mailing list.
 */
int main( int argc, char *argv[] )  
{
	if( argc != 4 )
	{
		printf("usage: ./assign4 [output.txt,letter.txt,recipients.txt]\n");
		return 0;
	}
	append(argv[1],argv[2]);
	insert_info(argv[1],argv[2],argv[3]);
	return 0;
}
void append(char *file1,char *file2)
{
	FILE *head = fopen(file1, "ab");
	FILE *tail = fopen(file2, "rb");
	if (!head || !tail)
        abort();
    char buf[BUFSIZ];
    size_t n;
    while ((n = fread(buf, 1, sizeof buf, tail)) > 0)
        if (fwrite(buf, 1, n, head) != n)
            abort();
    if (ferror(tail))
        abort();
    fprintf(head,"\n\n******************************************\n\n");
    fclose(head);
    fclose(tail);
}

int num_recipients(char *file)
{
	int line_count = 1, n_o_b_l = 0;
	FILE *fp1;
	char ch;
	fp1 = fopen(file, "r");
	while ((ch = fgetc(fp1)) != EOF)
	{
		if (ch  ==  '\n')
		{
			line_count++;
  		}
		if (ch  ==  '\n')
		{
			if ((ch = fgetc(fp1))  ==  '\n')
			{
   		     	fseek(fp1, -1, 1);
   		     	n_o_b_l++;
    	    }
   		}
	}
	int lines=line_count-n_o_b_l;
	fclose(fp1);
	return lines/5;
}

void insert_info(char *file1,char *file2,char *file3)
{
	FILE *file = fopen(file3, "r");
	int count = 0;
	if ( file != NULL )
	{
	    char line[128];
	    char temp[128];
	    while (fgets(line, sizeof line, file) != NULL) /* read a line */
	    {
	    	for(int x=0; x < sizeof line; x++)
	    	{
	    		if((line[x]=='\n')&&(count!=3))
	    			line[x]='\0';
	    	}
	        if (count<5)
	        {
	            if (count==0)
	            	replace(file1,"#N#",line);
	            if (count==1)
	            	replace(file1,"#F#",line);
	            if (count==2)
	            	replace(file1,"#L#",line);
	            if (count==3)
	            	strcpy(temp,line);
	            if (count==4)
	            {
	            	strcat(temp,line);
	            	replace(file1,"#A#",temp);
	            }
	            count++;
	        }
	        else
	        {
	        	append(file1,file2);
	            count=0;
	        }
	    }
	    fclose(file);
	}
}

void replace(char *file,char *x,char *y)
{
	FILE *input = fopen(file, "r");
	
	FILE *output = fopen("temp.txt", "w");
	
	char buffer[512];
	
	
	while (fgets(buffer, sizeof(buffer), input) != NULL)
	{
	    char *pos = strstr(buffer, x);
	    if (pos != NULL)
	    {
	        /* Allocate memory for temporary buffer */
	        char *temp = calloc(
	                strlen(buffer) - strlen(x) + strlen(y) + 1, 1);
	
	        /* Copy the text before the text to replace */
	        memcpy(temp, buffer, pos - buffer);
	
	        /* Copy in the replacement text */
	        memcpy(temp + (pos - buffer), y, strlen(y));
	
	        /* Copy the remaining text from after the replace text */
	        memcpy(temp + (pos - buffer) + strlen(y),
	                pos + strlen(x),
	                1 + strlen(buffer) - ((pos - buffer) + strlen(x)));
	
	        fputs(temp, output);
	
	        free(temp);
	    }
	    else
	        fputs(buffer, output);
	}
	
	fclose(output);
	fclose(input);
	
	/* Rename the temporary file to the original file */
	rename("temp.txt", file);
}
