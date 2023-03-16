#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Escreva um programa em linguagem C que 
//solicita ao usuário a quantidade de alunos de uma turma e 
//aloca um vetor de notas (números reais). 
//Depois de ler as notas, imprime a média aritmética.
//Obs: não deve ocorrer desperdício de memória; 
//e após ser utilizada a memória deve ser devolvida.

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
	
	printf("\nA média das notas de todos os alunos é de: ");
	for(int i = 0; i < qtde; i++){
		soma = soma + nota[i];
	}
	
	
	printf("%.2f", soma/qtde);
	
	free(nota);
	
	return 0;
	
}
