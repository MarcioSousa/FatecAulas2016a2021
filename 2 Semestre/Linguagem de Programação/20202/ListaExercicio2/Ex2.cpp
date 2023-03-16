#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Escreva um programa em linguagem C que 
//solicita ao usu�rio a quantidade de alunos de uma turma e 
//aloca um vetor de notas (n�meros reais). 
//Depois de ler as notas, imprime a m�dia aritm�tica.
//Obs: n�o deve ocorrer desperd�cio de mem�ria; 
//e ap�s ser utilizada a mem�ria deve ser devolvida.

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int qtde;
	float *nota, soma;
	
	printf("Entre com a quantidade de alunos da turma: ");
	scanf("%d", &qtde);
	
	nota = (float *) malloc(qtde * sizeof(int));
	
	printf("Digite as notas, uma em cada linha: \n");
	for(int i = 0; i < qtde; i++){
		scanf("%f", &nota[i]);
	}
	
	printf("\nLista de notas: ");
	for(int i = 0; i < qtde; i++){
		printf("%.2f ", nota[i]);
	}
	
	printf("\nA m�dia das notas de todos os alunos � de: ");
	for(int i = 0; i < qtde; i++){
		soma = soma + nota[i];
	}
	
	
	printf("%.2f", soma/qtde);
	
	free(nota);
	
	return 0;
	
}
