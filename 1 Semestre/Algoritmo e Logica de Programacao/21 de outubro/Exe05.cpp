#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Biblioteca necess�ria para usar o SETLOCALE()

main(){
	setlocale(LC_ALL, "Portuguese"); //Instru��o usada para configurar o idioma Portugu�s.
	
	int numero = 0, numeromaior = 0, t = 0;
	
	while(t < 10)
	{
		t++;
		printf("Digite o %d� N�mero: ", t);
		scanf("%d", &numero);
		
		if(numero > numeromaior)
		{
			numeromaior = numero;
		}
	}
	
	printf("O N�mero maior �: %d\n", numeromaior);
	
}
