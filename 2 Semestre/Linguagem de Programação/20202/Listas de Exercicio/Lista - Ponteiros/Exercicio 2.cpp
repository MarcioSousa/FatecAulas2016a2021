#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Escreva uma função que dado um número real passado como parâmetro, retorne a parte inteira e a parte fracionaria deste número.
//Escreva um programa que chama esta função. (Protótipo: void frac (float num, int *inteiro, float *frac))

void frac (float num, int *inteiro, float *frac);

main()
{
	float x, frac_x;
	int int_x;
	
	printf("Escreva o numero real: ");
	scanf("%f",&x);
	
	frac (x, &int_x, &frac_x);
	
	printf("\nNumero %.2f - parte inteira: %d e parte fracionaria: %.2f", x, int_x, frac_x);
	
}

void frac (float num, int *inteiro, float *frac)
{
	*inteiro = trunc(num);
	*frac = num-(*inteiro);
}
