#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

/*
	ALGORITHM:
	-you can catch on algorithm better with analyze park and parked cars matrices printed. but I try to explain.
	-firstly, I need zero 2D matrix to see and move clearly. (53-60)
	-secondly, free park slod value is 0, parked slot value is 1. notice that it cannot be parked more than one car in 1 slot.
	-int realcarnumber value controls it.It's higly important for last steps.
	-then, I need another 2D array to calculate distance between free and full park slot.array[][](36)
	-main algorithm is(100-132):
	** 1th for loop keeps free parking slot and keeps it's cordinate i and j, 
	when park slot is not free 1th for loop assign it value as 1 into array[i][j].1 means that there is a car in here.

	** 2th loop checks distance with ith row jth column.key factor is storagearray. for each ith row jth column, all free slot 
	are scaaned and these values are stored in storagearray. then, min value is returned with in bublefunc for all ith row jth column.

	-lastly, array matrix consists of distance value. last step is finding max value with min x cord,if x cords are equal min y cord. 
	
*/

int countarrayfunc(int i,int j,int k,int l){
	int value = abs(i-k)+abs(j-l);
	return value;
}	
int bubblefunc(int bublearray[],int carssize){
	int min =bublearray[0];
	for (int i = 0; i < carssize; i++)
	{
		if (bublearray[i]<min)
		{
			min = bublearray[i];
		}
	}
	return min;
}
int main()
{
	int size;int parkarea[50][50];int cars;int array[50][50];
	while(true){
		printf("Size: ");
		scanf("%d",&size);
		if (size<51)
		{
			break;
		}
		printf("Size must be between 50 and 1\n");
	}
	printf("Cars: ");
	scanf("%d",&cars);
	int realcarnumber = cars;
	if (cars == size * size)
	{
		printf("Best Slot Found In: 0 0\n");
	}
	else if(cars == 0)
	{
		printf("Best Slot Found In: 1 1\n");
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{	
				
				parkarea[i][j]= 0;
				array[i][j]=0;
			}
		}
		int xcor,ycor;int outofslote = 0;
		for (int i = 0; i < cars; i++)
		{	
			printf("Locations: ");
			scanf("%d %d",&xcor,&ycor);
			if (xcor>size || ycor>size)
			{	
				outofslote = 1;
				break;
			}
			else
			{		
				if (parkarea[size-ycor][xcor-1] == 1)
				{
					realcarnumber--;
				}
				else{
					parkarea[size-ycor][xcor-1] = 1;
				}
			}
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				printf("%d ",parkarea[i][j]);
			}
			printf("\n");
		}
		if (outofslote==1)
		{
			printf("Best Slot Found In: %d %d\n",size,size);
		}
		else
		{
			for (int i = size-1; i > -1; i--)
			{	
				for (int j = 0; j < size; j++)
				{	
					if (parkarea[i][j]==0)
					{	
						int storagearray[50];int carf = realcarnumber;
						for (int k = size-1; k > -1 ; k--)
						{
							for (int l = 0; l < size ; l++)
							{
								if (parkarea[k][l]==1)
								{
									int temp = countarrayfunc(i,j,k,l);
									storagearray[carf-1] = temp;
									carf--;
		
								}
								else{
									continue;
								}
							}
						}
						int bublesort = bubblefunc(storagearray,realcarnumber);
						array[i][j] = bublesort;
					}
					else{
						array[i][j]=0;
					}	
				}
			}
			printf("\n");
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					printf("%d ",array[i][j] );
				}
				printf("\n");
			}
			int max = 0;
			for (int i = 0; i < size; i++)
			{	
				for (int j = 0; j < size; j++)
				{	
					if (array[i][j]>max)
					{
						max = array[i][j];
					}
				}
			}
			int controller1; int controller2;int lastx;int lasty;int tempcontroller1 = 0;int ctrl=0;
			for (int i = size-1; i > -1; i--)
			{	tempcontroller1++;
				int tempcontroller2 = 0;
				for (int j = 0; j < size; j++)
				{	
					tempcontroller2++;
					if (array[i][j]==max && ctrl==0)
					{	
						controller2 = tempcontroller2;
						controller1 = tempcontroller1;ctrl++;
						lastx = controller2;lasty = controller1;
						continue;
					}
					if(array[i][j]==max && ctrl > 0){
						int controller2test = tempcontroller2;int controller1test = tempcontroller1;
						int lastxcheck = controller2test;int lastycheck = controller1test;
						if (lastxcheck<lastx)
						{
							lastx = lastxcheck; lasty= lastycheck;
						}
					}
				}
			}
			printf("Best Slot Found In: %d %d\n",lastx,lasty);		
		}
	}
	return 0;
}