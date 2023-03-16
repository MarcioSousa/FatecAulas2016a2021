#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Faça um programa que leia uma string de N elementos e um caractere qualquer e chame uma função que verifique quantas vezes esse caractere aparece na string.
//Use a aritmética de ponteiros para acessar os caracteres da string e a função deverá seguir o seguinte protótipo: void conta_caractere (char *ps, int N, char c, int *qtde)

void conta_caractere (char *ps, int N, char c, int *qtde);

main()
{
	char string[100], l;
	int i, qtd=0;

	printf("Informe a string: ");
	gets(string);
	printf("Informe o caracter que deseja verificar: ");
	scanf("%c",&l);
	
	conta_caractere (string, strlen(string), l, &qtd);
	
	printf("O caracter '%c' aparece %d vezes na string '%s'", l,qtd,string);

}

void conta_caractere (char *ps, int N, char c, int *qtde)
{
	int i;
	
	for(i=0;i<N;i++,ps++)
	{
		if (*ps == c)
		(*qtde)++;
	}

}
