#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int escolha;
	setlocale(LC_ALL, "Portuguese");
	
	printf("Escolha a estrutura.\n");
	printf("1 - For.\n2 - While.\n3 - Do...While.\n");
	scanf("%i", &escolha);
	
	if(escolha == 1){
		int exercicio;
		printf("Digite o exercício: ");
		scanf("%i", &exercicio);
		
		if(exercicio == 1){
			int numero;
			int par = 0;
			int impar = 0;

			for(int t = 0; t < 10; t++){
				printf("Digite o %iº número: ", t+1);
				scanf("%i", &numero);
				if(numero%2==0){
					par++;
				}else{
					impar++;
				}
			}
			printf("Qtde pares: %i, Qtde impares: %i\n",par, impar);
		}else{
			int num;
			for(int t = 0; t < 5; t++){
				
				printf("Digite um número: ");
				scanf("%i", &num);
				
				if(num%2 != 0){
					break;
				}
				
			}
		}
		
	}else if(escolha == 2){
		int exercicio;
		printf("Digite o exercício: ");
		scanf("%i", &exercicio);
		
		if(exercicio == 1){
			char vinho;
			int qtde = 0;
			int tinto = 0;
			int branco = 0;
			int rose = 0;
		
			fflush(stdin);
		
			printf("Digite t para tinto, b para branco ou R para rose: ");
			scanf("%c", &vinho);
		
			while(vinho != 'f'){
				if(vinho == 't'){
					printf("Quantidade de vinho Tinto: ");
					scanf("%i", &qtde);
					tinto += qtde;
				}else if(vinho == 'b'){
					printf("Quantidade de vinho Branco: ");
					scanf("%i", &qtde);
					branco += qtde;
				}else if(vinho == 'r'){
					printf("Quantidade de vinho Rosê: ");
					scanf("%i", &qtde);
					rose += qtde;
				}else{
					break;
				}
				fflush(stdin);
				printf("Digite t para tinto, b para branco ou R para rose: ");
				scanf("%c", &vinho);
			}
			
			printf("Rose: %i, Branco: %i, Tinto: %i\n", rose, branco, tinto);
			
		}else{
			int cont = 0;
			int numero;
			int maior = 0;
			
			while(cont < 10){
				printf("Digite o %iº número: ", cont +1);
				scanf("%i", &numero);
				
				if(cont != 0 && maior < numero){
					maior = numero;
				}
				
				cont ++;
			}
			
			printf("O maior número é: %i\n", maior);
		}	

	}else if(escolha == 3){
		int exercicio;
		printf("Digite o exercício: ");
		scanf("%i", &exercicio);
		
		if(exercicio == 1){
			int positivo = 0;
			float media = 0;
			int qtde = 0;
			int soma = 0;
		
			do{
				printf("digite um número positivo, negativo para sair ou zero para sair: ");
				scanf("%i", &positivo);
			
				if(positivo > 0 && positivo%2 == 0){
					soma += positivo;
					qtde++;
				}else{
					break;
				}
			
			}while(positivo > 0);
		
			media = float(soma) / qtde;
			printf("A média dos números digitados é %.2f\n.", media);
		}else{
			int um;
			int dois;
			int qtde = -1;
			
			do{
				qtde ++;
				printf("Digite dois números inteiros: ");
				scanf("%i %i", &um, &dois);
				
			}while(um%dois == 0);
			
			printf("Qtde digitados %i\n.", qtde);
		}
		
	}
	
	return 0;
}
