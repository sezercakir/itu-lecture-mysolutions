#include <stdio.h>
#include <stdbool.h>
/*
toplam satır sayısı = 2n-1 
ilk boşluk = n-1
satırlardaki topam karakter sayısı = 4n-3
ilk başta aradaki ana boşluk sayısı = 2n-3 
en uzun = (n+1)/2
n = 7										   		first spaces   	space of btween X blocks
      X           X      				1	 	     	6 						11
    X X X       X X X    				5	 			4 						7
  X X X X X   X X X X X  				9    			2 						3
X X X X X X X X X X X X X					 			0     						=> first parth of algorithm will be completed
  X X X X X   X X X X X 				9    			2 						3
    X X X       X X X					5    			4 						7   => at thee end of this step second part of algrithm will be completed
      X           X		 				1    			6 						11
    X X X       X X X					5	 			4 						7
  X X X X X   X X X X X 				9	 			2 						3
X X X X X X X X X X X X X					 			0     						=> at the end of this step third part of algrithm will be completed
  X X X X X   X X X X X 				9	 			2 						3
    X X X       X X X					5    			4 						7
      X           X 					1    			6 						11 
X
*/
int main()
{
	int n;
	bool flag = false;
	printf("enter a non negative odd integer\n");
	while(!flag){
		scanf("%d",&n);
		if (n==1)
		{
			printf("it is not possible to built square of diamonds with input 1. please enter a number greater than 1\n");
		}
		else if (n > 0 && n%2!=0)
		{
			flag=true;
		}
		else{
			printf("enter a non negative odd integer\n");
		}

	}
	for (int i = 1; i <= (n+1)/2; i++)   // FİRST PART OF ALGROTİHM
	{	
		int firstspace = (n-1)-(i-1)*2;
		if (firstspace==0)
		{
			break;
		}
		for (int j = 0; j < firstspace; j++) // to print first space in a row
		{
			printf(" ");
		}
		for (int k = 1; k <= 4*i-3; k++)   // to print first X and space between them
		{
			if (k%2!=0)
			{
				printf("X");
			}
			else{
				printf(" ");
			}
		}
		for (int x = 0; x < 2*firstspace-1; x++) // to print space between X blocks
		{
			printf(" ");
		}
		for (int t = 1; t <= 4*i-3; t++)   // to print second X block and space between them
		{
			if (t%2!=0)
			{
				printf("X");
			}
			else{
				printf(" ");
			}
		}
		for (int y = 0; y < firstspace; y++) // to print last spaces in a row
		{
			printf(" ");
		}
		printf("\n");
	}

	for (int i = 0; i < 4*n-3;i++)  // print first main full row (X X X X....)
	{
		if (i%2==0)
		{
			printf("X");
		}
		else{
			printf(" ");
		}
	}
	printf("\n");
	//---------------------------------------------------------------------
	//SECOND PART OF ALGORİTHM

	for (int i = (n-1)/2; i!=1  ; i--)
	{
		int firstspace = (n-1)-(i-1)*2;
		for (int j = 0; j < firstspace; j++) // to print first space in a row
		{
			printf(" ");
		}
		for (int k = 1; k <= 4*i-3; k++)   // to print first X block and space between them
		{
			if (k%2!=0)
			{
				printf("X");
			}
			else{
				printf(" ");
			}
		}
		for (int x = 0; x < 2*firstspace-1; x++) // to print space between X blocks
		{
			printf(" ");
		}
		for (int t = 1; t <= 4*i-3; t++)   // to print second X block and space between them
		{
			if (t%2!=0)
			{
				printf("X");
			}
			else{
				printf(" ");
			}
		}
		for (int y = 0; y < firstspace; y++) // to print last spaces in a row
		{
			printf(" ");
		}
		printf("\n");
	}
	//---------------------------------------------------------------
	//THİRD PART OF ALGORİTHM

	for (int i = 1; i <= (n+1)/2; i++)
	{	
		int firstspace = (n-1)-(i-1)*2;
		if (firstspace==0)
		{
			break;
		}
		for (int j = 0; j < firstspace; j++) // to print first space in a row
		{
			printf(" ");
		}
		for (int k = 1; k <= 4*i-3; k++)   // to print first X and space between them
		{
			if (k%2!=0)
			{
				printf("X");
			}
			else{
				printf(" ");
			}
		}
		for (int x = 0; x < 2*firstspace-1; x++) // to print space between X blocks
		{
			printf(" ");
		}
		for (int t = 1; t <= 4*i-3; t++)   // to print second X and space between them
		{
			if (t%2!=0)
			{
				printf("X");
			}
			else{
				printf(" ");
			}
		}
		for (int y = 0; y < firstspace; y++) // to print last spaces in a row
		{
			printf(" ");
		}
		printf("\n");
	}

	for (int i = 0; i < 4*n-3;i++)  // print second main full row
	{
		if (i%2==0)
		{
			printf("X");
		}
		else{
			printf(" ");
		}
	}
	printf("\n");

	//LAST PART OF ALGORİTHM 

	for (int i = (n-1)/2; i!=0  ; i--)
	{
		int firstspace = (n-1)-(i-1)*2;
		for (int j = 0; j < firstspace; j++) // to print first space in a row
		{
			printf(" ");
		}
		for (int k = 1; k <= 4*i-3; k++)   // to print X and its space
		{
			if (k%2!=0)
			{
				printf("X");
			}
			else{
				printf(" ");
			}
		}
		for (int x = 0; x < 2*firstspace-1; x++) // to print space between X blocks
		{
			printf(" ");
		}
		for (int t = 1; t <= 4*i-3; t++)   // to print X and sapce between them
		{
			if (t%2!=0)
			{
				printf("X");
			}
			else{
				printf(" ");
			}
		}
		for (int y = 0; y < firstspace; y++) // to print last spaces in a row
		{
			printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}