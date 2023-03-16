#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

/*
Crie um programa que implemente o jogo �Bingo de Prog II�. Nesse jogo, o jogador deve selecionar a quantidade de n�meros que ele gostaria de apostar (entre 1 e 20), e em seguida,
informar os n�meros escolhidos (valores entre 0 e 100). Ap�s receber a aposta, o computador sorteia 20 n�meros (entre 0 e 100) e compara os n�meros sorteados com os n�meros apostados,
informando ao apostador a quantidade de acertos e os n�meros que ele acertou.
O seu programa dever� implementar as fun��es ler_aposta, sorteia_valores e compara_aposta.

A fun��o ler_aposta deve receber como par�metro a quantidade de n�meros que ser�o apostados e um vetor previamente alocado dinamicamente para armazenar a quantidade exata de n�meros apostados.
A fun��o deve pedir para o usu�rio digitar os n�meros apostados e armazena-los no vetor, garantindo que somente n�meros dentro do intervalo de 0 a 100 sejam digitados.
A fun��o deve seguir o seguinte prot�tipo:
void ler_aposta(int *aposta, int n);

A fun��o sorteia_valores deve receber como par�metro a quantidade de n�meros que ser�o sorteados e um vetor previamente alocado dinamicamente para armazenar a quantidade exata de n�meros sorteados.
A fun��o deve sortear aleatoriamente os n�meros (entre 0 e 100) e armazena-los no vetor. A fun��o deve seguir o seguinte prot�tipo:
void sorteia_valores(int *sorteio, int n);

A fun��o compara_aposta deve receber como par�metro o vetor com os n�meros apostados (aposta), o vetor com os n�meros sorteados (sorteio), juntamente com os seus respectivos tamanhos
(na e ns) e um ponteiro para uma vari�vel inteira (qtdacertos), onde deve ser armazenada a quantidade de acertos. A fun��o deve retornar o ponteiro para um vetor alocado dinamicamente
contendo os n�meros que o apostador acertou. A fun��o deve seguir o seguinte prot�tipo:
int * compara_aposta(int *aposta, int *sorteio, int *qtdacertos, int na, int ns);

Em seguida, crie a fun��o principal do programa utilizado as fun��es criadas anteriormente para implementar o jogo �Bingo de Prog II�. Lembre-se que os vetores aposta, sorteio e acertos devem ser
alocados dinamicamente e a mem�ria alocada deve liberada quando ela n�o for mais ser utilizada.
Para sortear n�meros aleat�rios utilize a fun��o rand da biblioteca stdlib.h. A fun��o rand retorna um n�mero aleat�rio em um determinado intervalo. Exemplo:

x = rand() % 10;   // x vai receber um valor entre 0 e 10 

Para garantir que novos n�meros aleat�rios sejam sorteados em cada execu��o do programa � necess�rio executar a fun��o srand antes de sortear os n�meros. Exemplo:
srand(time(NULL));
Para poder utilizar essas fun��es � necess�rio incluir no programa as bibliotecas stdlib.h e time.h. Exemplo de programa para sortear um n�mero aleat�rio:
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
int x;
srand(time(NULL));
x = rand() % 10; // x vai receber um valor entre 0 e 10
printf("%d", x);
return 0;
}

*/

void ler_aposta(int *aposta, int n);
void sorteia_valores(int *sorteio, int n);
int * compara_aposta(int *aposta, int *sorteio, int *qtdacertos, int na, int ns);

main(void)
{
	int qtd,i;
	int *vetor_aposta;
	int *vetor_sorteio;
	int acertos=0;
	int *vetor_acertos;
	
	
	printf("=========== BINGO DE PROG II ===========\n");

	
	do
	{
		printf("Informe quantos numeros deseja apostar (entre 1 e 20 numeros): ");
		scanf("%d",&qtd);
		if(qtd < 1 || qtd > 20)
		{
			printf("\nQuantidade invalida! Deve ser entre 1 e 20!\n");
		}
	}while (qtd < 1 || qtd > 20);
		printf("A quantidade de numeros sera %d",qtd);
	
	
	vetor_aposta = (int *) malloc((2*qtd)*sizeof(int));
	if (vetor_aposta == NULL)
	{
		printf("N�o foi poss�vel alocar a mem�ria para vetor_aposta!");
		exit(1);
	}
	ler_aposta(&vetor_aposta[0], qtd);
	
	srand(time(NULL));
	vetor_sorteio = (int *) malloc((2*qtd)*sizeof(int));
	if (vetor_sorteio == NULL)
	{
		printf("N�o foi poss�vel alocar a mem�ria para vetor_sorteio!");
		exit(1);
	}
	sorteia_valores(&vetor_sorteio[0], qtd);
	
	
	compara_aposta(&vetor_aposta[0], &vetor_sorteio[0], &acertos, qtd, qtd);

	
	printf("\n\nOs valores apostados sao: ");
	for(i=0;i<qtd;i++,vetor_aposta++)
	{
		printf("%d, ",vetor_aposta[i]);
	}
	
	printf("\n\nOs valores sorteados sao: ");
	for(i=0;i<qtd;i++,vetor_sorteio++)
	{
		printf("%d, ",vetor_sorteio[i]);
	}
	
	printf("\n\nQtd de acertos: %d\n",acertos);
	
		
	free(vetor_aposta);
	free(vetor_sorteio);
	
	return 0;
}

void ler_aposta(int *aposta, int n)
{
	/*A fun��o ler_aposta deve receber como par�metro a quantidade de n�meros que ser�o apostados e um vetor previamente alocado dinamicamente para armazenar a quantidade exata de n�meros apostados.
	A fun��o deve pedir para o usu�rio digitar os n�meros apostados e armazena-los no vetor, garantindo que somente n�meros dentro do intervalo de 0 a 100 sejam digitados.*/
	
	int i;
	
	printf("\n\nInforme os numeros que deseja apostar (entre 0 e 100):\n");
	
	for(i=0;i<n;i++,aposta++)
	{
		do
		{
			printf("Informe o %do numero: ",i+1);
			scanf("%d",&aposta[i]);
			if(aposta[i] < 0 || aposta[i] > 100)
			{
				printf("\nValor invalido! Deve ser entre 0 e 100! Insira novamente.\n");	
			}
		}while(aposta[i] < 0 || aposta[i] > 100);
	}
	
}


void sorteia_valores(int *sorteio, int n)
{
	/*A fun��o sorteia_valores deve receber como par�metro a quantidade de n�meros que ser�o sorteados e um vetor previamente alocado dinamicamente para armazenar a quantidade exata de n�meros sorteados.
	A fun��o deve sortear aleatoriamente os n�meros (entre 0 e 100) e armazena-los no vetor.*/
	
	int i;
	
	for(i=0;i<n;i++,sorteio++)
	{
		sorteio[i] = rand() % 100;
	}
	
}




int * compara_aposta(int *aposta, int *sorteio, int *qtdacertos, int na, int ns){
	
	/*A fun��o compara_aposta deve receber como par�metro o vetor com os n�meros apostados (aposta), o vetor com os n�meros sorteados (sorteio), juntamente com os seus respectivos tamanhos
	(na e ns) e um ponteiro para uma vari�vel inteira (qtdacertos), onde deve ser armazenada a quantidade de acertos. A fun��o deve retornar o ponteiro para um vetor alocado dinamicamente
	contendo os n�meros que o apostador acertou.*/
	
	int i,j,z,k=0;
	int *v_acertos;
	
	v_acertos = (int *) malloc(na*sizeof(int));
	if (v_acertos == NULL)
	{
		printf("N�o foi poss�vel alocar a mem�ria para v_acertos!");
		exit(1);
	}
	
	for(i=0;i<na;i++,aposta++)
	{
		for(j=0;j<ns;j++,sorteio++)
		{
			if (aposta[i] == sorteio[j])
			{
				(*qtdacertos)++;
				v_acertos[k] = sorteio[j];
				k++;
			}
		}
		sorteio = sorteio - ns;
	}
	
	if((*qtdacertos) > 0)
	{
		printf("\n\n=================VETOR DE ACERTOS================\n");
	
		for(z=0;z<k;z++,v_acertos++)
		{
		printf(" %d",*v_acertos);
		}
	}
	else
	{
		printf("\n\n=================NAO ACERTOU NENHUM NUMERO!!================\n");
	}
	
	return v_acertos;
	free(v_acertos);
}

