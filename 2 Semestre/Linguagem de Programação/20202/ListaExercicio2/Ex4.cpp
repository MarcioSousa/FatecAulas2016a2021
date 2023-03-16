#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Escreva um programa que leia N inteiros (definidos pelo usuário) 
//armazenando-os numa memória dinamicamente alocada. 
//Em seguida mostre quantos dos números são pares e quantos são ímpares.

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int qtde, *numero, par = 0, impar = 0;
	
	//criando a váriável de quantidade
	printf("Digite a qtde de números que serão registrados: ");
	scanf("%i", &qtde);
	
	numero = (int *) malloc(qtde * sizeof(int));
	
	//inserindo os números
	printf("Digite os números, um em cada linha:\n");
	for(int t = 0; t < qtde; t++){
		scanf("%i", &numero[t]);
	}
	
	//verificando a quantidade de par e impar
	for(int t = 0; t < qtde; t++){
		if(numero[t]%2 == 0){
			par++;
		}else{
			impar++;
		}
	}
	
	printf("Quantidade de números\nPares: %i\nImpares: %i\n", par, impar);
	
	free(numero);
	
	return 0;
	
}
