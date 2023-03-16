#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Biblioteca necessária para usar o SETLOCALE()
#include <conio.h>
#include <string.h> //Necessário para strlen

main(){
	setlocale(LC_ALL, "Portuguese"); //Instrução usada para configurar o idioma Português.
	
	char nome[50], result[4];
	
	printf("Digite um nome: ");
	gets(nome);
	
	strncpy(result, nome,4);
	
	printf("As 4 primeiras letras são: %s", result);
	
	system("PAUSE");
}
