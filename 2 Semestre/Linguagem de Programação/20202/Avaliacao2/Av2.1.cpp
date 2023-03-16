#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Crie um programa que implemente o jogo “Bingo de Prog II”. 
//Nesse jogo, o jogador deve selecionar a quantidade de números 
//que ele gostaria de apostar (entre 1 e 20), e em seguida, 
//informar os números escolhidos (valores entre 0 e 100). 
//Após receber a aposta, o computador sorteia 20 números 
//(entre 0 e 100) e compara os números sorteados com os 
//números apostados, informando ao apostador a quantidade 
//de acertos e os números que ele acertou.

void Qtde_intervalo(int *vet, int N, int MIN, int MAX, int *qtde);

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int qtdeNumero, Minimo, Maximo;
	int *vetor;
	int *qtdeN;
	
	qtdeN = 0;
	
	vetor = (int *) malloc (qtdeNumero * sizeof(int));
	qtdeN = (int *) malloc (qtdeNumero * sizeof(int));
	
	printf("Quantos Números serão digitados? ");
	scanf("%i", &qtdeNumero);
	
	for(int t = 0; t < qtdeNumero; t++){
		printf("Digite o %iº Número: ", t+1);
		scanf("%i", &vetor[t]);
	}
	
	printf("Digite o valor mínimo: ");
	scanf("%i", &Minimo);
	
	printf("Digite o valor máximo: ");
	scanf("%i", &Maximo);
	
	Qtde_intervalo(vetor, qtdeNumero, Minimo, Maximo, qtdeN);
	
	printf("Quantidade: %i\n", *qtdeN);
	
	//PROCURANDO O MÍNIMO
	//Minimo = vetor[0];
	
	//for(int t = 0; t < qtdeNumero -1; t++){
	//	if(vetor[t] > vetor [t+1]){
	//		Minimo = vetor[t+1];
	//	}
	//}
	
	//PROCURANDO O MÍNIMO
	//Maximo = vetor[0];
	
	//for(int t = 0; t < qtdeNumero -1; t++){
	//	if(vetor[t] < vetor [t+1]){
	//		Maximo = vetor[t+1];
	//	}
	//}	
	
	//acerto = compara_aposta(numeroApostado, numeroSorteio, acerto, qtdenumero, qtdesorteio);
	
	//printf("Valor mínimo é %i\n", Minimo);
	//printf("Valor máximo é %i\n", Maximo);
	
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


