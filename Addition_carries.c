#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int num_carry(int x,int y);

int main(void)
{
	printf("\n\n******* Enter any two positive integers and this *******\n");
	printf("******* program will tell you the amount of      *******\n");
	printf("******* \"carries\" needed for  addition as well   *******\n");
	printf("******* as the sum of the two numbers. Enter 0   *******\n");
	printf("******* for the first integer to quit.           *******\n\n");
	while(1)
	{
		int num1,num2;
		printf("Enter first number: ");
		scanf("%d",&num1);
		if(num1==0)break;
		printf("Enter second number: ");
		scanf("%d",&num2);
		printf("\nIt would take %d carry operations to add these two integers.",num_carry(num1,num2));
		printf("\nThe sum of %d and %d is: %d\n\n",num1,num2,(num1+num2));
	}
	return 0;
}

int num_carry(int x,int y)
{
	int count=0,carry=0,xlength=1,ylength=1,temp;
	temp=x;
	while(temp>1)
	{
		temp=temp/10;
		xlength++;
	}
	temp=y;
	while(temp>1)
	{
		temp=temp/10;
		ylength++;
	}
	if (xlength>=ylength)
	{
		int num=0,mod;
		while (num<xlength)
		{
			mod=(x%10)+(y%10)+carry;
			if(mod>=10)
			{
				count++;
				carry=mod/10;
			}
			else
			{
				carry=0;
			}
			y=y/10;
			x=x/10;
			num++;
		}
	}
	if (ylength>=xlength)
	{
		int num=0,mod;
		while (num<ylength)
		{
			mod=(x%10)+(y%10)+carry;
			if(mod>=10)
			{
				count++;
				carry=mod/10;
			}
			else
			{
				carry=0;
			}
			y=y/10;
			x=x/10;
			num++;
		}
	}
	return count;
}