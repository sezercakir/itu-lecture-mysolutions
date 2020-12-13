#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
//gcc -std=c99 -Wall -Werror assignment2b.c -o main
// hocam ssh'ta son sutün diğerine bitişik geliyor.sanırım ssh'ın arayüz sıkıntısı olabilir. 
int global=0;
void mainoperator(int board_size,int x_location,int y_location,int x_board, int y_board,int size, int (*array)[size]);

void printMatrix(int coloumn, int (*array)[coloumn]);

int main(){
	
	
	int board_size;
	printf("enter size of array\n");
	scanf("%d",&board_size);
	int x,y;
	global=0;
	printf("enter location of hole into the board\n");
	scanf("%d %d",&x,&y);
	  	

	int array[board_size][board_size];
	for (int i = 0; i < board_size; ++i){
		for (int j = 0; j < board_size; ++j){
			array[i][j]=0;
		}
	}
	array[x][y]=-1; 
	mainoperator(board_size,x,y,0,0,board_size,array); 
	printMatrix(board_size,array); 

	return 0;
}

void mainoperator(int board_size,int x_location,int y_location,int x_board, int y_board,int size, int (*array)[size]){ 
	
	if(board_size==2){
		global++;
		
		
		for (int i = x_board; i < (x_board+board_size); ++i)   // iki for döngüsü her bir tramino fonskyionu için 4e bölünmüş karelerde boşluk alan hariç diğer kısımları sayı ile dolduruyor.								
		{
			for (int j = y_board; j< (y_board+board_size); ++j)
			{
				if(!(i==x_location && j==y_location)){
					array[i][j]=global;
				}
			}
		}
		return;

	}
	global++;
	int half_size=board_size/2,x_center,y_center;
	int x_up_right;
	int y_up_right;
	int x_up_left;
	int y_up_left;
	int x_low_right;
	int y_low_right;
	int x_low_left;
	int y_low_left;
	x_center= x_board + half_size;
	y_center= y_board + half_size;
	// 4 if control points divides four to wall. 
	if(x_location<x_center && y_location< y_center){ 
		
		array[x_center-1][y_center]=array[x_center][y_center-1]=array[x_center][y_center]=global; // en soldaki karenin en sağının etrafına 1 değerini atıyorum.
		
		x_up_left = x_location;
		y_up_left = y_location;

		x_up_right =x_center-1;
		y_up_right =y_center;

		x_low_left =x_center; 
		y_low_left =y_center-1;

		x_low_right =x_center; 
		y_low_right =y_center;
	
	//ikinci kare içi
	}else if(x_location<x_center && y_location>=y_center){ // ikinci dörtlükte ise boşluk. diğer 3 karenin boşluklu kareyekomşu kenarlarına 1 değerini atıyorum.
		
		array[x_center-1][y_center-1]= global;array[x_center][y_center-1]=global;array[x_center][y_center]=global;

		x_up_left =x_center-1;
		y_up_left =y_center-1;

		x_up_right =x_location;
		y_up_right =y_location;
														// bölünmüş kare içindeki aray elemanalarını yeniden konumlandırma
		x_low_left = x_center;
		y_low_left = y_center-1;

		x_low_right = x_center ;
		y_low_right = y_center;

	// üçüncü kare içi
	}else if(x_location>=x_center && y_location<y_center){ 
		
		array[x_center-1][y_center-1]=global;array[x_center-1][y_center]=global;array[x_center][y_center]=global;

		x_up_left=x_center-1;
		y_up_left=y_center-1;

		x_up_right=x_center-1; 
		y_up_right=y_center;
														// bölünmüş kare içindeki aray elemanalarını yeniden konumlandırma
		x_low_left=x_location; 
		y_low_left=y_location;

		x_low_right=x_center; 
		y_low_right=y_center;

	// dördüncü kare içi
	}else if(x_location>=x_center && y_location>=y_center){ 	

		array[x_center-1][y_center-1]=array[x_center-1][y_center]=array[x_center][y_center-1]=global;
		
		x_up_right = x_center-1;
		y_up_right = y_center;
		
		x_up_left = x_center-1;
		y_up_left = y_center-1;
													// bölünmüş kare içindeki aray elemanalarını yeniden konumlandırma
		x_low_right=x_location;
		y_low_right=y_location;
		
		x_low_left=x_center;
		y_low_left=y_center-1;
		

	}

	
	mainoperator(half_size,x_up_left, y_up_left, x_board,y_board       ,size,array); // recursive döngü sol üst kare için ve diğer dördü diğer bölgeler için recursive

	
	mainoperator(half_size,x_up_right, y_up_right, x_board,y_board+half_size       ,size,array);  

	
	mainoperator(half_size,x_low_left, y_low_left, x_board+half_size,y_board      ,size,array); 

	
	mainoperator(half_size,x_low_right, y_low_right, x_board+half_size,y_board+half_size     ,size,array); 

}
void printMatrix(int coloumn, int (*array)[coloumn]){ 
	
	for (int i = 0; i < coloumn; ++i)
	{
		for (int j = 0; j < coloumn; ++j)
			{	
				if(array[i][j]==(-1)){
					printf("X\t");
				}else{
					printf("%d\t",array[i][j]);
				}
				
			}
		printf("\n");		
	}
	printf("\n");
}