//Faça um programa que receba 3 valores - a, b e c. Crie uma função que receba estes 3
//valores, que são os coeficientes de uma equação do segundo grau e retorne o valor do
//delta, que é dado por 'b² - 4ac'

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f_DELTA(float v1, float v2, float v3);

main()
{
	float delta, a, b, c;
	printf("Informe o valor de a: ");
	scanf("%f",&a);
	printf("\nInforme o valor de b: ");
	scanf("%f",&b);
	printf("\nInforme o valor de c: ");
	scanf("%f",&c);
	printf("\nO valor de DELTA eh: %f", f_DELTA(a,b,c));
}

float f_DELTA(float v1, float v2, float v3)
{
	float v_DeltaRES;
	v_DeltaRES = (v2*v2) - 4*v1*v3;
	return v_DeltaRES;
}
