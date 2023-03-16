//Escreva uma função que recebe por parâmetro um valor inteiro e positivo N e retorna o valor de S.
//S = somatório(i=1, i<=n) ((n^2)+1)/(n+3)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

float f_S(int v_n2);

main()
{
	int v_n1;
	printf("Informe o numero inteiro: ");
	scanf("%d",&v_n1);
	printf("O valor de S eh: %f",f_S(v_n1));
}

float f_S(int v_n2)
{
int i;
float v_Result=0;

for (i = 1; i<=v_n2; i++)
{
	v_Result = v_Result + (((i * i) + 1) / float(i + 3));
}

return v_Result;
}
