#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Biblioteca necess�ria para usar o SETLOCALE()
#include <conio.h>
#include <string.h> //Necess�rio para strlen

main(){
	setlocale(LC_ALL, "Portuguese"); //Instru��o usada para configurar o idioma Portugu�s.
	
	char nome[50], result[4];
	
	printf("Digite um nome: ");
	gets(nome);
	
	strncpy(result, nome,4);
	
	printf("As 4 primeiras letras s�o: %s", result);
	
	system("PAUSE");
}
