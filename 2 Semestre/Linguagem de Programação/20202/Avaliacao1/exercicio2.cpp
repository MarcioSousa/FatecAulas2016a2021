#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define TAM 5
void incluir_livros();
void emprestimo_livro(int codigo, int qtde);

struct livro {
	int codigo;
	char titulo[50];
	float preco;
	int numeroexemplares;
};

// declaração de variáveis
struct livro biblioteca[TAM];
int codigolivroemprestado;
int qtde;
char ch;
int numlivros = 0;

int main(){
	
	setlocale(LC_ALL, "Portuguese"); 
	incluir_livros();
	
	printf("Ler emprestimo.\nInforme o código do livro: ");
	scanf("%i", &codigolivroemprestado);
	fflush(stdin);
	printf("Informe a quantidade: ");
	scanf("%i", &qtde);
	fflush(stdin);
	
	emprestimo_livro(codigolivroemprestado, qtde);
	
}

void incluir_livros(){
	for(int t = 0; t < TAM; t++){
		fflush(stdin);
		printf("== Inclusão do Livro %i ==", t+1);
		printf("\nCódigo do livro: ");
		scanf("%d", &biblioteca[numlivros].codigo);
		fflush(stdin);
		printf("Título do livro: ");
		gets(biblioteca[numlivros].titulo);
		fflush(stdin);
		printf("Preço do livro: ");
		scanf("%f", &biblioteca[numlivros].preco);
		printf("Número de exemplares do livro: ");
		scanf("%i", &biblioteca[numlivros].numeroexemplares);
		fflush(stdin);
		printf("\n");
		numlivros++;
		fflush(stdin);
	}
}


void emprestimo_livro(int codigo, int qtde){
	int v = 0;
	for(int t = 0; t < TAM; t++){
		if(codigo == biblioteca[t].codigo){
			printf("Livro Encontrado.\n");
			if(qtde <= biblioteca[t].numeroexemplares){
				biblioteca[t].numeroexemplares = biblioteca[t].numeroexemplares - qtde;
				printf("Número exemplares Atualizado: %i\n", biblioteca[t].numeroexemplares);
			}else{
				printf("mas não há quantidade necessária\nQtde Atual %i\n", biblioteca[t].numeroexemplares);
			}
			v = 1;
			break;
		}
	}
	
	if (v == 0){
		printf("Livro não encontrado no sistema.\n");
	}
}


