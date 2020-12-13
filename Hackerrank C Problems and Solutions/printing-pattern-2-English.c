#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
int main()																			
{	

	int size,n;
	scanf("%d",&n);
	size = 2*n-1;
	for (int i = 1; i <= size; i++)
	{
		for (int j = 1; j <=size ; j++){
			int a,b,last_value;
			int n = (size+1)/2;
			a = abs(i-n);
			b = abs(j-n);
			last_value = a>b ? a : b;
			printf("%d ",last_value+1 );
		}
		printf("\n");	
	}
	return 0;
}