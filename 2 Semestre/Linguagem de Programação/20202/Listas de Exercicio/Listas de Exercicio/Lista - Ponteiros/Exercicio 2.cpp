#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Escreva uma fun��o que dado um n�mero real passado como par�metro, retorne a parte inteira e a parte fracionaria deste n�mero.
//Escreva um programa que chama esta fun��o. (Prot�tipo: void frac (float num, int *inteiro, float *frac))

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
