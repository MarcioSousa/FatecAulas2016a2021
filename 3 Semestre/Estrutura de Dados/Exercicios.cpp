#include <stdio.h>
#include <stdlib.h>

void BubbleSort1(int vet[], int tam);
void BubbleSort2(int vet[], int tam);

main(){
	int vetor[10];
	
	vetor[0] = 10;
	vetor[1] = 1;
	vetor[2] = 4;
	vetor[3] = 7;
	vetor[4] = 8;
	vetor[5] = 9;
	vetor[6] = 7;
	vetor[7] = 2;
	vetor[8] = 3;
	vetor[9] = 4;
	
	BubbleSort1(vetor, 10);
	BubbleSort2(vetor, 10);
	
}

void BubbleSort1(int vet[], int tam){
	int aux, j, i;
	int cont = 0;
	
	for(i=0; i< tam; i++){
		j = 0;
		while(j < tam){
			if(vet[j] > vet[j+1]){
				aux = vet[j];
				vet[j] = vet[j+1];
				vet[j+1] = aux;
				cont ++;
			}
			j++;
		}
	}
	printf("%i\n", cont);
}

void BubbleSort2(int vet[], int tam){
	int fim, i, aux;
	int cont = 0;
	for(fim = tam -1; fim > 0; fim--){
		for(i = 0; i < fim; i++){
			if(vet[i] > vet[i+1]){
				aux = vet[i];
				vet[i] = vet[i+1];
				vet[i+1] = aux;
				cont ++;
			}
		}
	}
	printf("%i\n", cont);
}
