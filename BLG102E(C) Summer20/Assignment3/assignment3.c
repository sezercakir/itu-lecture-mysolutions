#include <stdio.h>
#include <stdlib.h>


void sequence(int array1[15],int array2[15]);						// ANA OPERATOR
int maincontrolfunc(int array1num,int array2[15]);					// 1. ARRAYDEKİ ELEMANIMIZIN KARŞI ARAYDE OLUP OLMADIĞINI, VARSA NEREDE KONUMLADNIĞINI DÖNDÜRÜR
int scansecondarray(int arraynum,int array2[15],int scancontrol);	// İLK EŞLEŞEN ELEMADAN ÖNCESİNİ GÖRMEZ VE SONRASSINI "arraynum" DEĞERİNE GÖRE TARAR VE KONUMUNU DÖNDÜRÜR. YOKSA -1 DÖNDÜRÜR
void printlongestseq(int* result,int size);
int main()
{	
	int array1[15] = {1,3,4,12,3,6,7,3,5,2,5,7,2,3,4};				 
	int array2[15] = {8,3,12,4,5,6,5,8,3,3,1,1,2,3,4};
	sequence(array1,array2);								// ANA OPERATOR
	return 0;
}
void sequence(int array1[15],int array2[15]){
	int maincontrol;
	int scancontrol;
	int last_control;
	int* result = (int*)malloc(sizeof(int)*50);int m=0;int n = 0;	// YOL UUNLUKLARINI DİZİDE TUTUYORUM
	for (int i = 0; i < 15; i++)									// İLK FOR BASTIRILAN İLK ELEMANI TUTAR
	{	
		maincontrol = maincontrolfunc(array1[i],array2);			// 2. ARRAYDEKİ İLKEŞELEŞEN ELEMANIN YERİ
		if (maincontrol!=-1)
		{
			for (int j = i+1; j < 15; j++)							//2. FOR BASTIRILACAK 2. ELEMANI TUTAR
			{	
				
				scancontrol = scansecondarray(array1[j],array2,maincontrol) ;  // İLK EŞLEŞEN ELEMANDAN SONRAKİ İLK ELEMANIN 2. ARRAYDEKİ, İLK EŞLEŞEN ELEMANIN KONUMUNDAN SONRAKİ UYGUN KONUMUNU SAPTAR 
				n=0;														   // HER DEĞİŞEN YOL İÇİN YOL UUZNLUĞUNU SIFIRLIYORUM.
				//scan = scansecondarray(array1[j],array2,scan);   //  
				if ((scancontrol>maincontrol)) 								   // 2. ARRAYADEKİ KONUMLARDA,İKİNCİ EŞLEŞEN ELEMANIN  KONUMUNUN İLK EŞLEŞEN ELEMANIN KONUMUNDAN SONRA OLDUĞUNU KONTROL EDER
				{
					for (int k = j+1; k < 15;k++)							   // 1. VE 2. ELEMAN BELİRLENDİRKTEN SONRA ARRAY İKİNCİ ELEMANDAN İTİBAREN TARANMAYA BAŞLANIR
					{	
						if (k==j+1 )										   // ARRAY 2.DEN İTİBAREN TARANMADAN EVVEL ÇIKTILARI ALINIR
						{	
							printf("%d %d ",array1[i],array1[j]);
							n = n + 2;
						}
						else{												   // ANA OLAY BURDA DÖNER
							last_control = scansecondarray(array1[k],array2,scancontrol); 	// SCANCONTROL İLE FONSKİYON İÇİNDE ARRAY DARALTILARAK TARANIR
							if (last_control>scancontrol)						// 2. ARRAYDE SON TESPİT EDİLENİN KONUMUNDAN SONRA UYGUN VARSA BASILIR.
							{
								printf("%d ",array1[k] );
								scancontrol = last_control;
								n++;
							}
			
						}
					}
					printf(" - \t");
					result[m] = n;												// HER BİR AYRI YOL UZUNLUĞUNU DİZİDE TUTUYORUM
					m++;
				}
			}
			printf("\n");
		}
	}
	printf("RESULT=>\n");
	printlongestseq(result,m);
	free(result);
}

int maincontrolfunc(int array1num,int array2[15]){						// HER İLK ELEMAN İÇİN KARŞI DİZİ OLUP/OLMAMA VE KONUM KONTROLU
	
	for (int k = 0; k < 15; k++)
	{
		if (array1num==array2[k])
		{
			return k;
		}
	}
	return -1;
}	
int scansecondarray(int arraynum,int array2[15],int scancontrol){		// FONSKİYONA VERİLEN "SCANCONTROL" KONUMUNDAN İTİBAREN TARIYORUM
	for (int i = scancontrol+1; i < 15; i++)
	{
		if (arraynum==array2[i])
		{
			return i;
		}
	}
	return -1;
}
void printlongestseq(int *result,int size){
	int max = result[0];
	for (int i = 1; i<size; i++)
	{
		if (result[i] > max)
		{
			max = result[i];
		}
	}
	printf("LENGHT OF THE LONGEST COMMEN SUBSEQUENCE IS %d\n",max );
}