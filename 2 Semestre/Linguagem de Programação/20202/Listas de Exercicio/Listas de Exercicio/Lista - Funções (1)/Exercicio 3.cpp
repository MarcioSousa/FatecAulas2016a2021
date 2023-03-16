//Escreva uma função chamada integerPower (base, expoente) que retorne o valor de potencia. Por
//exemplo, integerPower (3, 4) = 3 * 3 * 3 * 3.
//Suponha que expoente seja um inteiro diferente de zero e base seja um inteiro. A função
//integerPower deve usar for ou while para controlar o cálculo. 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f_integerPower(int base, int expoente);

main()
{
	int b,e;
	printf("Informe o valor da base: ");
	scanf("%d",&b);
	printf("\nInforme o valor do expoente: ");
	scanf("%d",&e);
	printf("\nO valor da potencia eh: %f", f_integerPower(b,e));
}

float f_integerPower(int base, int expoente)
{
	float v_Potencia;
	v_Potencia = base;
	int v_cont;
	for (v_cont = 1; v_cont < expoente; v_cont++)
	{
		v_Potencia = v_Potencia * base;
	}
	return v_Potencia;
}
