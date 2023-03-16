#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define MAX 100

int contagemOcorrencias(char palavra[MAX], char frase[MAX]);

main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("-------------------------------------\n");
	printf("|      TRABALHO DE LP ENTREGA       |\n");
	printf("|            2º SEMESTRE            |\n");
	printf("| ALUNOS:                           |\n");
	printf("|    DANILO RODRIGUES.              |\n");
	printf("|    MARCIO SOUSA.                  |\n");
	printf("-------------------------------------\n\n");
	
	
	char palavra[MAX], frase[MAX];
	int qtde =0;
	
	printf("Escreva uma palavra: ");
	gets(palavra);
	
	printf("Escreva uma frase: ");
	gets(frase);
	
	qtde = contagemOcorrencias(palavra, frase);
	
	printf("O frase tem %i palavras %s.\n\n", qtde, palavra);

	system("pause");	
}

int contagemOcorrencias(char palavra[MAX], char frase[MAX]){
	int cont = 0, i = 0, j = 0;
	
	while(frase[i] != '\0'){
		while(frase[i+j] != '\0' && palavra[j] != '\0' && frase[i+j] == palavra[j]){
			j++;
		}
		if(palavra[j] == '\0'){
			cont++;
		}
		j = 0;
		i++;
	}
	return cont;
}
