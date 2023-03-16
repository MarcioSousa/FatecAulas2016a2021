#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Faça um programa que crie uma estrutura Aluno, com:
//RA – int
//Nome – char[50]
//Nota - float
//E faça um cadastro de alunos, 
//solicitando que o usuário informe quantos alunos serão cadastrados e 
//armazene-os num vetor. Em seguida, exiba os dados dos alunos 
//cadastrados e a média das notas de todos os alunos da turma.

typedef struct{
	int RA;
	char Nome[50];
	float nota;
} Aluno;

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int qtdea;
	
	//criando a váriável de quantidade
	printf("Digite a qtde de Alunos que serão registrados: ");
	scanf("%i", &qtdea);
	
	Aluno *alu = (Aluno *) malloc(qtdea *sizeof(Aluno));
	
	//inserindo os alunos
	printf("Digite os alunos, um em cada linha:\n");
	for(int t = 0; t < qtdea; t++){
		printf("RA do Aluno: ");
		scanf("%i", &alu[t].RA);
		fflush(stdin);
		printf("Nome do Aluno: ");
		gets(alu[t].Nome);
		fflush(stdin);
		printf("Nota do Aluno: ");
		scanf("%f", &alu[t].nota);
		fflush(stdin);
	}
	
	printf("Dados do(s) Aluno(s)\n");
	
	for(int t = 0; t < qtdea; t++){
		printf("RA: %i; Nome: %s; Nota: %.2f\n", alu[t].RA, alu[t].Nome, alu[t].nota);
	}
	
	free(alu);
	
	return 0;
	
}
