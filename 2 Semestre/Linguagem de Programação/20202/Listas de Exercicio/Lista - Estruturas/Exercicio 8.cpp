#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


// declaração de variáveis
struct livro
{
	char titulo[100];
	char autor[50];
	char estilo[30];
	int codigo;
	float preco;
};
struct livro vetlivro[10];
char ch;
int i,numlivros = 0;
// definição da função menu( ):
void menu( )
{
	printf (" Digite I para incluir um livro. \n");
	printf (" Digite L para listar o nome de todos os livros. \n");
	printf (" Digite A para procurar livro por autor. \n");
	printf (" Digite T para procurar livro por titulo. \n");
	printf (" Digite E para procurar livro por estilo. \n");
	printf (" Digite M para calcular a media de preco de todos os livros. \n");
	printf ( "Digite S para sair \n");
	scanf ("%c", &ch);
}



void incluir_liv( )
{
	fflush(stdin);
	printf("\nInforme o nome do livro: ");
	gets(vetlivro[numlivros].titulo);
	fflush(stdin);
	printf("\nInforme o autor do livro: ");
	gets(vetlivro[numlivros].autor);
	fflush(stdin);
	printf("\nInforme o estilo do livro: ");
	gets(vetlivro[numlivros].estilo);
	fflush(stdin);
	printf("\nInforme o codigo do livro: ");
	scanf("%d", &vetlivro[numlivros].codigo);
	fflush(stdin);
	printf("\nInforme o preco do livro: ");
	scanf("%f", &vetlivro[numlivros].preco);
	printf("\n");
	numlivros++;
}



void lista_liv( )
{
	fflush(stdin);
	printf("\n\nListagem de livros:\n");
	for (i=0; i<numlivros; i++)
	{
		printf("Livro %d: %s.\n", i+1, vetlivro[i].titulo);
	}
	printf("\n\n\n");
}



void proc_autor( )
{
	fflush(stdin);
	char buscaautor[50];
	printf("\nInforme o nome do autor procurado: ");
	gets(buscaautor);
	fflush(stdin);
	for(i=0; i<numlivros; i++)
	{
		if(strcmp(buscaautor, vetlivro[i].autor)==0)
		{
			printf("Livro: %s\n\n", vetlivro[i].titulo);
			
		}
	}

}



void proc_titulo( )
{
	fflush(stdin);
	char buscatitulo[100];
	printf("\nInforme o titulo do livro procurado: ");
	gets(buscatitulo);
	fflush(stdin);
	for(i=0; i<numlivros; i++)
	{
		if(strcmp(buscatitulo, vetlivro[i].titulo)==0)
		{
			printf("Livro: %s, Autor: %s\n\n", vetlivro[i].titulo, vetlivro[i].autor);
			
		}
	}

}



void proc_estilo( )
{
	fflush(stdin);
	char buscaestilo[30];
	printf("\nInforme o estilo de livro procurado: ");
	gets(buscaestilo);
	fflush(stdin);
	for(i=0; i<numlivros; i++)
	{
		if(strcmp(buscaestilo, vetlivro[i].estilo)==0)
		{
			printf("Livro: %s, Autor: %s\n\n", vetlivro[i].titulo, vetlivro[i].autor);
			
		}
	}

}



void media_preco( )
{
	fflush(stdin);
	float soma=0.0,media;
	
	for(i=0;i<numlivros;i++);
	{
		soma=soma+vetlivro[i].preco;
	}
	media = soma/(float)(numlivros);
	printf("\n\nO preco medio dos livros eh de R$%.2f\n\n", media);
}


// definição da função principal
int main( )
{
menu( );
while (ch != 'S')
{
switch(ch)
{
case 'I': incluir_liv( ); break;
case 'L': lista_liv( ); break;
case 'A': proc_autor( ); break;
case 'T': proc_titulo( ); break;
case 'E': proc_estilo( ); break;
case 'M': media_preco( ); break;
} // fim do switch
menu( );
}




} // fim da função main.
