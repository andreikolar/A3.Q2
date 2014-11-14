#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

main(){
	char prompt[50]="Andrei's Shell!!";
	int z;
	char userInput[150];
	for (z=0; z<150; z++){
		userInput[z]='\0';
	}
	int size;
	int counter;
	char quitArrL[]="quit";
	char quitArrC[]="QUIT";
	char setArrL[]="set prompt";
	char setArrC[]="SET PROMPT";
	int check;
	int looper=1;
	int sizeOfPrompt;
	
	while (looper==1){
		memset(userInput,'\0',150);
		sizeOfPrompt=strlen(prompt);
		printf("%s ",prompt);
		fgets(userInput,sizeof(userInput),stdin);
		size=strlen(userInput);
		size-=1;

		if (size==4){
			check=1;
			for (z=0; z<size; z++){
				if (userInput[z] != quitArrL[z] && userInput[z] != quitArrC[z]){
					check=0;
				}
			}
			if (check==1){
				exit(0);
			}else{
				system(userInput);
			}
		}else if(size>=10){
			check=1;
			for (z=0; z<10;z++){
				if (userInput[z] != setArrL[z] && userInput[z] != setArrC[z]){
					check=0;
				}
			}
			if (check == 1){
				memset(prompt,'\0',sizeOfPrompt);
				size +=1;
				counter=0;
				for (z=11; z<size; z++){
					prompt[counter]=userInput[z];
					counter +=1;
				}
			}else{
				system(userInput);
			}
		}else{
			system(userInput); 
		}
	}

}	
