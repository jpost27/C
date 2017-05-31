#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"PermAPI.h"

//Josh Post, CSC 344 Assignment 1
//Due Friday, September 23rd

//Takes a command-line argument in the form of a String and inputs 
//it into the Permutation API

int main(int argc, char *argv[])
{
        if(argc != 2)
	{
		printf("Usage: main [string]");
		return 1;
	}
	char* string = argv[1];
        int n = strlen(string);
        permutation(string,0,n-1);
        return 0;
}
