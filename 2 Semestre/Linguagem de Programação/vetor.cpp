//Declarar um vetor de 80 posi??es de inteiros.
//Esse vetor representa uma estrutura do tipo matriz, com 8 linhas e 10 colunas.
//Fa?a um programa que receba valores inteiros maiores do que zero e guarde em uma das posi??es do vetor determinada pelo usu?rio. O usu?rio dever? digitar a linha e a coluna desejada para guardar o valor inteiro.
//Finalizar a entrada de dados quando todo o vetor estiver preenchido.
//*/
#include <stdio.h>
#define LIN 3
#define COL 4
#define TAM  LIN * COL

int main(void)
{
	int vetor[TAM];
	int vetor2[LIN][COL];
	
	int lin, col, valor, pos, i;
	int continua = 1;

	//Inicializa o vetor com zero
	for(i=0; i < TAM; i++)
	{
		vetor[i]=0;
	}

	do{
    	printf("Digite o valor da linha entre 1 e %i: ", LIN);
		scanf("%i", &lin);
	}while(lin < 1 || lin > LIN);

	do{
	  	printf("Digite o valor da coluna entre 1 e %i: ", COL);
     	scanf("%i", &col);
	}while(col< 1 || col > COL);

	do{
		printf("Digite um valor positivo: ");
	   	scanf("%i", &valor);
	}while(valor <1);

	//Calcula a posicao no vetor relativo a linha e coluna digitado
	pos = ((lin-1) * COL ) + (col-1);

	//Salva valor digitado no vetor
	vetor[pos] = valor;

	printf("\nA linha %i e coluna %i tem o indice %i no vetor.", lin, col, pos);
	printf("\nEstado final do vetor:\n\n\t");
	for(i=0; i < TAM; i++)
	   printf("%i ", vetor[i]);
       printf("\n");

 	return 0;
}
