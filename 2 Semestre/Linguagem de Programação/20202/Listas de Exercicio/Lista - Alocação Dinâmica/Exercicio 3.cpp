#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
Fa�a um programa que:
(a) Crie dinamicamente uma matriz de distancias entre n cidades diferentes,
(b) Pe�a para o usu�rio entrar com as dist�ncias entre as cidades,
(c) Exiba na tela a matriz de distancias criada,
(d) Quando o usu�rio digitar o n�mero de duas cidades o programa dever� retornar a dist�ncia entre elas.
*/


main()
{
	int **p;
	int i,j,n;
	
	printf("Informe a quantidade de cidades: ");				//RECEBE A QUANTIDADE DE CIDADES
	scanf("%d",&n);
	
	p = (int**) malloc(n*sizeof(int*));							//ALOCA AS LINHAS
	
	for(i=0;i<n;i++)
	{
		p[i] = (int*) malloc(n*sizeof(int));					//ALOCA AS COLUNAS PARA CADA LINHA
		for(j=0;j<n;j++)
		{
			if (i==j)
			{
				p[i][j]=0;
			}
			else
			{
				if(i>j)
				{
					p[i][j] = p[j][i];
				}
				else
				{
					printf("Insira a distancia entre as cidades %d e %d: ", i+1,j+1);
					scanf("%d",&p[i][j]);
				}

			}
		}
	}
	
	printf("\n\nCIDADE\t|");									//IMPRIME O CABE�ALHO DA MATRIZ
	for(i=0;i<n;i++)
	{
		printf("%d\t",i+1);										//IMPRIME O TITULO DAS COLUNAS
	}
	printf("\n--------+--------------------------------------------------\n");
	for(i=0;i<n;i++)											//IMPRIME A MATRIZ
	{
		printf("%d\t|",i+1);
		for(j=0;j<n;j++)
		{
			printf("%d\t",p[i][j]);
		}
		printf("\n");
	}
	
	printf("\n\n");
	for(j=0;j<n;j++)											//COME�A A DESALOCA��O
	{
		free(p[j]);												//DESALOCA AS COLUNAS
	}
	free(p);													//DESALOCA AS LINHAS
	
}
