#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
Crie um programa para manipular vetores. O seu programa deve implementar uma fun��o que receba um vetor de inteiros V e retorne um outro vetor de
inteiros alocado dinamicamente com todos os valores de V que estejam entre o valor m�nimo e m�ximo (que tamb�m s�o passados como par�metro para a fun��o).

A fun��o deve obedecer ao seguinte prot�tipo:
void valores_entre(int *v, int n, int min, int max, int *qtd);

A fun��o recebe:
� v: vetor de n�meros inteiros;
� n: a quantidade de elementos do vetor v;
� min: valor m�nimo a ser buscado;
� max: valor m�ximo a ser buscado;

A fun��o deve:
� Verificar a quantidade de elementos do vetor que sejam maiores do que min e menores que max;
� Caso a quantidade seja maior do que 0 (zero), alocar dinamicamente uma �rea do exato tamanho necess�rio para armazenar os valores;
� Copia os elementos do vetor que sejam maiores do que min e menores que max para a �rea alocada dinamicamente.
� Mostrar na tela e exibir na tela os valores resultantes.

Em seguida, crie a fun��o principal do programa para inicializar um vetor de inteiros, exibir esses valores na tela e pedir para o usu�rio digitar o valor m�nimo
e m�ximo a ser buscado. Em seguida o programa dever� chamar a fun��o valores_entre.
Lembre-se de exibir uma mensagem de erro caso nenhum valor seja encontrado. N�o se esque�a de liberar a mem�ria alocada dinamicamente.
*/

void valores_entre(int *v, int n, int min, int max, int *qtd);

main()
{
	int vetor[5]={1,2,3,4,5};
	int minimo, maximo, qtde=0, i;
	
	printf("Vetor disponibilizado: ");
	for(i=0;i<5;i++)
	{
		printf("%d ",vetor[i]);
	}
	
	printf("\nInforme o valor minimo: ");
	scanf("%d",&minimo);
	printf("Informe o valor maximo: ");
	scanf("%d",&maximo);
	
	valores_entre(&vetor[0], 5, minimo, maximo, &qtde);
	//se der errado mudar a linha acima para "vetor"
	printf("\nExistem %d valores entre %d e %d.",qtde,minimo,maximo);
	
	
}

void valores_entre(int *v, int n, int min, int max, int *qtd)
{
	int i, *vetor_novo, j=0;
	
	
	for(i=0;i<n;i++,v++)
	{
		if (*v >= min && *v <= max)
		{
			(*qtd)++;
		}
	}
	
	if ((*qtd)==0)
	{
		printf("Nenhum valor encontrado");
		exit(1);
	}
	
	vetor_novo = (int*) malloc((*qtd)*sizeof(int));
	
	if (vetor_novo == NULL)
{
	printf ("Nao foi possivel alocar o vetor!");
	exit(1);
}	
	
	v--;
	
	for(i=5;i>0;i--,v--)
	{
		if (*v >= min && *v <= max)
		{
			vetor_novo[j] = *v;
			j++;
		}
	}
	
	printf("O vetor novo eh composto por: ");
	
	for(i=(*qtd)-1;i>=0;i--)
	{
		printf("%d ",vetor_novo[i]);

	}
	free(vetor_novo);
}
