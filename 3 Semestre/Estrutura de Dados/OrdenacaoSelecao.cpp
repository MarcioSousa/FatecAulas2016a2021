#include <stdio.h>
#include <stdlib.h>

void SelectionSort(int vet[], int tam);
void SelectionSort2(int vet[], int tam);

main(){
	int vetor[10];
	int vetor2[10];
	
	vetor[0] = 40;
	vetor[1] = 30;
	vetor[2] = 1;
	vetor[3] = 2;
	vetor[4] = 81;
	vetor[5] = 77;
	vetor[6] = 66;
	vetor[7] = 37;
	vetor[8] = 5;
	vetor[9] = 7;
	
	vetor2[0] = 40;
	vetor2[1] = 30;
	vetor2[2] = 1;
	vetor2[3] = 2;
	vetor2[4] = 81;
	vetor2[5] = 77;
	vetor2[6] = 66;
	vetor2[7] = 37;
	vetor2[8] = 5;
	vetor2[9] = 7;
	
	SelectionSort(vetor, 10);
	SelectionSort2(vetor2, 10);
	
	for(int t = 0; t < 10; t++){
		printf("%i ", vetor[t]);
	}
	printf("\n");
	
	for(int t = 0; t < 10; t++){
		printf("%i ", vetor2[t]);
	}
	printf("\n");
}

//1) Comparações realizadas nesta versão = 72
//2) Quantidade de trocas realizadas nesta versão = 20
//Selection Sort
void SelectionSort(int vet[], int tam){
	int indx, indy, aux;
	int comparacao =0, troca = 0;
	
	for(indy = 0; indy< tam -2; indy++){
		for(indx = 0; indx< tam-1; indx++){
			comparacao++;
			printf("Comparacao %i %i<%i\n", comparacao, vet[indx], vet[indy]);
			if(vet[indx] < vet[indy]){
				aux = vet[indy];
				vet[indy] = vet[indx];
				vet[indx] = aux;
				troca++;
				printf("Troca %i: %i por %i\n", troca, vet[indy], vet[indx]);
			}
		}
	}
}

//1) Comparações realizadas nesta versão = 80
//2) Quantidade de trocas realizadas nesta versão = 9
//Otimização da Selection Sort
void SelectionSort2(int vet2[], int tam){
	int indy, indx, aux, menor, comparacao =0, troca = 0;
	for(indy = 0; indy < tam-2; indy++){
		menor = indy;
		for(indx = 0; indx < tam-1; indx++){
			comparacao++;
			printf("Comparacao %i\n", comparacao);
			if(vet2[menor] > vet2[indx]){
				menor = indx;
				troca++;
				printf("Troca %i: %i por %i\n", troca, vet2[indy], vet2[indx]);
			}
		}
		comparacao++;
		printf("Comparacao %i\n", comparacao);
		if(menor > indy){
			aux = vet2[indy];
			vet2[indy] = vet2[menor];
			vet2[menor] = aux;
			printf("Troca %i\n", troca);
		}
	}
}

//Exercícios
//Implemente as duas versões do SelectionSort (Normal e Otimizada)
//e compare:
//	a)Quantidade de comparações realizadas por cada versão; (1)
//	b)Quantidade de trocas realizadas por cada versão.(2)
//	
//	Entrada(Dez Números)
//	40 30 1 2 81 77 66 37 5 7
