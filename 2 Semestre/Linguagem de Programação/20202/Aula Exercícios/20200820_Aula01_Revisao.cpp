#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

const float pi = 3.14;

int main() {
	int escolha;
	setlocale(LC_ALL, "Portuguese");
	
	printf("Os exercícios de Revisão da aula 01 são:\n");
	printf("1 - Faça um programa que calcule e exiba a área de uma região retangular.\n");
	printf("Considere que a largura da região é 7cm, o comprimento é 8cm e a fórmula para calcular a área é: A = LxC.\n");
	printf("=================================================================\n");
	printf("2 - Faça um programa que receba um número e calcule o seu dobro.\n");
	printf("=================================================================\n");
	printf("3 - Um funcionário recebe um salário fixo mais 4% de comissão sobre as vendas.\n");
	printf("Faça um programa que receba o salário fixo de um funcionário e o valor de suas vendas,\n");
	printf("calcule e mostre a comissão e o salário final do funcionário.\n");
	printf("=================================================================\n");
	printf("4 - Faça um programa que calcule e exiba o volume de uma lata de óleo,\n");
	printf("utilizando a fórmula: VOLUME = PI * RAIO2 * ALTURA e considerando que PI = 3,14.\n");
	printf("=================================================================\n\n");
	printf("Esolha um dos exercícios acima:");
	scanf("%i", &escolha);
	
	if(escolha == 1){
		int l = 7;
		int c = 8;
		int a = l*c;
		printf("%.i", a);
	}else if(escolha == 2){
		int numero;
		scanf("%i", &numero);
		int dobro = numero *2;
		printf("%.i", dobro);
	}else if(escolha == 3){
		float salario;
		float vendas;
		float sf;
		
		printf("Digite o valor do salário:");
		scanf("%f", &salario);
		printf("Digite o valor de venda: ");
		scanf("%f", &vendas);
		sf = ((vendas/100)*4) + salario;
		printf("%.2f", sf);
	}else{
		float raio, altura, volume;
	
		printf ("Informe o raio: ");
		scanf ("%f", &raio);
		printf ("Informe a altura: ");
		scanf ("%f", &altura);
	
		volume = pi * (raio*raio) * altura;
	
		printf ("\nO volume da lata de oleo eh: %.2f", volume);	
	}
	
	return 0;
}

