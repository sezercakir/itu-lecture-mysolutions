#include <stdio.h>

//in this challenga all lines of boxes must not be higher than 41 and dont use structer !!

int avaliableboxs(int array[][3],int size)
{
	for (int i = 0; i < size; i++)
	{	
		int volume=1;
		if (array[i][0]<41 && array[i][1]<41 && array[i][2]<41)
		{
			volume = volume * array[i][0] * array[i][1] *array[i][2];
		}
		else{
			continue;
		}
		printf("\n%d",volume );
	}
	return 0;
}
int main()
{	
	int n;int array[1000][3];
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{	
		for (int j = 0; j < 3; j++)
		{
			scanf("%d ",&array[i][j]);
		}
	}
	avaliableboxs(array,n);
	return 0;
}