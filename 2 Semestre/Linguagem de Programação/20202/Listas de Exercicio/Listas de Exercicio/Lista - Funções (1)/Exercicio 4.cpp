//Escreva uma função que recebe, por parâmetro, a altura (alt) e o sexo de uma pessoa e
//retorna o seu peso ideal. Para homens, calcular o peso ideal usando a fórmula peso ideal =
//72.7 x alt - 58 e, para mulheres, peso ideal = 62.1 x alt - 44.7.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f_Peso_Ideal(float alt, char sex);

main()
{
	float v_altura;
	char v_sexo;
	printf("\nInforme seu sexo (H = homem e M = mulher): ");
	scanf("%c",&v_sexo);
	printf("\nInforme sua altura: ");
	scanf("%f",&v_altura);
	printf("\n Seu peso ideal eh: %f", f_Peso_Ideal(v_altura, v_sexo));
}

float f_Peso_Ideal(float alt, char sex)
{
	float peso;
	if (sex=='M')
		peso = (62.1*alt) - 44.7;
	else
		peso = (72.7*alt) - 58;
	return peso;
}
