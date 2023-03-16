#include <iostream>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int ex;
	
	printf("==================================================\n");
	printf("============ EXERCÍCIOS PARA ENTREGA =============\n");
	printf("==================================================\n");
	printf("== Digite o número do exercício para executá-lo ==\n");
	printf("==================================================\n");
	scanf("%i", &ex);
	
	if(ex == 1){
		printf("==================================================\n");
		printf("EXERCÍCIO 01 - FAÇA UM PROGRAMA QUE RECEBA VÁRIAS \n");
		printf("IDADES E QUE CALCULE E MOSTRE A MÉDIA DAS IDADES  \n");
		printf("DIGITADAS. FINALIZE DIGITANDO A IDADE IGUAL A -1. \n");
		printf("==================================================\n");
		
		int qtde = 0, idade = 0, somaidade = 0;
		float media = 0;
	
		do{
			printf("Digite uma idade: ");
			scanf("%i", &idade);
		
			if(idade != -1){
				qtde++;
				somaidade = somaidade + idade;
			}
		
		}while(idade != -1);
	
		media = somaidade / float(qtde);
		printf("A média das idades é: %.2f", media);
		
	}else if(ex == 2){
		printf("==================================================\n");
		printf("EXERCÍCIO 02 - FAÇA UM PROGRAMA QUE RECEBA A      \n");
		printf("IDADE, O PESO, A ALTURA E A COR DOS OLHOS         \n");
		printf("(A - AZUL, P - PRETO, V - VERDE E C - CASTANHO) E \n");
		printf("A COR DOS CABELOS (P - PRETO, C - CASTANHO,       \n");
		printf("L - LOIRO E R - RUIVO) DE 20 PESSOAS E MOSTRE:    \n");
		printf("  A) A QUANTIDADE DE PESSOAS COM IDADE SUPERIOR A \n");
		printf("50 ANOS E PESO INFERIOR A 60 QUILOS;              \n");
		printf("  B) A MÉDIA DAS IDADES DAS PESSOAS COM ALTURA    \n");
		printf("INFERIOR A 1,50;                                  \n");
		printf("  C) A PERCENTAGEM DE PESSOAS COM OLHOS AZUIS     \n");
		printf("ENTRE TODAS AS PESSOAS ANALISADAS;                \n");
		printf("  D) A QUANTIDADE DE PESSOAS RUIVAS E QUE NAÕ     \n");
		printf("POSSUEM OLHOS AZUIS.                              \n");
		printf("==================================================\n");
		
		
	}else if(ex == 3){
		Enunciado(ex);
	}else if(ex == 4){
		Enunciado(ex);
	}else if(ex == 5){
		Enunciado(ex);
	}else if(ex == 6){
		Enunciado(ex);
	}else{
		printf("============ EXERCÍCIO NÃO ENCONTRADO ============\n");
		printf("=========== O PROGRAMA FOI FINALIZADO ============\n");
		printf("==================================================\n");
	}
	
}

