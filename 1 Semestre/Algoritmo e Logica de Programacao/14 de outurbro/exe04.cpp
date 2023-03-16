#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main(){
	setlocale(LC_ALL, "Portuguese");
	
	int par = 0, impar = 0, numero = 0, somaimpares = 0, somapares = 0, mediaimpares = 0;

	for (int t=1; t <=10; t++)
	{
		printf("Digite o %dº Número: ", t);
		scanf("%d", &numero);
	
		if (numero %2 == 0)
		{
			somapares = somapares + numero;
			par = par +1;
		}
		else
		{
			somaimpares = somaimpares + numero;
			impar = impar + 1;
		}
	}
	
	mediaimpares = somaimpares / impar;
	
	printf("\nA qtde de números pares é: %d", par);
	printf("\nA qtde de números impares é: %d", impar);
	printf("\nA soma dos números pares é: %d",somapares);
	printf("\nA média dos números impares é: %d",mediaimpares);	
	
}
