#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Escreva um programa que leia N inteiros (definidos pelo usu�rio) 
//armazenando-os numa mem�ria dinamicamente alocada. 
//Em seguida mostre quantos dos n�meros s�o pares e quantos s�o �mpares.

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int qtde, *numero, par = 0, impar = 0;
	
	//criando a v�ri�vel de quantidade
	printf("Digite a qtde de n�meros que ser�o registrados: ");
	scanf("%i", &qtde);
	
	numero = (int *) malloc(qtde * sizeof(int));
	
	//inserindo os n�meros
	printf("Digite os n�meros, um em cada linha:\n");
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
	
	printf("Quantidade de n�meros\nPares: %i\nImpares: %i\n", par, impar);
	
	free(numero);
	
	return 0;
	
}
