#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Biblioteca necess�ria para usar o SETLOCALE()
#include <conio.h>
#include <string.h> //Necess�rio para strlen

main(){
	setlocale(LC_ALL, "Portuguese"); //Instru��o usada para configurar o idioma Portugu�s.
	
	char nome[50];
	
	printf("Digite um nome: ");
	gets(nome);
	
	for(int t=1; t<strlen(nome); t = t+2){
		printf("%c\n", nome[t]);
	}
	
	system("PAUSE");
}
