#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Biblioteca necessária para usar o SETLOCALE()

void armazenarValor();
void inverterValor();

float num[10];

main(){
	setlocale(LC_ALL, "Portuguese"); //Instrução usada para configurar o idioma Português.
	
	armazenarValor();
	inverterValor();
	
	system("PAUSE");
}

void armazenarValor(){
	for(int t = 0; t < 10; t++)
	{
		printf("Digite o %.0dº valor: ", t+1);
		scanf("%f", &num[t]);
	}
}

void inverterValor(){
	printf("\n---Invertendo os valores dos Vetores---\n");
	for(int t = 9; t > -1;t--)
	{
		printf("O valor do %dº Vetor é: %.0f\n", t+1,num[t]);
		
	}
	printf("\n");
}
