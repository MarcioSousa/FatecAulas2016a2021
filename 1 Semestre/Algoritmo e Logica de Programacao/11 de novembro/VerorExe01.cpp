#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Biblioteca necess�ria para usar o SETLOCALE()

void armazenarValor();
void inverterValor();

float num[10];

main(){
	setlocale(LC_ALL, "Portuguese"); //Instru��o usada para configurar o idioma Portugu�s.
	
	armazenarValor();
	inverterValor();
	
	system("PAUSE");
}

void armazenarValor(){
	for(int t = 0; t < 10; t++)
	{
		printf("Digite o %.0d� valor: ", t+1);
		scanf("%f", &num[t]);
	}
}

void inverterValor(){
	printf("\n---Invertendo os valores dos Vetores---\n");
	for(int t = 9; t > -1;t--)
	{
		printf("O valor do %d� Vetor �: %.0f\n", t+1,num[t]);
		
	}
	printf("\n");
}
