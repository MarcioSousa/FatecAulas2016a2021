#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define TAM 3
void incluir_liv();
void lista_liv();
void proc_autor();
void proc_titulo();
void proc_estilo();
void media_preco();

struct livro {
	char autor[50];
	char titulo[50];
	char estilo[50];
	int cod;
	float preco;
};

// declaração de variáveis
struct livro vetlivro[10];
char ch;
int numlivros = 0;

// definição da função menu( ):
void menu(){
	printf (" Digite I para incluir um livro. \n");
	printf (" Digite L para listar o nome de todos os livros. \n");
	printf (" Digite A para procurar livro por autor. \n");
	printf (" Digite T para procurar livro por titulo. \n");
	printf (" Digite E para procurar livro por estilo. \n");
	printf (" Digite M para calcular a media de preco de todos os livros. \n");
	printf ( "Digite S para sair \n");
	scanf ("%c", &ch);
}

// definição da função principal
int main(){
	setlocale(LC_ALL, "Portuguese"); 
	menu();
	
	while (ch != 'S'){
		switch(ch){
			case 'I': incluir_liv(); break;
			case 'L': lista_liv(); break;
			case 'A': proc_autor(); break;
			case 'T': proc_titulo(); break;
			case 'E': proc_estilo(); break;
			case 'M': media_preco(); break;
		} // fim do switch
		menu();
	}
}// fim da função main.

void incluir_liv(){
	fflush(stdin);
	printf("\n== Inclusão de Livros ==");
	printf("\nTítulo do livro: ");
	gets(vetlivro[numlivros].titulo);
	fflush(stdin);
	printf("\nAutor do livro: ");
	gets(vetlivro[numlivros].autor);
	fflush(stdin);
	printf("\nEstilo do livro: ");
	gets(vetlivro[numlivros].estilo);
	fflush(stdin);
	printf("\nCódigo do livro: ");
	scanf("%d", &vetlivro[numlivros].cod);
	fflush(stdin);
	printf("\nPreço do livro: ");
	scanf("%f", &vetlivro[numlivros].preco);
	printf("\n");
	numlivros++;
	fflush(stdin);
}

void lista_liv(){
	fflush(stdin);
	for(int t = 0; t < TAM; t++){
		if(vetlivro[t].cod > 0){
			printf("Código: %i, autor: %s, título: %s, estilo: %s, preço: %.2f\n\n", vetlivro[t].cod, vetlivro[t].autor, vetlivro[t].titulo, vetlivro[t].estilo, vetlivro[t].preco);
		}else{
			break;
		}
	}
	fflush(stdin);
}

void proc_autor(){
	char filtroAutor[50];
	fflush(stdin);
	printf("Digite um Autor: ");
	gets(filtroAutor);
	fflush(stdin);
	for(int t = 0; t < TAM; t++){
		if(strcmp(vetlivro[t].autor, filtroAutor) == 0){
			printf("Código: %i, autor: %s, título: %s, estilo: %s, preço: %.2f\n\n", vetlivro[t].cod, vetlivro[t].autor, vetlivro[t].titulo, vetlivro[t].estilo, vetlivro[t].preco);
			break;
		}
	}
	fflush(stdin);
}

void proc_titulo(){
	char filtroTitulo[50];
	fflush(stdin);
	printf("Digite um Título: ");
	gets(filtroTitulo);
	fflush(stdin);
	for(int t = 0; t < TAM; t++){
		if(strcmp(vetlivro[t].titulo, filtroTitulo) == 0){
			printf("Código: %i, autor: %s, título: %s, estilo: %s, preço: %.2f\n\n", vetlivro[t].cod, vetlivro[t].autor, vetlivro[t].titulo, vetlivro[t].estilo, vetlivro[t].preco);
			break;
		}
	}
	fflush(stdin);
}

void proc_estilo(){
	char filtroEstilo[50];
	fflush(stdin);
	printf("Digite um Estilo: ");
	gets(filtroEstilo);
	fflush(stdin);
	for(int t = 0; t < TAM; t++){
		if(strcmp(vetlivro[t].estilo, filtroEstilo) == 0){
			printf("Código: %i, autor: %s, título: %s, estilo: %s, preço: %.2f\n\n", vetlivro[t].cod, vetlivro[t].autor, vetlivro[t].titulo, vetlivro[t].estilo, vetlivro[t].preco);
			break;
		}
	}
	fflush(stdin);
}

void media_preco(){
	fflush(stdin);
	
	float soma=0,media=0;
	
	for(int t = 0; t < TAM; t++){
		soma = soma + vetlivro[t].preco;
	}
	
	media = soma/(float)(numlivros);
	printf("\n\nO preco médio dos livros eh de R$%.2f\n", media);
	fflush(stdin);
}
