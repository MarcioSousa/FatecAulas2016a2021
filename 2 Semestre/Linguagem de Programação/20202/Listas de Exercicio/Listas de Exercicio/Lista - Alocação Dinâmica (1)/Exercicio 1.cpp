#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
Crie um programa para manipular vetores. O seu programa deve implementar uma função que receba um vetor de inteiros V e retorne um outro vetor de
inteiros alocado dinamicamente com todos os valores de V que estejam entre o valor mínimo e máximo (que também são passados como parâmetro para a função).

A função deve obedecer ao seguinte protótipo:
void valores_entre(int *v, int n, int min, int max, int *qtd);

A função recebe:
• v: vetor de números inteiros;
• n: a quantidade de elementos do vetor v;
• min: valor mínimo a ser buscado;
• max: valor máximo a ser buscado;

A função deve:
• Verificar a quantidade de elementos do vetor que sejam maiores do que min e menores que max;
• Caso a quantidade seja maior do que 0 (zero), alocar dinamicamente uma área do exato tamanho necessário para armazenar os valores;
• Copia os elementos do vetor que sejam maiores do que min e menores que max para a área alocada dinamicamente.
• Mostrar na tela e exibir na tela os valores resultantes.

Em seguida, crie a função principal do programa para inicializar um vetor de inteiros, exibir esses valores na tela e pedir para o usuário digitar o valor mínimo
e máximo a ser buscado. Em seguida o programa deverá chamar a função valores_entre.
Lembre-se de exibir uma mensagem de erro caso nenhum valor seja encontrado. Não se esqueça de liberar a memória alocada dinamicamente.
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
