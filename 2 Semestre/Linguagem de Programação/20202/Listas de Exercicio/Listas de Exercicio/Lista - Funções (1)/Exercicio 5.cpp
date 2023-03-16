//Escreva uma função que recebe um valor inteiro e verifica se o valor é par ou ímpar. A
//função deve retornar um valor booleano (true ou false).

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool f_Par_Impar(int v_Num);

main()
{
	int v_Numero=0;
	printf("Informe o numero que deseja verificar: ");
	scanf("%d",&v_Numero);
	if(f_Par_Impar(v_Numero) == true)
	printf("\nO numero %d eh par.",v_Numero);
	else
	printf("\nO numero %d eh impar.",v_Numero);
}

bool f_Par_Impar(int v_Num)
{
	if(v_Num%2==0)
	return true;
	else
	return false;
}
