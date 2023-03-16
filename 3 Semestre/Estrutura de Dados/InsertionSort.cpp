#include <stdio.h>
#include <stdlib.h>

void InsertionSort(int vetor[], int tam);
int vetor[10] = {100, 193, 93, 478, 375, 4, 47, 55, 889, 5};

main(){
	
	
	InsertionSort(vetor,10);
	
	for(int l = 0; l <10; l++){
		printf("%i ", vetor[l]);
	}
	printf("\n");
}

void InsertionSort(int vetor[], int tam){
	int i ,j , atual;
	int comparacao = 0, posicao = 0;
	
	
	for(i = 1; i < tam; i++){
		atual = vetor[i];
		comparacao ++;
		j = i -1;
		while((j>=0) && (atual < vetor[j])){
			vetor[j+1] = vetor[j];
			j = j -1;
			for(int l = 0; l <10; l++){
				printf("%i ", vetor[l]);
			}
			printf("\n");
		}
		
		vetor[j+1] = atual;
	}
	printf("Qtde de comparacoes: %i\n", comparacao);
	printf("Qtde de mudanca de posicoes: %i\n", posicao);
}
