#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Biblioteca necessária para usar o SETLOCALE()
#include <conio.h>
#include <string.h> //Necessário para strlen

main(){
	setlocale(LC_ALL, "Portuguese"); //Instrução usada para configurar o idioma Português.
	
	char frase[50];
	
	printf("Digite uma frase de até 50 caracteres: ");
	gets(frase);
	
	system("PAUSE");
}
