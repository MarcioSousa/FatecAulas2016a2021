#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

//Crie um programa que implemente o jogo �Bingo de Prog II�. 
//Nesse jogo, o jogador deve selecionar a quantidade de n�meros 
//que ele gostaria de apostar (entre 1 e 20), e em seguida, 
//informar os n�meros escolhidos (valores entre 0 e 100). 
//Ap�s receber a aposta, o computador sorteia 20 n�meros 
//(entre 0 e 100) e compara os n�meros sorteados com os 
//n�meros apostados, informando ao apostador a quantidade 
//de acertos e os n�meros que ele acertou.

void ler_aposta(int *aposta, int n);
void sorteia_valores(int *sorteio, int n);
int *compara_aposta(int *aposta, int *sorteio, int *qtdeacertos, int na, int ns);

int a = 0;

int main(){
	setlocale(LC_ALL, "Portuguese");
	int qtdeacerto= 0;
	int qtdenumero;
	int qtdesorteio;
	int *numeroApostado;
	int *numeroSorteio;
	int *acerto;
	
	printf("Digite a quantidade de n�meros que deseja apostar (entre 1 e 20): ");
	scanf("%i", &qtdenumero);
	printf("Digite a quantidade de n�meros que deseja que sorteie (entre 1 e 20): ");
	scanf("%i", &qtdesorteio);
	
	
	numeroApostado = (int *) malloc (qtdenumero * sizeof(int));
	numeroSorteio = (int *) malloc (qtdenumero * sizeof(int));
	acerto = (int *) malloc (qtdenumero * sizeof(int));
	
	ler_aposta(numeroApostado, qtdenumero);
	sorteia_valores(numeroSorteio, qtdesorteio);
	acerto = compara_aposta(numeroApostado, numeroSorteio, acerto, qtdenumero, qtdesorteio);
	
	printf("---------------------------------\n");
	printf("Quantidade Total de Acertos: %i\n", a);
	
	printf("---------------------------------\n");
	
	printf("N�meros Apostados: ");
	
	for(int t =0; t < qtdenumero; t++){
		printf("%i ", numeroApostado[t]);
	}
	
	printf("\nN�meros Sorteados: ");
	for(int t =0; t < qtdesorteio; t++){
		printf("%i ", numeroSorteio[t]);
	}
	
	printf("\n---------------------------------\n");
	
	
	free(numeroApostado);
	free(numeroSorteio);
	free(acerto);
	
	return 0;
}

void ler_aposta(int *aposta, int n){
	printf("\nDigite o(s) %i n�mero(s) que deseja apostar (0 - 100))\n", n);
	
	for(int t = 0; t < n ; t++){
		printf("==> Digite o %i� N�mero: ", t+1);
		scanf("%i", &aposta[t]);
	}
	
}

void sorteia_valores(int *sorteio, int n){
	srand(time(NULL));
	
	for(int t = 0; t < n; t++){
		sorteio[t] = rand() % 100;
	}
}

int * compara_aposta(int *aposta, int *sorteio, int *qtdeacertos, int na, int ns){
	
	for(int t = 0; t < ns; t++){
		for(int u = 0; u < na; u++){
			if(aposta[u] == sorteio[t]){
				qtdeacertos[a] = aposta[u];
				a++;
			}
		}
	}
	
	return qtdeacertos;
}




