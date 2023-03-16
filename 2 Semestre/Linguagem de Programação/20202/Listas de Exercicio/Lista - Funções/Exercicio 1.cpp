//Escreva uma função que receba um valor e informe se ele é positivo ou não.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool f_Pos_Neg(float v_Res);

main()
{
	float v1;
	printf("Digite o valor do numero:\t");
	scanf("%f",&v1);
	if (f_Pos_Neg(v1) == false)
		printf("\nEste numero eh negativo!");
	else
		printf("\nEste numero eh positivo!");
}

bool f_Pos_Neg(float v_E1)
{
	int v_Res;
	if (v_E1 < 0)
		v_Res = false;
	else
		v_Res = true;
	return v_Res;
}


