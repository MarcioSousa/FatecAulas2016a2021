#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Biblioteca necess�ria para usar o SETLOCALE()
#include <conio.h>
#include <string.h> //Necess�rio para strlen

main(){
	setlocale(LC_ALL, "Portuguese"); //Instru��o usada para configurar o idioma Portugu�s.

	char frase[50];
	int tamanho;

	printf("Digite uma frase: ");
	gets(frase);
	
	tamanho = strlen(frase);
	printf("O tamanho da string %s vale %d\n\n", frase, tamanho);
	
	system("PAUSE");
}
