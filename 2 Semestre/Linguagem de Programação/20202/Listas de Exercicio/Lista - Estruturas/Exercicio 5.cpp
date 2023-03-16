#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TAM 5

char frase[50];
char fraseapos[50];
char ch[1];
int n;
int i;
int j;


main() {
	printf("\nInforme a palavra desejada: ");
	gets(frase);
	fflush(stdin);
	printf("\nInforme a letra que deseja substituir: ");
	gets(ch);
	fflush(stdin);
	printf("\nInforme quantos caracteres deseja substituir: ");
	scanf("%d", &n);
	
	
	if (n >= strlen(frase))
	{
		n = strlen(frase);
	}

	strcpy(fraseapos,frase);
	
	for (j=0; j<n; j++)
	{
		fraseapos[j] = ch[0];
		//memcpy(fraseapos,ch,n);
	}
	
	printf("\nPalavra: %s", frase);
	printf("\nResultado: %s", fraseapos);
}
