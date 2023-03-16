#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Biblioteca necessária para usar o SETLOCALE()

main(){
	setlocale(LC_ALL, "Portuguese"); //Instrução usada para configurar o idioma Português.
	
	int divisor, inicio, final, resultado = 0;
	
	printf("Entre com o valor do divisor: ");
	scanf("%d", &divisor);
	
	printf("Início do intervalor: ");
	scanf("%d", &inicio);
	
	printf("Final do intervalo: ");
	scanf("%d", &final);
	
	printf("Números divisíveis por %d no intervalo de %d a %d:\n", divisor, inicio, final);
	
	while (inicio <= final)
	{
		if (inicio%divisor == 0)
		{
			printf("%d ", inicio);	
		}
		inicio++;
	}
	
}
