#include <stdio.h>
#include<string.h>
#include <stdlib.h>
int main()
{

	int size;
	printf("enter size of array\n");
	scanf("%d",&size);
	int *array;
	array = (int*)malloc(size * sizeof(int));
	printf("enter values of array\n");
	int sum=0;
	for (int i = 0; i < size; i++)
	{
		scanf("%d",&array[i]);
		sum = sum + array[i];
	}
	int sum=0;
	printf("%d\n",sum );
	return 0;
} 