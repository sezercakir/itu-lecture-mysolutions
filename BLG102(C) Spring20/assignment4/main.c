//gcc -std=c99 -Wall -Werror assignment4.c -o main
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* dictation(char* s,int lastlegnth){

	for(int i = 0; i < lastlegnth;i++){//to remove punctuations
        if((s[i]) < 'a' || s[i]>'z'){
            int j = i;
            while(j < lastlegnth){
                if (s[j] == '\0'){
                    break;
                }
                s[j] = s[j+1];

                j++;
            }
        }
    }
    for(int i = 0; i < lastlegnth;i++){ //to convert uppercases to lowercase
        if ((s[i])  <= 90 && (s[i]) >= 65){
            (s[i]) +=32;
        }
    }
    return s;
}
char* get_word(char* s, int n) {
	char *number;
    number = (char*)malloc(10000*sizeof(char)); // word is a string with max 100 words each word max 100 char
    char *controllerstr;
    char flag[2] = " ";
    int length = 0;
    
    controllerstr = strtok(s,flag);
    while(controllerstr != NULL){
        strcpy(number+(length*100),controllerstr);
        controllerstr = strtok(NULL,flag);
        length++;
    }

    int lastlegnth = strlen(number+(n-1)*100);
    strcpy(number+(length*100),dictation((number+(n-1)*100),lastlegnth));
    return number+(n-1)*100;
}

struct  instruction_s 
{
	int step; // line 
	int index;	//word
};
void get_sentence(char book[10000][200], struct instruction_s* instructions, int numberinstructions, char* sentence) {
	
	int firstinstindex;
	for (int i = 0; i < numberinstructions; i++)
	{	
		int temp = 0;
		for (int j = 0; j < i+1; j++)
		{
			temp += (instructions+j)->step;
			
		}
		//printf("%s",book[temp-1] );
		firstinstindex = (instructions+i)->index;
		sentence = get_word(book[temp-1],firstinstindex);
		
		printf("%s ",sentence);
	}
}

int main(int argc, char **argv[])
{
	
	char sentence[200];
	FILE *farg1;
	char book[10000][200];
	FILE *farg2;
	//farg1 = fopen(argv[1],"r"); 
	farg1 =  fopen("alice.txt","r");
	//farg2 = fopen(argv[2],"r"); 
	farg2 = fopen("1.txt","r");
	struct instruction_s* instruction = (struct instruction_s*)malloc(200*sizeof(struct instruction_s));
	int n = 0;
	int order = 0;
	while(!feof(farg2)){
		fscanf(farg2,"%c %d",&((instruction+n)->step),&((instruction+n)->index));
		n++;
	}
	
	
	while(!feof(farg1)){
        fgets(book[order],200,farg1);  //to read from book line by line  to assign book array 
        order++;
    }
   
    
    //printf("%s",book[(instruction+0)->step]);
    fclose(farg1);
    fclose(farg2);

    get_sentence(book,instruction,n-1,sentence);
    free(instruction);
	return 0;
}

//(chalis == "!" || chalis == "%"||chalis == ")" || chalis == "-"|| chalis == ";"|| chalis == "?"|| chalis == "]"||chalis == "{" || chalis == "''"|| chalis == "&"|| chalis == "*"||chalis == "." ||chalis == "<" ||chalis == "^" ||chalis == "@"||chalis == "|"||chalis == "#"||chalis == "'"||chalis == "+"||chalis == "/"||chalis == "="||chalis == "["||chalis == "_"||chalis == "}"||chalis == "$"||chalis == "("||chalis == ","||chalis == ":"||chalis == ">"||chalis == "'"||chalis == "~")