#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Biblioteca necess�ria para usar o SETLOCALE()

main(){
	setlocale(LC_ALL, "Portuguese"); //Instru��o usada para configurar o idioma Portugu�s.
	
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
	
	printf("S�o divis�veis %d N�mero(s).\n", cont);
}
