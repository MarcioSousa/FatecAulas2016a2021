#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Biblioteca necessária para usar o SETLOCALE()
#include <conio.h>
#include <string.h> //Necessário para strlen

main(){
	setlocale(LC_ALL, "Portuguese"); //Instrução usada para configurar o idioma Português.
	
	char string1[20], string2[20];
	
	printf("Digite um valor para passar a string1 com até 20 caracteres: ");
	gets(string1);
	
	strcpy(string2, string1);
	
	printf("O valor da string2 é: %s\n", string2);
	
	system("PAUSE");
	
}
