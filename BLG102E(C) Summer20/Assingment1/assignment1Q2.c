#include <stdio.h>
#include <stdbool.h>

int main()
{
	int n;
	bool flag = false;
	bool flag1;
	int num,numcont;
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
	for (int i = 1; i <= (n+1)/2; i++)   // FÄ°RST PART OF ALGROTÄ°HM
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
		num = 1;
		numcont = 1;
		flag1 = true;
		for (int k = 1; k <= 4*i-3; k++)   // to print first X X block with numbers and space between them
		{	

			if (k==1 || k==4*i-3)
			{
				printf("X");
			}
			else if (k%2==0)
			{
				printf(" ");
			}
			else{ 
				
				if (num * num == (i-1)*(i-1) && num * num != 1 && flag1 == true)
				{
					printf("%d",num);
					flag1=false;
					
				}
				else if (num * num == (i-1)*(i-1) && flag1 == false)
				{
					
					printf("%d",num-numcont);
					numcont++;
				}
				else{
					printf("%d",num );
					num++;
				}
			}
		}
		for (int x = 0; x < 2*firstspace-1; x++) // to print space between X blocks
		{
			printf(" ");
		}
		num = 1;
		numcont = 1;
		flag1 = true;
		for (int t = 1; t <= 4*i-3; t++)   // to print second X block with numbers and space between them
		{
			if (t==1 || t==4*i-3)
			{
				printf("X");
			}
			else if (t%2==0)
			{
				printf(" ");
			}
			else{ 
				
				if (num * num == (i-1)*(i-1) && num * num != 1 && flag1 == true)
				{
					printf("%d",num);
					flag1=false;
					
				}
				else if (num * num == (i-1)*(i-1) && flag1 == false)
				{
					
					printf("%d",num-numcont);
					numcont++;
				}
				else{
					printf("%d",num );
					num++;
				}
			}
		}
		for (int y = 0; y < firstspace; y++) // to print last spaces in a row
		{
			printf(" ");
		}
		printf("\n");
	}
	num = 1;
	numcont = 1;
	for (int i = 1; i < 4*n-2;i++)  // print first main full row with numbers 
	{								// 
		if (i%2!=0)
		{
			if (i==1 || i==2*n-1 || i==4*n-3)
			{
				printf("X");
			}
			else{
				if (i>1 && i<2*n-1)  // First part of main row with numbers from first X to second X 
				{	

					if (i<n-1)
					{
						printf("%d",num);
						num++;
					}
					else{
						
		 				printf("%d",num );
		 				num--;
					}
				}

				if (i>2*n-1 && i<4*n-3)   // second part of main row with numbers from second X to third X
				{
					if (i<3*n-3)
					{
						printf("%d",numcont);
						numcont++;
						
					}
					else{
						printf("%d",numcont);
						numcont--;
					}

				}
			}
		}
		else{
			printf(" ");
		}
	}
	printf("\n");
	//---------------------------------------------------------------------
	//SECOND PART OF ALGORÄ°THM
	
	for (int i = (n-1)/2; i!=1  ; i--)
	{
		int firstspace = (n-1)-(i-1)*2;
		for (int j = 0; j < firstspace; j++) // to print first space in a row
		{
			printf(" ");
		}
		num = 1;
		numcont = 1;
		flag1 = true;
		for (int k = 1; k <= 4*i-3; k++)   // to print first X block with numbers and space between them
		{
			if (k==1 || k==4*i-3)
			{
				printf("X");
			}
			else if (k%2==0)
			{
				printf(" ");
			}
			else{ 
				
				if (num * num == (i-1)*(i-1) && num * num != 1 && flag1 == true)
				{
					printf("%d",num);
					flag1=false;
					
				}
				else if (num * num == (i-1)*(i-1) && flag1 == false)
				{
					
					printf("%d",num-numcont);
					numcont++;
				}
				else{
					printf("%d",num );
					num++;
				}
			}
		}
		for (int x = 0; x < 2*firstspace-1; x++) // to print space between X blocks
		{
			printf(" ");
		}
		num = 1;
		numcont = 1;
		flag1 = true;
		for (int t = 1; t <= 4*i-3; t++)   // to print second X block  and space between them
		{
			if (t==1 || t==4*i-3)
			{
				printf("X");
			}
			else if (t%2==0)
			{
				printf(" ");
			}
			else{ 
				
				if (num * num == (i-1)*(i-1) && num * num != 1 && flag1 == true)
				{
					printf("%d",num);
					flag1=false;
					
				}
				else if (num * num == (i-1)*(i-1) && flag1 == false)
				{
					
					printf("%d",num-numcont);
					numcont++;
				}
				else{
					printf("%d",num );
					num++;
				}
			}
		}
		for (int y = 0; y < firstspace; y++) // to print last spaces in a row
		{
			printf(" ");
		}
		printf("\n");
	}
	//---------------------------------------------------------------
	//THÄ°RD PART OF ALGORÄ°THM

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
		num = 1;
		numcont = 1;
		flag1 = true;
		for (int k = 1; k <= 4*i-3; k++)   // to print first X and space between them
		{
			if (k==1 || k==4*i-3)
			{
				printf("X");
			}
			else if (k%2==0)
			{
				printf(" ");
			}
			else{ 
				
				if (num * num == (i-1)*(i-1) && num * num != 1 && flag1 == true)
				{
					printf("%d",num);
					flag1=false;
					
				}
				else if (num * num == (i-1)*(i-1) && flag1 == false)
				{
					
					printf("%d",num-numcont);
					numcont++;
				}
				else{
					printf("%d",num );
					num++;
				}
			}
		}
		for (int x = 0; x < 2*firstspace-1; x++) // to print space between X blocks
		{
			printf(" ");
		}
		num = 1;
		numcont = 1;
		flag1 = true;
		for (int t = 1; t <= 4*i-3; t++)   // to print second X with numbers and space between them
		{
			if (t==1 || t==4*i-3)
			{
				printf("X");
			}
			else if (t%2==0)
			{
				printf(" ");
			}
			else{ 
				
				if (num * num == (i-1)*(i-1) && num * num != 1 && flag1 == true)
				{
					printf("%d",num);
					flag1=false;
					
				}
				else if (num * num == (i-1)*(i-1) && flag1 == false)
				{
					
					printf("%d",num-numcont);
					numcont++;
				}
				else{
					printf("%d",num );
					num++;
				}
			}
		}
		for (int y = 0; y < firstspace; y++) // to print last spaces in a row
		{
			printf(" ");
		}
		printf("\n");
	}

	num = 1;
	numcont = 1;
	for (int i = 1; i < 4*n-2;i++)  // print first main full row with numbers
	{
		if (i%2!=0)
		{
			if (i==1 || i==2*n-1 || i==4*n-3)
			{
				printf("X");
			}
			else{
				if (i>1 && i<2*n-1)
				{	

					if (i<n-1)
					{
						printf("%d",num);
						num++;
					}
					else{
						
		 				printf("%d",num );
		 				num--;
					}
				}

				if (i>2*n-1 && i<4*n-3)
				{
					if (i<3*n-3)
					{
						printf("%d",numcont);
						numcont++;
						
					}
					else{
						printf("%d",numcont);
						numcont--;
					}

				}
			}
		}
		else{
			printf(" ");
		}
	}
	printf("\n");

	//LAST PART OF ALGORÄ°THM 

	for (int i = (n-1)/2; i!=0  ; i--)
	{
		int firstspace = (n-1)-(i-1)*2;
		for (int j = 0; j < firstspace; j++) // to print first space in a row
		{
			printf(" ");
		}
		num = 1;
		numcont = 1;
		flag1 = true;
		for (int k = 1; k <= 4*i-3; k++)   // to print X with numbers and its space
		{
			if (k==1 || k==4*i-3)
			{
				printf("X");
			}
			else if (k%2==0)
			{
				printf(" ");
			}
			else{ 
				
				if (num * num == (i-1)*(i-1) && num * num != 1 && flag1 == true)
				{
					printf("%d",num);
					flag1=false;
					
				}
				else if (num * num == (i-1)*(i-1) && flag1 == false)
				{
					
					printf("%d",num-numcont);
					numcont++;
				}
				else{
					printf("%d",num );
					num++;
				}
			}
		}
		for (int x = 0; x < 2*firstspace-1; x++) // to print space between X blocks
		{
			printf(" ");
		}
		num = 1;
		numcont = 1;
		flag1 = true;
		for (int t = 1; t <= 4*i-3; t++)   // to print X with numbers and space between them
		{
			if (t==1 || t==4*i-3)
			{
				printf("X");
			}
			else if (t%2==0)
			{
				printf(" ");
			}
			else{ 
				
				if (num * num == (i-1)*(i-1) && num * num != 1 && flag1 == true)
				{
					printf("%d",num);
					flag1=false;
					
				}
				else if (num * num == (i-1)*(i-1) && flag1 == false)
				{
					
					printf("%d",num-numcont);
					numcont++;
				}
				else{
					printf("%d",num );
					num++;
				}
			}
		}
		for (int y = 0; y < firstspace; y++) // to print last spaces in a row
		{
			printf(" ");
		}
		printf("\n");
	}
	printf("%d",--num );
	return 0;
}
	