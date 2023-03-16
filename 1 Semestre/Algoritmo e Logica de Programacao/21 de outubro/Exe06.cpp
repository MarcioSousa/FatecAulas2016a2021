#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Biblioteca necessária para usar o SETLOCALE()

main(){
	setlocale(LC_ALL, "Portuguese"); //Instrução usada para configurar o idioma Português.
	
	int vinicial, vfinal, contador;
	
	do{
		printf("Digite o valor Inicial: ");
    	scanf("%d", &vinicial);
	
    	printf("Digite o valor Final: ");
    	scanf("%d", &vfinal);
    	if (vinicial > vfinal)
    	{
    		printf("O valor Inicial não pode ser maior que o valor Final! Digite novamente...\n");
		}
	} while (vinicial > vfinal);
	
	contador = vinicial;
	vfinal = vfinal +1;
	
	do
	{
		printf("%d\n", contador);
		contador ++;
	} while(vfinal != contador);
	
	printf("Terminou");
	
}
