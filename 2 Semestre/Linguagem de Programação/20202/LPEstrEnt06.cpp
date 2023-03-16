#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define TAM 3

struct aluno {
	char nome[15];
	int matricula;
	float N_Prova1;
	float N_Prova2;
	float N_Trab;
	float media;
};

main(){
	setlocale(LC_ALL, "Portuguese"); 
	
	struct aluno alunos[TAM];
	struct aluno aprovados[TAM];
	struct aluno reprovados[TAM];
	
	int a=0,r=0;
	
	for(int t = 0; t < TAM; t++){
		printf("Digite os dados do %iº de %i alunos.\n", t+1, TAM);
		printf("Nome: ");		
		gets(alunos[t].nome);
		fflush(stdin);
		
		printf("Matrícula: ");		
		scanf("%i", &alunos[t].matricula);
		fflush(stdin);
		
		printf("Nota Prova 1: ");		
		scanf("%f", &alunos[t].N_Prova1);
		fflush(stdin);
		
		printf("Nota Prova 2: ");		
		scanf("%f", &alunos[t].N_Prova2);
		fflush(stdin);
		
		printf("Nota Trabalho: ");		
		scanf("%f", &alunos[t].N_Trab);
		fflush(stdin);
		
		//Calcular média
		alunos[t].media = ((alunos[t].N_Prova1 + alunos[t].N_Prova2)/2)*0.3+alunos[t].N_Trab * 0.7;
		
		if (alunos[t].media >= 6.0)
		{
			aprovados[a].matricula = alunos[t].matricula;
			aprovados[a].media = alunos[t].media;
			a++;
		}
		else
		{
			reprovados[r].matricula = alunos[t].matricula;
			reprovados[r].media = alunos[t].media;
			r++;
		}
		
	}
	
	//Exibir na tela os aprovados
	printf("====\nListagem de alunos aprovados.\n");
	for (int t=0; t<a; t++)
	{
		printf("\nMatricula %d, com media %.2f", aprovados[t].matricula, aprovados[t].media);
	}
		
	printf("\n\n\nLista de alunos reprovados:");
	for (int t=0; t<r; t++)
	{
		printf("\nMatricula %d, com media %.2f", reprovados[t].matricula, reprovados[t].media);
	}
		
	printf("\n== FINALIZADO ==\n");
}












