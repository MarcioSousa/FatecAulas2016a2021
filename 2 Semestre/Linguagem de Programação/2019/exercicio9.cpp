#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;
void incluir_liv();
void lista_liv();
void proc_autor();
void proc_titulo();
void proc_estilo();
void media_preco();

struct livro{
	char titulo[15];
	char autor[20];
	char estilo[10];
	int codigo;
	float preco;
};

//declaração das variáveis.
livro vetlivro[50];
char ch;
int numlivros = 0;

//definicão da função menu():
void menu(){
	printf("\n");
	cout<<"Digite I para incluir um livro.\n";
	cout<<"Digite L para listar o nome de todos os livros.\n";
	cout<<"Digite A para procurar livro por autor.\n";
	cout<<"Digite T para procurar livro por título.\n";
	cout<<"Digite E para procurar livro por estulo.\n";
	cout<<"Digite M para calcular a media de preco de todos os livros.\n";
	cout<<"Digite S para sair.\n";
	cin>>ch;
}

//Definição da função principal
int main(){

	menu();
	while(ch!='S'){
		switch(ch){
			case 'I' : incluir_liv();break;
			case 'L' : lista_liv();break;
			case 'A' : proc_autor();break;
			case 'T' : proc_titulo();break;
			case 'E' : proc_estilo();break;
			case 'M' : media_preco();break;
		}//fim do switch
		menu();
	}
	system("PAUSE");
	return 0;
}//fim da função main

void incluir_liv(){
	for(int t = 0; t < 50; t++){
		if(vetlivro[t].codigo == 0){
			fflush(stdin);
			printf("Digite o codigo do livro: ");
			scanf("%i", &vetlivro[t].codigo);
			
			fflush(stdin);
			printf("Digite o título do livro: ");
			gets(vetlivro[t].titulo);
			
			fflush(stdin);
			printf("Digite o autor do livro: ");
			gets(vetlivro[t].autor);
			
			fflush(stdin);
			printf("Digite o estilo do livro: ");
			gets(vetlivro[t].estilo);
			
			fflush(stdin);
			printf("Digite o preco do livro: ");
			scanf("%f", &vetlivro[t].preco);
			
			printf("Cadastrado com Sucesso!\n");
			fflush(stdin);
			
			break;
		}
	}
}

void lista_liv(){
	for(int t = 0; t < 50; t++){
		if(vetlivro[t].codigo != '\0'){
			printf("%i - %s - %s - %s - %.2f\n", vetlivro[t].codigo, vetlivro[t].titulo, vetlivro[t].autor, vetlivro[t].estilo, vetlivro[t].preco);
		}else{
			break;
		}
	}
}

void proc_autor(){
	char nomeautor[50];
	int retorno;
	
	fflush(stdin);
	printf("Digite o nome do autor: ");
	gets(nomeautor);
	
	for(int t = 0; t< 50; t++){
		if(vetlivro[t].codigo != '\0'){
			retorno = strcmp(vetlivro[t].autor, nomeautor);
			if(retorno == 0){
				printf("passou");
				break;
			}else{
				printf("não foi encontrado!");
				break;
			}
		}
	}
	
}

void proc_titulo(){
	char nometitulo[50];
	int retorno;
	
	fflush(stdin);
	printf("Digite o nome do titulo: ");
	gets(nometitulo);
	
	for(int t = 0; t < 50; t++){
		if(vetlivro[t].codigo != '\0'){
			retorno = strcmp(vetlivro[t].titulo, nometitulo);
			if(vetlivro[t].titulo == nometitulo){
				printf("passou");
				break;
			}
		}
	}
}

void proc_estilo(){
	char nomeestilo[50];
	int retorno;
	
	fflush(stdin);
	printf("Digite o nome do estilo: ");
	gets(nomeestilo);
	
	for(int t = 0; t< 50; t++){
		if(vetlivro[t].codigo != '\0'){
			retorno = strcmp(vetlivro[t].estilo, nomeestilo);
			if(vetlivro[t].estilo == nomeestilo){
				printf("passou");
				break;
			}
		}
		
	}
}

void media_preco(){
	float total = 0, media = 0;
	int cont = 0;
	
	for(int t = 0; t < 50; t++){
		if(vetlivro[t].codigo != '\0'){
			total = total + vetlivro[t].preco;
			cont ++;
		}else{
			break;
		}
	}
	
	if(cont != 0){
		media = total / cont;
	}

	printf("A média eh: %.2f\n", media);
	
}
