#include<stdio.h>
#include<math.h>
#include<string.h>
#include <stdlib.h>

int main(void)
{
	while (1)
	{
		char n[10];
		char i;
		char o;
		printf("\nBase of integer: Enter b for binary, d for decimal, h for hexadecimal or o for octal: ");
		scanf("%c", &i);
		getchar();
		while (1)
		{
			if((i=='d') || (i=='o') || (i=='h') || (i=='b'))
			{
				printf("Enter the number: ");
				scanf("%s", n);
				getchar();
				break;
			}
			else
			{
				printf("\nImproper response.\n");
				printf("Base of integer: Enter b for binary, d for decimal, h for hexadecimal or o for octal: ");
				scanf("%c", &i);
				getchar();
			}
		}
		o='p';
		while(1)
		{
			if ((o=='d')||(o=='h')||(o=='o'))
				{break;}
			else
			{
				printf ("Enter the base of the output(d, h, or o): ");
				scanf ("%c", &o);
				getchar();
			}
		}
		int num1=0,num2=0;
		if(i=='d')
		{
			num1=atoi(n);
		}
		else if(i=='b')
		{
			int z;
			for (int x=(strlen(n) - 1);x>=0;x--)
			{
				z = (n[x] - '0');
				z = z * pow(2,(strlen(n) - (x+1)));
				num1=num1+z;
			}
		}
		else if(i=='h')
		{
			int z;
			for (int x=(strlen(n) - 1);x>=0;x--)
			{
				if ((n[x]-'0')<10) z = (n[x] - '0');
				else if ((n[x])=='a') z = 10;
				else if ((n[x])=='b') z = 11;
				else if ((n[x])=='c') z = 12;
				else if ((n[x])=='d') z = 13;
				else if ((n[x])=='e') z = 14;
				else if ((n[x])=='f') z = 15;
				z = z * pow(16,(strlen(n) - (x+1)));
				num1=num1+z;
			}
		}
		else if(i=='o')
		{
			int z;
			for (int x=(strlen(n) - 1);x>=0;x--)
			{
				z = (n[x] - '0');
				z = z * pow(8,(strlen(n) - (x+1)));
				num1=num1+z;
			}
		}
		else {}
		if (o=='d')
		{
			printf("The integer %s in decimal is %d",n,num1);
		}
		else if (o=='o')
		{
			printf("The integer %s in octal is %o",n,num1);
		}
		else if (o=='h')
		{
			printf("The integer %s in hexadecimal is %04x",n,num1);
		}
		else {}
		printf("\n\nDo you wish to do another?(Y or N): ");
		char l;
		scanf("%c", &l);
		getchar();
		if ((l!='y')&&(l!='Y'))
		{
			break;
		}
	}
	return 0;
}
