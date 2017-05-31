#include<stdio.h>
#include<math.h>
#include<string.h>
#include <stdlib.h>

int main(void)
{
	int i1,i2;
	double d1,d2;
	
	int *intptr1,*intptr2;
	double *dubptr1,*dubptr2;
	intptr1=&i1;
	intptr2=&i2;
	dubptr1=&d1;
	dubptr2=&d2;
	printf("i1 %p\ni2 %p\nd1 %p\nd2 %p\n\n",&i1,&i2,&d1,&d2);
	printf("intptr1 %p\nintptr2 %p\n %pdubptr1\n %pdubptr2\n\n",&intptr1,&intptr2,&dubptr1,&dubptr2);
	printf("intptr1 %p\nintptr2 %p\n %pdubptr1\n %pdubptr2\n\n",intptr1,intptr2,dubptr1,dubptr2);
	intptr1=intptr2;
	printf("intptr1 %p\n\n",intptr1);
	dubptr1=intptr1;
	printf("dubptr1 %p\n\n",dubptr1);
	dubptr1=(double *)intptr1;
	printf("dubptr1 %p\n\n",dubptr1);
	intptr1=NULL;
	printf("intptr1 %p\n\n",intptr1);
	printf("intptr2 %p\n\n",*intptr2);
	*intptr2=100;
	printf("i1 %d\ni2 %d\n",i1,i2);
	
	printf("intptr2+1 %p\n\n",(intptr2 + 1));
	printf("dubptr2+1 %p\n\n",(dubptr2 + 1));
	printf("intptr2+1 %p\n\n",* (intptr2 + 1));
	printf("dubptr2+1 %p\n\n",* (dubptr2 + 1));
	printf("intptr2-1 %p\n\n",(intptr2 - 1));
	printf("dubptr2-1 %p\n\n",(dubptr2 - 1));
	printf("intptr2-1 %p\n\n",* (intptr2 - 1));
	printf("intptr2-1 %p\n\n",* (dubptr2 - 1));
	intptr1=&i1;
	printf("intptr1 %p\n\n",intptr1);
	printf("intptr2 %p\n\n",intptr2);
	printf("*intptr1 %p\n\n",*intptr1);
	printf("*intptr2 %p\n\n",*intptr2);
	intptr1=&i2;
	printf("intptr1 %p\n\n",intptr1);
	printf("intptr2 %p\n\n",intptr2);
	printf("*intptr1 %p\n\n",*intptr1);
	printf("*intptr2 %p\n\n",*intptr2);
	double *ptr=(double *)malloc (sizeof (3.1416));
	printf("ptr %p\n\n",ptr);
	printf("*ptr %p\n\n",*ptr);
	free((void *)ptr);
	printf("ptr %p\n\n",ptr);
	printf("*ptr %p\n\n",*ptr);
	ptr=(double *)realloc (ptr,3.1416);
	printf("ptr %p\n\n",ptr);
	printf("*ptr %p\n\n",*ptr);
	
	printf("\n\n");
	return 0;
}