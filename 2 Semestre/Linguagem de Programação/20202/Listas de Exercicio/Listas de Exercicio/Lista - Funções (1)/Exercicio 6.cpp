#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int f_Idade_Dias (int v_Anos, int v_Meses, int v_Dias);

main()
{
	int v_Id_Anos, v_Id_Meses, v_Id_Dias;
	printf("Informe quantos anos tem de vida: ");
	scanf("%d",&v_Id_Anos);
	printf("\nInforme quantos meses tem de vida (alem dos anos): ");
	scanf("%d",&v_Id_Meses);
	printf("\nInforme quantos dias tem de vida (alem dos anos e meses): ");
	scanf("%d",&v_Id_Dias);
	printf("\nVoce tem %d dias de vida.", f_Idade_Dias(v_Id_Anos,v_Id_Meses,v_Id_Dias));
}

int f_Idade_Dias(int v_Anos, int v_Meses, int v_Dias)
{
	int v_Result = 0;
	v_Result = v_Anos*365 + v_Meses*30 + v_Dias;
	return v_Result;
}

