#include <stdio.h>
#include <stdlib.h>
int max(int array[],int size,int k)
{	
	int maxvalue=0;
	for (int i = 0; i < size; i++)
	{	
		if (array[i] > maxvalue && array[i]<k)
		{
			maxvalue = array[i];
		}
	}
	return maxvalue;
}
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	int size = (n-1)*(n)/2;
	int *arrayand = malloc(size * sizeof(int));
	int *arrayor = malloc(size * sizeof(int));
	int *arrayxor = malloc(size * sizeof(int));
	int mt = 0;
	for (int i=1;i < n;i++)
	{	
		int a =mt;
		for (int j = i+1; j < n+1; j++)
		{	
			arrayand[a]= i&j;
			arrayor[a]=i|j;
			arrayxor[a]=i^j;
			a++;
		}
		mt = a;
	}
	int valueofand = max(arrayand,size,k);
	int valueofor = max(arrayor,size,k);
	int valueofxor = max(arrayxor,size,k);
	printf("%d\n%d\n%d\n",valueofand,valueofor,valueofxor );
	return 0;
}










































/*int main()
{	

	int *array = malloc(5*sizeof(int));
	array[0]= 1&2;array[1]=1&3;array[2]=1&4;array[3]=1&5;array[4]=2&3;
	int value = max(array,5,4);
	printf("%d\n",value );
	return 0;
}
void setarray(int n,int k)
{	
	int size = (n-1)*(n)/2;
	int *arrayand = malloc(size * sizeof(int));
	int *arrayor = malloc(size * sizeof(int));
	int *arrayxor = malloc(size * sizeof(int));
	int i = 1;int forcontroller = 2;
	while(i<size)
	{

	}
	int valueofand = max(arrayand,size,k);
	int valueofor = max(arrayxor,size,k);
	int valueofxor = max(arrayxor,size,k);
	printf("%d\n%d\n%d\n",valueofand,valueofor,valueofxor );
}*/