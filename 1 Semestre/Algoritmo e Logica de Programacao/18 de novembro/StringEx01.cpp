#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Biblioteca necessária para usar o SETLOCALE()
#include <conio.h>
#include <string.h> //Necessário para strlen

main(){
	setlocale(LC_ALL, "Portuguese"); //Instrução usada para configurar o idioma Português.

	char frase[50];
	int tamanho;

	printf("Digite uma frase: ");
	gets(frase);
	
	tamanho = strlen(frase);
	printf("O tamanho da string %s vale %d\n\n", frase, tamanho);
	
	system("PAUSE");
}
