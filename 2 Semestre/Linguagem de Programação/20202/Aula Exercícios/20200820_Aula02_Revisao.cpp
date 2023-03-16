#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

const float pi = 3.14;

int main() {
	int escolha;
	setlocale(LC_ALL, "Portuguese");
	
	printf("Os exercícios de Revisão da aula 02 são:\n");
	printf("1 - Um comerciante comprou um produto e quer vendê-lo com um lucro de 45 por cento\nse o valor da compra for menor que R$ 20,00; caso contrário, o lucro será de 30%.\nFaça um programa que receba o valor do produto e imprimir o valor da venda.\n");
	printf("=================================================================\n");
	printf("2 - Faça um programa que leia o ano de nascimento de uma pessoa, calcule e mostre\nsua idade e também verifique e mostre se ela já tem idade para votar (16 anos ou mais)\ne para conseguir Carteira de Habilitação (18 anos ou mais).\n");
	printf("=================================================================\n");
	printf("3 - Escreva um programa que leia o peso em kg e a altura em m de uma determinada\npessoa de forma a calcular o IMC (índice de massa corpórea) da mesmo e exiba uma\ndas frases, conforme for o caso:\n");
	printf("=================================================================\n");
	printf("4 - Escreva um programa que receba dois números e execute as operações a seguir,\nde acordo com a escolha do usuário:\n");
	printf("=================================================================\n\n");
	printf("Esolha um dos exercícios acima:");
	
	scanf("%i", &escolha);
	
	if(escolha == 1){
		float valor;
		float lucro;
		float valorvenda; //100,00
		
		scanf("%f", &valor);
		
		if(valor < 20){
			lucro = valor * 0.45;
			valorvenda = lucro + valor;
		}else{
			lucro = valor * 0.3;
			valorvenda = lucro + valor;
		}
		printf("O valor de venda é %.2f\n", valorvenda);
	}else if(escolha == 2){
		int ano;
		
		printf("Digite o ano: ");
		scanf("%i", &ano);
		
		if((2020 - ano) >= 18){
			printf("Habilitação e Votar\n");
		}else if((2020 - ano) >= 16){
			printf("Votar\n");
		}else{
			printf("Não pode tirar carteira de habilitação e nem votar\n");
		}
	}else if(escolha == 3){
		float peso;
		float altura;
		float imc;
		
		printf("Digite seu peso em kg: ");
		scanf("%f", &peso);
		printf("Digite sua altura: ");
		scanf("%f", &altura);
		
		imc = peso / (altura * altura);
		
		if(imc <= 18.5){
			printf("Você está abaixo do peso.\n");
		}else if(imc <= 25){
			printf("O seu peso está na faixa de normalidade.\n");
		}else if(imc <= 30){
			printf("Você está acima do peso normal.\n");
		}else{
			printf("Obesidade.\n");
		}
				
	}else{
		int escolha;
		float numeroum;
		float numerodois;
		float calculo;
		
		printf("Digite uma escolha: ");
		scanf("%i", &escolha);
		printf("Digite um número: ");
		scanf("%f", &numeroum);
		printf("Digite outro número: ");
		scanf("%f", &numerodois);
		
		switch(escolha){
			case 1:
				calculo = (numeroum + numerodois)/2;
				printf("Média: %.2f\n", calculo);
				break;
				
			case 2:
				if(numeroum > numerodois){
					calculo = numeroum - numerodois;
				}else{
					calculo = numerodois - numeroum;
				}
				printf("Diferença: %.2f\n", calculo);
				break;
			
			case 3:
				calculo = numeroum * numerodois;
				printf("Produto: %.2f\n", calculo);
				break;
			case 4:
				if(numerodois != 0){
					calculo = numeroum / numerodois;
					printf("Divisão: %.2f\n", calculo);
				}
				printf("Não existe divisão por zero.\n");
				break;
			default:
				printf("Valor inválido!\n");
		}
		
	}
	
	return 0;
}

