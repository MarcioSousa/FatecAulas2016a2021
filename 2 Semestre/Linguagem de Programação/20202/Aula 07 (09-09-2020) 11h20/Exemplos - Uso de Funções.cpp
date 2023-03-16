#include <stdio.h>
#include <stdlib.h>

//Fazer um programa que crie uma função que calcule o dobro de um numero
/*int Dobro (int x)
{
	int res_dobro;
	res_dobro = x * 2;
	
	return res_dobro;	
}
main()
{
	int num;
	printf ("Informe um numero: ");
	scanf ("%d", &num);
	
	//res = num * 2; 

	printf ("\nO dobro do numero %d eh %d", num, Dobro (num));
}

//Faça um programa que receba o raio e altura de uma lata de óleo e crie uma função para calcular o seu volume, 
//utilizando a fórmula: VOLUME = PI * RAIO2 * ALTURA e considerando que PI = 3,14.
#define pi 3.14

float Volume (float r, float a)
{
	float res_vol;
	
	res_vol = pi * (r*r) * a;
	
	return res_vol;
}
main()
{
	float raio, altura, volume;
	
	printf ("Informe o raio: ");
	scanf ("%f", &raio);
	printf ("Informe a altura: ");
	scanf ("%f", &altura);
	
	volume = Volume (raio, altura);
	
	printf ("\nO volume da lata de oleo eh: %.2f", volume);	
}*/

//Um funcionário recebe um salário fixo mais 4% de comissão sobre as vendas. Faça um programa que receba o salário fixo 
//de um funcionário e o valor de suas vendas e crie funções para:
//1 - Calcular e mostrar a sua comissão
//2 - Calcular e mostrar o salário final do funcionário.
float Calc_comiss (float vvendas)
{
	float res_comiss;
	
	res_comiss = vvendas * 0.04;
	
	return res_comiss;
}
float Calc_vfinal (float sf, float vc)
{
	float res_vfinal;
	
	res_vfinal = sf + vc;
	
	return res_vfinal;
}
main()
{
	float salfixo, valvendas, salfinal;
	
	printf ("Informe o salario fixo: ");
	scanf ("%f", &salfixo);
	printf ("Informe o valor de vendas: ");
	scanf ("%f", &valvendas);
	
	printf ("\nO valor de comissao eh: %.2f", Calc_comiss(valvendas));
	
	salfinal = Calc_vfinal (salfixo, Calc_comiss(valvendas));
	
	printf ("\nO salario final eh: %.2f", salfinal);	
}
