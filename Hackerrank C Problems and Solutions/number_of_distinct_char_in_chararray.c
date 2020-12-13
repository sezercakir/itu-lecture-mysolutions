#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//In this example, we try to find number of distinct character in char array.
/*
	ALGORITHM:
	- we scan condition that is unwanted BACKWARDS in second forloop with j= i-1 and j--.
*/

int main()
{	
	char *a = "xyzbadddaafgggc";
	int number = 1;
	for (int i = 1; i < strlen(a); i++)
	{	
		for (int j = i-1; j > -1; j--)
		{
			if (a[i]==a[j])
			{
				break;
			}
			else{
				if (j==0)
				{
					number++;
				}
			}
		}
	}
	printf("%d\n",number );
}