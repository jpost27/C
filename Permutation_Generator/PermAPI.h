#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//Josh Post, CSC 344 Assignment 1
//Due Friday, September 23rd

//API for permutations.
//Input any String and it will recursively display
//all permutations of that String

void permutation(char *string, int x, int length);
void swap(char *x, char *y);

//**Recursion logic came from http://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
//Recursive Algorithm for printing all permutations of a String.
//Input the String, an integer of value 0, and the length of the String
void permutation (char *string, int x, int length)
{
	if (x == length)
		printf("%s\n", string);
	else
	{
		int i;
		for (i = x; i <= length; i++)
		{
			swap((string+x), (string+i));
			permutation(string, x+1, length);
			swap((string+x), (string+i));
		}
	}
}

//Simple function for swapping two characters
//Input character pointers and they will be swapped
void swap(char *x, char *y)
{
	char temp = *x;
	*x = *y;
	*y = temp;
}
