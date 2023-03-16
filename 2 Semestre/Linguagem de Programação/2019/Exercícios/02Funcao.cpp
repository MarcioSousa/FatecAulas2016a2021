#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//VARIÁVEIS GLOBAIS
int a, b, c;

void F_ENTRADA();
int F_SOMAR(int, int);
void V_POSNEG(int);
void E_VALORES();
void CAL_DELTA();

main(){
	//VARIÁVEIS LOCAIS
	setlocale(LC_ALL, "Portuguese");

	int ne;
	
	printf("================================================\n");
	printf("==== EXERCÍCIOS DE LINGUAGEM DE PROGRAMAÇÃO ====\n");
	printf("==============  FUNCOES ========================\n");
	printf("================================================\n\n");
	printf("EXEMPLOS DOS EXERCÍCIOS, DIGITE 0.\n");	
	printf("DIGITE O NÚMERO DO EXERCÍCIO(1 ao 9): ");
	scanf("%d", &ne);
	fflush(stdin);
	
	if(ne == -1){
		printf("=====================================================\n");
		printf("|FAÇA UM PROGRAMA QUE RECEBA 2 NÚMEROS PARES,       |\n");
		printf("|CALCULE A SOMA ENTRE ELES E EXIBA O RESULTADO. EM  |\n");
		printf("|SEQUIDA RECEBA 2 NÚMEROS ÍMPARES, CALCULE A SOMA   |\n");
		printf("|ENTRE ELES E TAMBÉM EXIBA O RESULTADO.             |\n");
		printf("|RESULTADO SEM FUNÇÃO:                              |\n");
		printf("=====================================================\n\n");
		
		int soma;
		printf("Informe 2 números pares: ");
		scanf("%d", &a);
		scanf("%d", &b);
		
		if(a%2 == 0 && b%2 == 0){
			soma = a + b;
			printf("A soma dos pares é: %d", soma);
		}
		
		printf("Informe 2 números ímpares: ");
		scanf("%d", &a);
		scanf("%d", &b);
		
		if(a%2 != 0 && b%2 != 0){
			soma = a + b;
			printf("A soma dos ímpares é: %d", soma);
		}
		
	}else if(ne == 0){
		printf("=====================================================\n");
		printf("|FAÇA UM PROGRAMA QUE RECEBA 2 NÚMEROS PARES,       |\n");
		printf("|CALCULE A SOMA ENTRE ELES E EXIBA O RESULTADO. EM  |\n");
		printf("|SEQUIDA RECEBA 2 NÚMEROS ÍMPARES, CALCULE A SOMA   |\n");
		printf("|ENTRE ELES E TAMBÉM EXIBA O RESULTADO.             |\n");
		printf("|RESULTADO COM FUNÇÃO:                              |\n");
		printf("=====================================================\n\n");
		
		int soma;
		
		F_ENTRADA();
		//printf("Informe 2 números pares: ");
		//scanf("%d", &a);
		//scanf("%d", &b);
		
		if(a%2 == 0 && b%2 == 0){
			soma = F_SOMAR(a, b);
			printf("A soma dos pares é: %d", soma);
		}
		
		F_ENTRADA();
		//printf("Informe 2 números ímpares: ");
		//scanf("%d", &a);
		//scanf("%d", &b);
		
		if(a%2 != 0 && b%2 != 0){
			soma = F_SOMAR(a, b);
			printf("A soma dos ímpares é: %d", soma);
		}
	}else if( ne == 1){
		printf("=====================================================\n");
		printf("|FAÇA UM PROGRAMA QUE RECEBA 1 NÚMERO E, ATRAVÉS DE |\n");
		printf("|UMA FUNÇÃO, VERIFIQUE SE ELE É POSITIVO OU         |\n");
		printf("|NEGATIVO.                                          |\n");
		printf("=====================================================\n\n");
		
		int num = 0;
		printf("Digite um número: ");
		scanf("%d", &num);
		
		V_POSNEG(num);

	}else if(ne == 2){
		printf("=====================================================\n");
		printf("|FAÇA UM PROGRAMA  QUE:                             |\n");
		printf("|CRIE UMA FUNÇÃO PARA RECEBER 3 VALORES (a, b, c);  |\n");
		printf("|CRIE UMA FUNÇÃO QUE CALCULE O VALOR DE DELTA,      |\n");
		printf("|ATRAVÉS DA FÓRMULA:                                |\n");
		printf("|                DELTA = B² - 4 * 4 * C             |\n");
		printf("=====================================================\n\n");
		
		E_VALORES();
		CAL_DELTA();
		
	}
}

//EXEMPLOS===============================
//TIPO DE RETORNO, NOME, PARÂMETROS	
int F_SOMAR(int x, int y){
	int calc_soma;
	calc_soma = x + y;
	return calc_soma;
}

//VOID NÃO RETORNA NADA
void F_ENTRADA(){
	printf("Informe 2 números: ");
	scanf("%d", &a);
	scanf("%d", &b);
}
//=======================================
//VERIFICA SE UM NÚMERO É POSITIVO OU NEGATIVO
void V_POSNEG(int numero){
	if(numero%2 == 0){
		printf("Este número é positivo\n");
	}else{
		printf("Este número é negativo.\n");
	}
	
}
//===========================================
//RECEBENDO 3 VALORES
void E_VALORES(){
	printf("Digite o valor de A: ");
	scanf("%d", &a);
	printf("Digite o valor de B: ");
	scanf("%d", &b);
	printf("Digite o valor de C: ");
	scanf("%d", &c);
}

void CAL_DELTA(){
	int delta = 0;
	delta = (b * b) - 4 * a * c;
	printf("O valor de delta (%d² - 4 * %d * %d)é: %d", b, a, c, delta);
}
//=============================================



