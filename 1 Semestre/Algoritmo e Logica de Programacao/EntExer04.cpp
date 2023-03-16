#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Localização
#include <conio.h>
#include <string.h> //Necessário para strlen

main(){
	setlocale(LC_ALL, "Portuguese"); //Instrução usada para configurar o idioma Português.
	
	char fraseA[10];
	char fraseB[10];
	char fraseC[20];
	int tamanhoA, tamanhoB;
	
	gets(fraseA);
	gets(fraseB);
	
	tamanhoA = strlen(fraseA);
	tamanhoB = strlen(fraseB);
	
	printf("Tamanho: %d %d\n", tamanhoA, tamanhoB);
	printf("%s\n", fraseA);
	printf("%s\n", fraseB);
	
	for(int t=0; t<tamanhoA; t++){
		printf("%c\n", fraseA[t]);
	}
	
	for(int t=0; t<tamanhoB;t++){
		printf("%c\n", fraseB[t]);
	}
	
	if(tamanhoA > tamanhoB){
		for(int t=0; t< tamanhoA; t++){
			printf("%c%c",fraseA[t], fraseB[t]);
		}
	}
	
	else{
		for(int t=0; t<tamanhoB; t++){
			if(t < tamanhoA){
				printf("%c%c",fraseA[t], fraseB[t]);
			}
			else{
				printf("%c\n", fraseB[t]);
			}
		}
	}
	
	system("PAUSE");
	
}

