/*1. Fa�a um programa que receba uma string frase e chame uma fun��o que verifique se o valor digitado para a string 
foi "SIM" ou "N�O".
A fun��o dever� retornar 1 se o valor de frase for "SIM" e 0 se o valor de frase for "N�O". A fun��o s� deve retornar 
alguma coisa se o valor da string for "SIM" ou "N�O".*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*int F_Verifica (char f[], int x);

main()
{
	char frase [50];
	int num;
	
	printf ("Digite a frase: ");
	gets (frase);
	
	num = F_Verifica(frase, 50);
	
	if (num == 1)
		printf ("\nVoce digitou SIM!!!");
	else
	{
		if (num == 0)
			printf ("\nVoce digitou NAO!!!");
		else
			printf ("\nVoce nao digitou nem SIM nem NAO!!!");
	}
	
}

int F_Verifica (char f[], int x)
{
	if (strcmp (f, "SIM") == 0|| strcmp (f, "sim") == 0)
		return 1;
	if (strcmp (f, "NAO") == 0 || strcmp (f, "nao") == 0)
		return 0;	
}*/

/*2.	Defina uma estrutura Livro com os membros: c�digo (int), titulo (string[30]), preco (float) e n�mero de 
exemplares(int).

a.	Crie um vetor Biblioteca de tamanho 5 e armazene as informa��es desses 5 livros.
b.	Leia um empr�stimo, ou seja, solicite que o usu�rio informe um c�digo de produto e uma quantidade pedida. 
c.	Verifique se o livro existe (o c�digo informado existe no vetor Biblioteca). 
d.	Se o livro existir, e se houver n�mero de exemplares suficiente para atender ao empr�stimo, atualize o estoque 
(n�mero de exemplares - quantidade pedida) e mostre ao usu�rio o c�digo do livro, o t�tulo desse livro e essa "nova" 
quantidade calculada.
e.	Se o livro n�o existir, informe o usu�rio.*/

#define max 3

struct livro
{
	int		cod;
	char	titulo[30];
	float	preco;
	int		numex;
};


main()
{
	struct livro biblioteca[max];
	int i, cod, quant;
	
	for (i=0; i<max; i++)
	{
		printf ("\n");
		printf ("Digite um codigo: ");
		scanf ("%d", &biblioteca[i].cod);
		fflush (stdin);
		fflush (stdin);
		printf ("Digite um titulo: ");
		gets (biblioteca[i].titulo);
		fflush (stdin);
		printf ("Digite o preco: ");
		scanf ("%f", &biblioteca[i].preco);
		fflush (stdin);
		printf ("Digite o numero de exemplares: ");
		scanf ("%d", &biblioteca[i].numex);
		fflush (stdin);			
	}	
	
	//Socicitando um emprestimo
	printf ("\n--- SOLICITANDO UM EMPRESTIMO ---");
	printf ("\nDigite um codigo: ");
	scanf ("%d", &cod);
	fflush (stdin);
	printf ("Digite a quantidade solicitada: ");
	scanf ("%d", &quant);
	fflush (stdin);
	
	//Verificando se o livro existe
	for (i=0; i<max; i++)
	{
		if (biblioteca[i].cod == cod)
		{
			if (biblioteca[i].numex >= quant)
			{
				biblioteca[i].numex = biblioteca[i].numex - quant;
				
				printf ("\n\n%d - %s - %d", biblioteca[i].cod, biblioteca[i].titulo, biblioteca[i].numex);
			}
			else
				printf ("\n\nNao existe quantidade suficiente deste livro !!!");
		}
		else
			printf ("\n\nLivro nao existe !!!");
	}
}

