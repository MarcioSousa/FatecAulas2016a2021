#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Crie um programa que implemente o jogo �Bingo de Prog II�. 
//Nesse jogo, o jogador deve selecionar a quantidade de n�meros 
//que ele gostaria de apostar (entre 1 e 20), e em seguida, 
//informar os n�meros escolhidos (valores entre 0 e 100). 
//Ap�s receber a aposta, o computador sorteia 20 n�meros 
//(entre 0 e 100) e compara os n�meros sorteados com os 
//n�meros apostados, informando ao apostador a quantidade 
//de acertos e os n�meros que ele acertou.

void Qtde_intervalo(int *vet, int N, int MIN, int MAX, int *qtde);

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int qtdeNumero, Minimo, Maximo;
	int *vetor;
	int *qtdeN;
	
	qtdeN = 0;
	
	vetor = (int *) malloc (qtdeNumero * sizeof(int));
	qtdeN = (int *) malloc (qtdeNumero * sizeof(int));
	
	printf("Quantos N�meros ser�o digitados? ");
	scanf("%i", &qtdeNumero);
	
	for(int t = 0; t < qtdeNumero; t++){
		printf("Digite o %i� N�mero: ", t+1);
		scanf("%i", &vetor[t]);
	}
	
	printf("Digite o valor m�nimo: ");
	scanf("%i", &Minimo);
	
	printf("Digite o valor m�ximo: ");
	scanf("%i", &Maximo);
	
	Qtde_intervalo(vetor, qtdeNumero, Minimo, Maximo, qtdeN);
	
	printf("Quantidade: %i\n", *qtdeN);
	
	//PROCURANDO O M�NIMO
	//Minimo = vetor[0];
	
	//for(int t = 0; t < qtdeNumero -1; t++){
	//	if(vetor[t] > vetor [t+1]){
	//		Minimo = vetor[t+1];
	//	}
	//}
	
	//PROCURANDO O M�NIMO
	//Maximo = vetor[0];
	
	//for(int t = 0; t < qtdeNumero -1; t++){
	//	if(vetor[t] < vetor [t+1]){
	//		Maximo = vetor[t+1];
	//	}
	//}	
	
	//acerto = compara_aposta(numeroApostado, numeroSorteio, acerto, qtdenumero, qtdesorteio);
	
	//printf("Valor m�nimo � %i\n", Minimo);
	//printf("Valor m�ximo � %i\n", Maximo);
	
	free(vetor);
	free(qtdeN);
	
}

void Qtde_intervalo(int *vet, int N, int MIN, int MAX, int *qtde){

	for(int t = 0; t < N; t++){
		if(vet[t] >= MIN){
			if(vet[t] <= MAX){
				*qtde = *qtde + 1;
			}
		}
	}
	
}


