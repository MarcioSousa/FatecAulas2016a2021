#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Escreva uma função que aceita como parâmetro um vetor de inteiros com N valores, e determina o maior elemento do vetor e o número de vezes que este elemento ocorreu no vetor.
//Por exemplo, para um vetor com os seguintes elementos: 5, 2, 15, 3, 7, 15, 8, 6, 15, a função deve retorna para o programa que a chamou o valor 15 e o número 3 (indicando que o número 15 ocorreu 3 vezes).
//A função deve ser do tipo void.

void verifica_vetor (int *vetor_funcao,int *mai,int *qtde);

main()
{
	int vetor[5],maior=0,qtd=0,i;
		
	printf("Informe os valores do vetor:\n");
	
	for(i=0;i<5;i++)
	{
		scanf("%d",&vetor[i]);
	}
	
	verifica_vetor (vetor,&maior,&qtd);
	
	printf ("\nO maior numero do vetor eh o %i e esse numero aparece %i vezes no vetor!", maior, qtd);
	
}

void verifica_vetor (int *vetor_funcao,int *mai,int *qtde)
{
	int i;
	
	for(i=0;i<5;i++,vetor_funcao++)
	{
		if(*vetor_funcao > *mai)
		{
			*mai = *vetor_funcao;
		}
	}
	
	vetor_funcao--;
	
		for(i=5;i>0;i--, vetor_funcao--)
	{
		if(*vetor_funcao == *mai)
		{
			(*qtde)++;
		}
	}
}
