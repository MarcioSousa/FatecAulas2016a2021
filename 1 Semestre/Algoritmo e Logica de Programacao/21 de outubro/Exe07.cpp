#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Biblioteca necess�ria para usar o SETLOCALE()

main(){
	setlocale(LC_ALL, "Portuguese"); //Instru��o usada para configurar o idioma Portugu�s.
	
	int divisor, inicio, final, resultado = 0;
	
	printf("Entre com o valor do divisor: ");
	scanf("%d", &divisor);
	
	printf("In�cio do intervalor: ");
	scanf("%d", &inicio);
	
	printf("Final do intervalo: ");
	scanf("%d", &final);
	
	printf("N�meros divis�veis por %d no intervalo de %d a %d:\n", divisor, inicio, final);
	
	while (inicio <= final)
	{
		if (inicio%divisor == 0)
		{
			printf("%d ", inicio);	
		}
		inicio++;
	}
	
}
