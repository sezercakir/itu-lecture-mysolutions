#include <stdio.h>
#include <stdlib.h>
//gcc -std=c99 -Wall -Werror a.c -o main

int points(int intmain, char dartloc){
	switch (dartloc)
	{
		case 'S' : return (intmain*1);break;
		case 'D' : return (intmain*2);break;
		case 'T' : return (intmain*3);break;
		case 'O' : intmain=1;return (intmain*25);break;
		case 'I' : intmain=1;return (intmain*50);break;
	}
	return 0;
}
void game(int targetvalue)
{	int i = targetvalue;int controller1=0;
	for (;i != 0; )
	{	
		int intvalue;char s;
		printf("Throw: ");
		scanf("%d %c",&intvalue,&s);
		if (controller1==0)
		{	
			if (s!='D')
			{
				printf("Points: %d\n",i);
				continue;
			}
			else{
				printf("Points: %d\n",(i - points(intvalue,s)) );
				i = i - points(intvalue,s);
				controller1++;
				continue;
			}
		}
		else
		{
			i = i - points(intvalue,s);
			if (i>0)
			{
				printf("Points: %d\n",i);
			}
			if (i < 0)
			{
				i = i + points(intvalue,s);
				printf("Points: %d\n",i);
				continue;
			}
			if (i == 0)
			{
				if (s == 'D')
				{
					printf("Points: 0\n");
					break;
				}
				else
				{
					i = i + points(intvalue,s);
					printf("Points: %d\n", i);
					continue;
				}
			}
		}
	}
}
int main()
{
	int targetvalue;
	printf("Target: ");
	scanf("%d",&targetvalue);
	game(targetvalue);
	return 0;
}