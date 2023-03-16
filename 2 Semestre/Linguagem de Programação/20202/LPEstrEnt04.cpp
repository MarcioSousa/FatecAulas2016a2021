#include <stdio.h>
#include <locale.h>
#include <string.h>

struct Pessoa{
	char nome[30];
	char endereco[50];
	char telefone[15];
};

//Utilizando estrutura, fazer um programa em C que permita 
//a entrada de nome, endereço e telefone de 5 pessoas e os 
//imprima em ordem alfabética.

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	Pessoa pessoas[5];
	Pessoa pessoaAux;
	char nomeAux[30];
	char enderecoAux[50];
	char telefoneAux[15];
	bool alterou = false;
	
	printf("Cadastro de Pessoas.\n");
	
	for(int t = 0; t < 5; t++){
		printf("Digite o nome: ");
		gets(pessoas[t].nome);
		fflush(stdin);
		printf("Digite o endereço: ");
		gets(pessoas[t].endereco);
		fflush(stdin);
		printf("Digite o telefone: ");
		gets(pessoas[t].telefone);
	}
	
	for(int t = 0; t < 5; t++){
		if(strcmp(pessoas[t].nome, pessoas[t+1].nome) > 0){
			if(t < 4){
				strcpy(nomeAux, pessoas[t].nome);
				strcpy(enderecoAux, pessoas[t].endereco);
				strcpy(telefoneAux, pessoas[t].telefone);
        		
				strcpy(pessoas[t].nome, pessoas[t+1].nome);
        		strcpy(pessoas[t].endereco, pessoas[t+1].endereco);
        		strcpy(pessoas[t].telefone, pessoas[t+1].telefone);
        		
        		strcpy(pessoas[t+1].nome, nomeAux);
        		strcpy(pessoas[t+1].endereco, enderecoAux);
        		strcpy(pessoas[t+1].telefone, telefoneAux);
        		
				t = -1;
			}
		}
	}
	
	printf("Nome das pessoas em ordem Alfabética:\n");
	
	for(int t = 0; t < 5; t++){	
		printf("%s, %s, %s\n",pessoas[t].nome, pessoas[t].endereco, pessoas[t].telefone);
	}
	
	
}
