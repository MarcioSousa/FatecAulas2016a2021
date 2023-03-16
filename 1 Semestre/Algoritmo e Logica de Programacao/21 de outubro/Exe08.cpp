#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Biblioteca necessária para usar o SETLOCALE()

main(){
	setlocale(LC_ALL, "Portuguese"); //Instrução usada para configurar o idioma Português.
	
	int numero1, numero2, cont = -1;
	
	do
	{
		printf("Digite o dividendo: ");
		scanf("%d", &numero1);
		
		printf("Digite o divisor: ");
		scanf ("%d", &numero2);
		printf("----------------------\n");
		cont++;
	} while (numero1%numero2 == 0);
	
	printf("São divisíveis %d Número(s).\n", cont);
}
