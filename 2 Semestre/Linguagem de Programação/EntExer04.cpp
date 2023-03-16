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
	int tamanhoA, tamanhoB, tamanhoC;
	int a = 0;
	
	printf("Digite a Primeira String: ");
	gets(fraseA);
	
	printf("Digite a Segunda String: ");
	gets(fraseB);
	
	tamanhoA = strlen(fraseA);
	tamanhoB = strlen(fraseB);

	if(tamanhoA > tamanhoB){
		for(int t=0; t< tamanhoA ; t++){
			if(t < tamanhoB){
				fraseC[a] = fraseA[t];
				a++;
				fraseC[a] = fraseB[t];
				a++;
			}
			else{
				fraseC[a] = fraseA[t];
				a++;
			}
		}
	}
	else
	{
	    for(int t=0; t< tamanhoB; t++){
			if(t < tamanhoA){
				fraseC[a] = fraseA[t];
				a++;
				fraseC[a] = fraseB[t];
				a++;
			}
			else{
				fraseC[a] = fraseB[t];
				a++;
			}
		}
	}
	
	tamanhoC = strlen(fraseC);
	
	printf("A terceira String é: ");

	for(int t=0; t<tamanhoC;t++){
		printf("%c", fraseC[t]);
	}
	
	printf("\n=================================================\n");
	system("PAUSE");
	
}
