#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
	// 3 integers
	int int1,int2,int3;
	printf("Enter three integers:\n");
	scanf("%d %d %d",&int1,&int2,&int3);
	printf("\n%d * %d - %d = %d\n\n",int1,int2,int3,(int1*int2-int3));
	
	//one line
	printf("This is a C program\n");
	//two lines
	printf("This is\na C program\n");
	//each word separate line
	printf("This\nis\na\nC\nprogram\n");
	//each word separated by tabs
	printf("This\tis\ta\tC\tprogram\n");
	//* pattern
	printf("*****\n****\n***\n**\n*\n\n");
	
	//five digit integer spaced
	int num;
	printf("Enter a five digit integer: ");
	scanf("%d",&num);
	for (int x=10000;x>=1;x=x/10)
	{
		printf("%d ",(num/x)%10);
	}
	printf("\n\n");
	return 0;
}