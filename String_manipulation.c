#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strlen (char s[]);
int my_strcpy (char *s, char t[]);
char *my_strcat(char s[], char t[]);
void my_strreverse (char *s);

int main(void)
{
	char str1[] = "123456789";
	char str2[] = "987654321";
	char str3[] = "abcdefghijkl";
	printf("String 1: %s\nString 2: %s\nString 3: %s\n\n",str1,str2,str3);
	printf("String length 1: %d\nString length 2: %d\nString length 3: %d\n\n", my_strlen(str1), my_strlen(str2), my_strlen(str3));
	char *ptr1=str1;
	char *ptr3=str3;
	printf("String copy 2->1: %d\nString copy 3->2: %d\nString 1: %s\nString 2: %s\nString 3: %s\n\n", my_strcpy (ptr1, str2),my_strcpy(str2,ptr3),str1,str2,str3);
	char str4[] = "123456789";
	char str5[] = "987654321";
	printf("String 4: %s\nString 5: %s\n",str4,str5);
	printf("Concatenation 4+5: %s \n\n",my_strcat(str4,str5));
	char str6[] = "asdfghjkl";
	char *ptr=str6;
	printf("String 6 before reverse: %s\n",str6);
	my_strreverse(ptr);
	printf("String 6 after reverse: %s\n\n",str6);
	return 0;
}

int my_strlen (char s[])
{
	char x = '\\';
	int n=1;
	while( s[n] != '\0')
	{
		n++;
	}
	return n;
}

int my_strcpy (char *s, char t[])
{
	if(my_strlen(s) >= my_strlen(t))
	{
		for(int x=0;x<my_strlen(t);x++)
		{
			s[x]=t[x];
		}
		return 1;
	}
	else
	{ 
		return -1;
	}
}


char *my_strcat(char s[], char t[])
{
	int num=(my_strlen(s)+my_strlen(t)+1);
	char new[num];
	int y=0;
	for(int x=0;x<my_strlen(s);x++)
		{
			new[y]=s[y];
			y++;
		}
	for(int z=0;z<my_strlen(t);z++)
		{
			new[y]=t[z];
			y++;
		}
	new[y]='\0';
	char *ptr=new;
	return ptr;
}

void my_strreverse (char *s)
{
	int num=my_strlen(s),x;
	char *b,*e,t;
	b = s;
	e = s;
 
 	for (x=0; x < num-1; x++)
 	{
 		e++;
 	}
 
 	for (x=0; x < num/2; x++)
 	{
 		t = *e;
 		*e = *b;
 		*b = t;
 		b++;
 		e--;
 	}
}