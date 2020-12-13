#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
// multiplicand, multiplier, and product
//gcc -std=c99 -Wall -Werror lab.c -o main
int distinctinteger(int sayi,int multipliersayi,int productsayi);
int* digitsfunc(int t,int size);

int main()
{
	
	int number,digits;
	char input[15];
	printf("select one of them; multiplicand,multiplier or product \n");		//multiplicand,multiplier,product
	scanf("%s",input);  
	int row;
	int solutionnum = 0;
	int productsayi = 0;
	int* sayic;						
	int* multipliersayic;
	int* productsayic;
	
	
	if ( strcmp(input,"multiplicand") == 0)
	{
		printf("select which digit; enter 1 for units, enter 2 for tens, enter 3 for hundreds\n");
		scanf("%d",&digits);
		printf("determine a number between 0-9\n");
		scanf("%d",&number);
		row = 1;
	}
	else if (strcmp(input,"multiplier")==0)
	{
		printf("select which digit;  enter 1 for units, enter 2 for tens\n");
		scanf("%d",&digits);
		printf("determine a number between 0-9\n");
		scanf("%d",&number);
		row = 2;
	}
	else if (strcmp(input,"product")==0)
	{
		printf("select which digit; enter 1 for units, enter 2 for tens, enter 3 for hundreds, enter 4 for thousands, enter 5 for ten thousands\n");
		scanf("%d",&digits);
		printf("determine a number between 0-9\n");
		scanf("%d",&number);
		row = 3;
	}
	else{
		printf("wrong input.enter again\n");
		return EXIT_FAILURE;
	}
	//FIRST PART OF ALGORITHM. AND MAIN IDEA.
	if (row==1)
	{	
		for (int sayi = 100; sayi < 1000; sayi++)
		{	
			
			for (int multipliersayi = 12; multipliersayi < 100;multipliersayi++)   // two for loop multiple all integer that is between 100-1000
			{
				productsayi = sayi*multipliersayi;
				
				if (productsayi>10000)
				{	
					sayic = digitsfunc(sayi,3);										// it is generated int array to control sayic[3-digits]==number
   					int sum = distinctinteger(sayi,multipliersayi,productsayi);     // 10 distinc integer means that every integer number is used once
    				if ((sayic[3-digits] == number) && (sum == 10)  )
    				{
    					printf("one of the solution is %d multiple %d equal %d \n",sayi,multipliersayi,productsayi );
    					solutionnum++;
    				}
				}
				
			}	
		}
		if (solutionnum==0)
		{
			printf("there is no solution\n");
		}
	}
	// SECOND PART OF ALGORITHM. IT IS SİMİLAR FIRST ONE. 
	else if (row == 2)								
	{
		for (int sayi = 100; sayi < 1000; sayi++)
		{	
			
			for (int multipliersayi = 12; multipliersayi < 100;multipliersayi++)
			{
				productsayi = sayi*multipliersayi;
				
				if (productsayi>10000)
				{	
					multipliersayic = digitsfunc(multipliersayi,2);
				
   					int sum = distinctinteger(sayi,multipliersayi,productsayi);
					//int sum = (distinccharacter(sayi,3) + distinccharacter(multipliersayi,2) + distinccharacter(productsayi,5));
					//printf("sum %d\n\n",sum );
    				if ((multipliersayic[2-digits] == number) && (sum == 10)  )
    				{
    					printf("one of the solution is %d multiple %d equal %d \n",sayi,multipliersayi,productsayi );
    					solutionnum++;	
    				}	
				}	
			}
				
		}
		if (solutionnum==0)
		{
			printf("there is no solution\n");
		}

	}
	//THIRD PART OF ALGORITHM. IT IS SİMİLAR FIRST ONE.
	else if(row==3)
	{
		for (int sayi = 100; sayi < 1000; sayi++)
		{	
			
			for (int multipliersayi = 12; multipliersayi < 100;multipliersayi++)
			{
				productsayi = sayi*multipliersayi;
				
				if (productsayi>10000)
				{	
					
    				
					productsayic = digitsfunc(productsayi,5);
				
   					int sum = distinctinteger(sayi,multipliersayi,productsayi);
					//int sum = (distinccharacter(sayi,3) + distinccharacter(multipliersayi,2) + distinccharacter(productsayi,5));
					//printf("sum %d\n\n",sum );
    				if ((productsayic[5-digits] == number) && (sum == 10)  )
    				{
    					printf("one of the solution is %d X %d = %d \n",sayi,multipliersayi,productsayi );
    					solutionnum++;
    				}
				}
			}		
		}
		if (solutionnum==0)
		{
			printf("there is no solution\n");
		}
	}
	return 0;
}
int distinctinteger(int sayi,int multipliersayi,int productsayi) // distinc integer into multiplicand,multiper and product											
{																 // my aim to find 10 distinct integer into sum of total digit number of multiplicand,multiper and product	  
	int* arr = malloc(sizeof(int)*10);							 // int* arr => it is built to detect 10 distinct int
   	int i=9;
   	int a;
   	int number=1;
   	while(sayi!=0){
   		a = sayi%10;
   		arr[i] = a;
   		if (i==6)
   		{														//==>> this while add integers of multiplicand to the arr that have 10 element
   			break;
   		}
   		sayi = sayi/10;
   		i--;
   	}
   	while(multipliersayi!=0){
   		a = multipliersayi%10;
   		arr[i] = a;												// ==>>  this while add integers of multiplier to the arr that have 10 element
   		if (i==4)
   		{
   			break;
   		}
   		multipliersayi = multipliersayi/10;
   		i--;
   	}
   	while(productsayi!=0){
   		a = productsayi%10;
   		arr[i] = a;												// ==>> this while add integers of products to the arr that have 10 element
   		if (i==0)
   		{
   			break;					
   		}
   		productsayi = productsayi/10;
   		i--;
   	}
	for (int i = 1; i < 10; i++)
	{	
		for (int j = i-1; j > -1; j--)
		{
			if (arr[i]==arr[j])
			{													// ==>> these for loops detect how many distinct integer exist into the rray
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
	
	return number;
}

int* digitsfunc(int t,int size){
   	int* arr = malloc(sizeof(int)*size);
   	int i=size-1;
   	int a;
   	while(t!=0){
   		a = t%10;
   		arr[i] = a;
   		if (i==0)												// this funtion convert to integer to array. it controls whether integer that is send by user is part of solution 
   		{														// X7X multiple XX = XXXXX. digitsfunc provide controlling for 7.
   			break;
   		}
   		t = t/10;
   		i--;
   	}
   	return arr;
}