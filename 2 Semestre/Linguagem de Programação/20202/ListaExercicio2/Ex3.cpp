#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Faça um programa em C que 
//receba do usuário o tamanho de uma string e 
//chame uma função para alocar dinamicamente essa string. 
//Em seguida, o usuário deverá informar o conteúdo dessa string. 
//O programa imprime a string sem suas vogais.
char *palavra;

void AlocaString(int num){
	char *ps;
	palavra = (char *) malloc ((num) * sizeof(char));
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int tamstr;
	
	printf("Entre com o tamanho da string: ");
	scanf("%i", &tamstr);
	
	AlocaString(tamstr);
	
	printf("Digite uma string com %i letras: ", tamstr);
	scanf("%s", palavra);
	
	//imprimir a string sem vogais
	printf("A palavra sem as vogais: ");
	for(int i = 0; i < tamstr; i++){
		if(palavra[i] != 'a' && palavra[i] != 'A' && palavra[i] != 'e' && palavra[i] != 'E' && palavra[i] != 'i' && palavra[i] != 'I' && palavra[i] != 'o' && palavra[i] != 'O' && palavra[i] != 'u' && palavra[i] != 'U'){
			printf("%c", palavra[i]);
		}
	}
	
	printf("\n");
	
	free(palavra);
	
	return 0;
	
}
