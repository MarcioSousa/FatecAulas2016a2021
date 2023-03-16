#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TAM 10

struct alunos		//definição da estrutura
{
	char nome[100];
	int matricula;	
	float n_prova1, n_prova2, n_trab, media;
};



main() {
	
	
	struct alunos aluno [TAM];
	struct alunos aprovados [TAM];
	struct alunos reprovados [TAM];
	int i,j=0,k=0;
	
	for (i=0; i<TAM; i++)
	{
		printf("Digite o nome do aluno: ");
		gets(aluno[i].nome);
		fflush(stdin);
		printf("Digite a matricula do aluno: ");
		scanf("%d", &aluno[i].matricula);
		fflush(stdin);
		printf("Digite a nota da P1: ");
		scanf("%f", &aluno[i].n_prova1);
		printf("Digite a nota da P2: ");
		scanf("%f", &aluno[i].n_prova2);
		printf("Digite a nota do trabalho: ");
		scanf("%f", &aluno[i].n_trab);
		fflush(stdin);
		aluno[i].media = ((aluno[i].n_prova1 + aluno[i].n_prova2)/2)*0.3 + aluno[i].n_trab*0.7;
		
		if (aluno[i].media >= 6.0)
		{
			aprovados[j].matricula = aluno[i].matricula;
			aprovados[j].media = aluno[i].media;
			j++;
		}
		else
		{
			reprovados[k].matricula = aluno[i].matricula;
			reprovados[k].media = aluno[i].media;
			k++;
		}
		
	}
	
	printf("Lista de alunos aprovados:");
	for (i=0; i<j; i++)
	{
		printf("\nMatricula %d, com media %.2f", aprovados[i].matricula, aprovados[i].media);
	}
		
	printf("\n\n\nLista de alunos reprovados:");
	for (i=0; i<k; i++)
	{
		printf("\nMatricula %d, com media %.2f", reprovados[i].matricula, reprovados[i].media);
	}
		
}
