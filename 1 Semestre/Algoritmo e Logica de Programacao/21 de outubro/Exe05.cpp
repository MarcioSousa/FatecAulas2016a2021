#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Biblioteca necessária para usar o SETLOCALE()

main(){
	setlocale(LC_ALL, "Portuguese"); //Instrução usada para configurar o idioma Português.
	
	int numero = 0, numeromaior = 0, t = 0;
	
	while(t < 10)
	{
		t++;
		printf("Digite o %dº Número: ", t);
		scanf("%d", &numero);
		
		if(numero > numeromaior)
		{
			numeromaior = numero;
		}
	}
	
	printf("O Número maior é: %d\n", numeromaior);
	
}
