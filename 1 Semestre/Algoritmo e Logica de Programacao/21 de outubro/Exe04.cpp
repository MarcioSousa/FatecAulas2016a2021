#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Biblioteca necessária para usar o SETLOCALE()

main(){
	setlocale(LC_ALL, "Portuguese"); //Instrução usada para configurar o idioma Português.
	
	int numero = 0, cont = -1, soma = 0, media;
	
	printf("======= DIGITE NÚMEROS INTEIROS =======\n=======================================\n\n");
	
	do
	{
		cont ++;
		
		printf("Positivo p/ calcular, negativo ou zero para encerrar: ");
		scanf("%d", &numero);
		
		soma = soma + numero;
		
	} while ((numero % 2 == 0) && (numero != 0));
	
	if (cont != 0)
	{
		media = soma / cont;
	}

	printf("O resultado é %.2d.", media);
}
