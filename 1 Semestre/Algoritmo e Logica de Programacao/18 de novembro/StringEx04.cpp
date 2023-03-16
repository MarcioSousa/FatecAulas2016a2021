#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Biblioteca necessária para usar o SETLOCALE()
#include <conio.h>
#include <string.h> //Necessário para strlen

main(){
	setlocale(LC_ALL, "Portuguese"); //Instrução usada para configurar o idioma Português.
	
	char nome[50];
	
	printf("Digite um nome: ");
	gets(nome);
	
	for(int t=1; t<strlen(nome); t = t+2){
		printf("%c\n", nome[t]);
	}
	
	system("PAUSE");
}
