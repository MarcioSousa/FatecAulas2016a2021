#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Biblioteca necess�ria para usar o SETLOCALE()
#include <conio.h>
#include <string.h> //Necess�rio para strlen

main(){
	setlocale(LC_ALL, "Portuguese"); //Instru��o usada para configurar o idioma Portugu�s.
	
	char string1[20], string2[20];
	
	printf("Digite um valor para passar a string1 com at� 20 caracteres: ");
	gets(string1);
	
	strcpy(string2, string1);
	
	printf("O valor da string2 �: %s\n", string2);
	
	system("PAUSE");
	
}
