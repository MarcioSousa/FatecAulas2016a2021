#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

/*
Crie um programa que implemente o jogo “Bingo de Prog II”. Nesse jogo, o jogador deve selecionar a quantidade de números que ele gostaria de apostar (entre 1 e 20), e em seguida,
informar os números escolhidos (valores entre 0 e 100). Após receber a aposta, o computador sorteia 20 números (entre 0 e 100) e compara os números sorteados com os números apostados,
informando ao apostador a quantidade de acertos e os números que ele acertou.
O seu programa deverá implementar as funções ler_aposta, sorteia_valores e compara_aposta.

A função ler_aposta deve receber como parâmetro a quantidade de números que serão apostados e um vetor previamente alocado dinamicamente para armazenar a quantidade exata de números apostados.
A função deve pedir para o usuário digitar os números apostados e armazena-los no vetor, garantindo que somente números dentro do intervalo de 0 a 100 sejam digitados.
A função deve seguir o seguinte protótipo:
void ler_aposta(int *aposta, int n);

A função sorteia_valores deve receber como parâmetro a quantidade de números que serão sorteados e um vetor previamente alocado dinamicamente para armazenar a quantidade exata de números sorteados.
A função deve sortear aleatoriamente os números (entre 0 e 100) e armazena-los no vetor. A função deve seguir o seguinte protótipo:
void sorteia_valores(int *sorteio, int n);

A função compara_aposta deve receber como parâmetro o vetor com os números apostados (aposta), o vetor com os números sorteados (sorteio), juntamente com os seus respectivos tamanhos
(na e ns) e um ponteiro para uma variável inteira (qtdacertos), onde deve ser armazenada a quantidade de acertos. A função deve retornar o ponteiro para um vetor alocado dinamicamente
contendo os números que o apostador acertou. A função deve seguir o seguinte protótipo:
int * compara_aposta(int *aposta, int *sorteio, int *qtdacertos, int na, int ns);

Em seguida, crie a função principal do programa utilizado as funções criadas anteriormente para implementar o jogo “Bingo de Prog II”. Lembre-se que os vetores aposta, sorteio e acertos devem ser
alocados dinamicamente e a memória alocada deve liberada quando ela não for mais ser utilizada.
Para sortear números aleatórios utilize a função rand da biblioteca stdlib.h. A função rand retorna um número aleatório em um determinado intervalo. Exemplo:

x = rand() % 10;   // x vai receber um valor entre 0 e 10 

Para garantir que novos números aleatórios sejam sorteados em cada execução do programa é necessário executar a função srand antes de sortear os números. Exemplo:
srand(time(NULL));
Para poder utilizar essas funções é necessário incluir no programa as bibliotecas stdlib.h e time.h. Exemplo de programa para sortear um número aleatório:
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
		printf("Não foi possível alocar a memória para vetor_aposta!");
		exit(1);
	}
	ler_aposta(&vetor_aposta[0], qtd);
	
	srand(time(NULL));
	vetor_sorteio = (int *) malloc((2*qtd)*sizeof(int));
	if (vetor_sorteio == NULL)
	{
		printf("Não foi possível alocar a memória para vetor_sorteio!");
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
	/*A função ler_aposta deve receber como parâmetro a quantidade de números que serão apostados e um vetor previamente alocado dinamicamente para armazenar a quantidade exata de números apostados.
	A função deve pedir para o usuário digitar os números apostados e armazena-los no vetor, garantindo que somente números dentro do intervalo de 0 a 100 sejam digitados.*/
	
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
	/*A função sorteia_valores deve receber como parâmetro a quantidade de números que serão sorteados e um vetor previamente alocado dinamicamente para armazenar a quantidade exata de números sorteados.
	A função deve sortear aleatoriamente os números (entre 0 e 100) e armazena-los no vetor.*/
	
	int i;
	
	for(i=0;i<n;i++,sorteio++)
	{
		sorteio[i] = rand() % 100;
	}
	
}




int * compara_aposta(int *aposta, int *sorteio, int *qtdacertos, int na, int ns){
	
	/*A função compara_aposta deve receber como parâmetro o vetor com os números apostados (aposta), o vetor com os números sorteados (sorteio), juntamente com os seus respectivos tamanhos
	(na e ns) e um ponteiro para uma variável inteira (qtdacertos), onde deve ser armazenada a quantidade de acertos. A função deve retornar o ponteiro para um vetor alocado dinamicamente
	contendo os números que o apostador acertou.*/
	
	int i,j,z,k=0;
	int *v_acertos;
	
	v_acertos = (int *) malloc(na*sizeof(int));
	if (v_acertos == NULL)
	{
		printf("Não foi possível alocar a memória para v_acertos!");
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

