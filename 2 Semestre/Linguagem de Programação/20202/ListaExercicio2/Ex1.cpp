#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Faça um programa que leia o tamanho de um vetor de inteiros e 
//reserve dinamicamente memória para esse vetor. 
//Em seguida, leia os elementos desse vetor, 
//imprima o vetor lido e 
//mostre o resultado da soma dos números ímpares presentes no vetor.

int main(){
	int m, *pont, soma;
	setlocale(LC_ALL, "Portuguese");
	
	printf("Entre com o tamanho dos vetores: ");
	scanf("%d", &m);
	
	pont = (int *) malloc(m * sizeof(int));
	
	printf("Digite cada número em uma linha: \n");
	for(int i = 0; i < m; i++){
		scanf("%d", &pont[i]);
	}
	
	printf("Lista de vetores: ");
	for(int i = 0; i < m; i++){
		printf("%d ", pont[i]);
	}
	
	printf("\nLista de Vetores ímpares: ");
	for(int i = 0; i < m; i++){
		if(pont[i]%2 != 0){
			soma = soma + pont[i];
			printf("%d ", pont[i]);
		}
	}
	
	printf("\nSoma dos números ímpares: %d\n", soma);
	
	free(pont);
	
	return 0;
	
}
