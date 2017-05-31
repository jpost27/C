#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(void)
{
	//input strings
	char str[128],full[128];
	printf("Enter any input from the keyboard. To end input z\n\n");
	scanf("%s",str);
	getchar();
	while(strcmp(str,"z") != 0)
	{
		strcat(full,str);
		strcat(full,"\n");
		scanf("%s",str);
		getchar();
	}
	strcat(full,"\n");
	//tally up stats
	int upper=0,lower=0,digits=0,white=0,x;
	for(x=0;x<strlen(full);x++)
	{
		if(isupper(full[x]) != 0)
		{
			upper++;
		}
		if(islower(full[x]) != 0)
		{
			lower++;
		}
		if(isdigit(full[x]) != 0)
		{
			digits++;
		}
		if (isspace(full[x]) != 0)
		{
			printf("%c1",x);
			white++;
		}	
	}
	//output statistics
	printf("\n\n%s\n",full);
	printf("The number of whitespace characters is: %d",white);
	printf("\nThe number of digits is: %d",digits);
	printf("\nThe number of lowercase characters is: %d",lower);
	printf("\nThe number of uppercase characters is: %d",upper);
	printf("\n\nGoodbye\n");
	return 0;
}