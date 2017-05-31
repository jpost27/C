#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//Josh Post, CSC 344 Assignment 1
//Due Friday, September 23rd

//Random number generator.
//Options:
//-n: next number specifies the count of random numbers to generate
//-l: next number specifies the lower bounds of the numbers generated
//-u: next number specifies the upper bounds of the numbers generated
//Default options:
//Count = 10
//Lower Bounds = 1
//Upper Bounds = 100

int main(int argc, char *argv[])
{
	//Makes sure the correct number of command-line arguments are input
        if(argc%2 != 1)
	{
		printf("Usage: main -[option] [number]\n");
		return 1;
	}
	//Set the default values
	int COUNT = 10, UPPER_BOUND = 100, LOWER_BOUND = 1, x;
	//Processes the command-line arguments
	for (x = 1; x < argc; x+=2)
	{
		if (strcmp(argv[x], "-n") == 0)
			COUNT = atoi(argv[x+1]);
		else if (strcmp(argv[x], "-l") == 0)
                        LOWER_BOUND = atoi(argv[x+1]);
		else if (strcmp(argv[x], "-u") == 0)
                        UPPER_BOUND = atoi(argv[x+1]);
		else
		{
			printf("Error: improper option entry\n");
        		return 2;
		}
	}
	//Generate and print the random numbers
	for (x = 0; x < COUNT; x++)
	printf("%d\n",rand() % (UPPER_BOUND + 1 - LOWER_BOUND) + LOWER_BOUND);
        return 0;
}
