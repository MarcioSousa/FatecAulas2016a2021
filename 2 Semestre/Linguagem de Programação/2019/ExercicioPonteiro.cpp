#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

//FA�A UM PROGRAMA QUE CRIE UMA ESTRUTURA ALUNO, COM: 
//		RA INT, 
//		NOME CHAR[50], 
//		NOTA FLOAT
//E FA�A UM CADASTRO DE ALUNOS, SOLICITANDO QUE O USU�RIO 
//INFORME QUANTOS ALUNOS SER�O CADASTRADOS E ARMAZENE-OS NUM 
//VETOR. EM SEGUIDA, EXIBA OS DADOS DOS ALUNOS CADASTRADOS E 
//A M�DIA FINAL DE TODA TURMA.

struct Aluno{
	int ra;
	char nome[50];
	float nota;
};

int main() {
    struct Aluno *P;
	int qtde;
	float soma = 0, media = 0;
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Quantos alunos deseja cadastrar: ");
	scanf("%d", &qtde);
	
	P = (struct Aluno *) malloc(qtde* sizeof(struct Aluno));
	
	for(int i = 0; i < qtde; i++){
		fflush(stdin);
		
		printf("Dados do %i� Aluno\n", i+1);
		
		printf("RA: ");
		scanf("%i", &P[i].ra);
		
		fflush(stdin);
		printf("Nome: ");
		gets(P[i].nome);
		
		printf("Nota: ");
		scanf("%f", &P[i].nota);
	}
	
	printf("\n");
	
	for(int t = 0; t < qtde; t++){
		printf("%i� Aluno(a): RA: %d, nome: %s, nota: %.2f\n", t+1, P[t].ra, P[t].nome, P[t].nota);
	}
	
	for(int t=0; t < qtde; t++){
		soma = soma + P[t].nota;
	}
	
	media = soma/qtde;
	
	printf("A m�dia das notas dos alunos �: %.2f\n", media);
	free(P);
	
	return 0;
}

//EXERC�CIO2 - CONSIDERE UM CADASTRO DE PRODUTOS EM ESTOQUE ONDE CADA PRODUTO POSSUI:
//		-- CODIGO (INT)
//		-- NOME (CHAR[50]);
//		-- QUANTIDADE (INT);
//		-- PRECO (FLOAT).
//(A) CRIE A ESTRUTURA DO PRODUTO;
//(B) CADASTRE UM CONJUNTO DE 'N' PRODUTOS;
//(C) ENCONTRE O PRODUTO DE MAIOR PRE�O.
//	OBS: USE SOMENTE ALOCA��O DIN�MICA.

