#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//VARI�VEIS GLOBAIS
int a, b, c;

void F_ENTRADA();
int F_SOMAR(int, int);
void V_POSNEG(int);
void E_VALORES();
void CAL_DELTA();

main(){
	//VARI�VEIS LOCAIS
	setlocale(LC_ALL, "Portuguese");

	int ne;
	
	printf("================================================\n");
	printf("==== EXERC�CIOS DE LINGUAGEM DE PROGRAMA��O ====\n");
	printf("==============  FUNCOES ========================\n");
	printf("================================================\n\n");
	printf("EXEMPLOS DOS EXERC�CIOS, DIGITE 0.\n");	
	printf("DIGITE O N�MERO DO EXERC�CIO(1 ao 9): ");
	scanf("%d", &ne);
	fflush(stdin);
	
	if(ne == -1){
		printf("=====================================================\n");
		printf("|FA�A UM PROGRAMA QUE RECEBA 2 N�MEROS PARES,       |\n");
		printf("|CALCULE A SOMA ENTRE ELES E EXIBA O RESULTADO. EM  |\n");
		printf("|SEQUIDA RECEBA 2 N�MEROS �MPARES, CALCULE A SOMA   |\n");
		printf("|ENTRE ELES E TAMB�M EXIBA O RESULTADO.             |\n");
		printf("|RESULTADO SEM FUN��O:                              |\n");
		printf("=====================================================\n\n");
		
		int soma;
		printf("Informe 2 n�meros pares: ");
		scanf("%d", &a);
		scanf("%d", &b);
		
		if(a%2 == 0 && b%2 == 0){
			soma = a + b;
			printf("A soma dos pares �: %d", soma);
		}
		
		printf("Informe 2 n�meros �mpares: ");
		scanf("%d", &a);
		scanf("%d", &b);
		
		if(a%2 != 0 && b%2 != 0){
			soma = a + b;
			printf("A soma dos �mpares �: %d", soma);
		}
		
	}else if(ne == 0){
		printf("=====================================================\n");
		printf("|FA�A UM PROGRAMA QUE RECEBA 2 N�MEROS PARES,       |\n");
		printf("|CALCULE A SOMA ENTRE ELES E EXIBA O RESULTADO. EM  |\n");
		printf("|SEQUIDA RECEBA 2 N�MEROS �MPARES, CALCULE A SOMA   |\n");
		printf("|ENTRE ELES E TAMB�M EXIBA O RESULTADO.             |\n");
		printf("|RESULTADO COM FUN��O:                              |\n");
		printf("=====================================================\n\n");
		
		int soma;
		
		F_ENTRADA();
		//printf("Informe 2 n�meros pares: ");
		//scanf("%d", &a);
		//scanf("%d", &b);
		
		if(a%2 == 0 && b%2 == 0){
			soma = F_SOMAR(a, b);
			printf("A soma dos pares �: %d", soma);
		}
		
		F_ENTRADA();
		//printf("Informe 2 n�meros �mpares: ");
		//scanf("%d", &a);
		//scanf("%d", &b);
		
		if(a%2 != 0 && b%2 != 0){
			soma = F_SOMAR(a, b);
			printf("A soma dos �mpares �: %d", soma);
		}
	}else if( ne == 1){
		printf("=====================================================\n");
		printf("|FA�A UM PROGRAMA QUE RECEBA 1 N�MERO E, ATRAV�S DE |\n");
		printf("|UMA FUN��O, VERIFIQUE SE ELE � POSITIVO OU         |\n");
		printf("|NEGATIVO.                                          |\n");
		printf("=====================================================\n\n");
		
		int num = 0;
		printf("Digite um n�mero: ");
		scanf("%d", &num);
		
		V_POSNEG(num);

	}else if(ne == 2){
		printf("=====================================================\n");
		printf("|FA�A UM PROGRAMA  QUE:                             |\n");
		printf("|CRIE UMA FUN��O PARA RECEBER 3 VALORES (a, b, c);  |\n");
		printf("|CRIE UMA FUN��O QUE CALCULE O VALOR DE DELTA,      |\n");
		printf("|ATRAV�S DA F�RMULA:                                |\n");
		printf("|                DELTA = B� - 4 * 4 * C             |\n");
		printf("=====================================================\n\n");
		
		E_VALORES();
		CAL_DELTA();
		
	}
}

//EXEMPLOS===============================
//TIPO DE RETORNO, NOME, PAR�METROS	
int F_SOMAR(int x, int y){
	int calc_soma;
	calc_soma = x + y;
	return calc_soma;
}

//VOID N�O RETORNA NADA
void F_ENTRADA(){
	printf("Informe 2 n�meros: ");
	scanf("%d", &a);
	scanf("%d", &b);
}
//=======================================
//VERIFICA SE UM N�MERO � POSITIVO OU NEGATIVO
void V_POSNEG(int numero){
	if(numero%2 == 0){
		printf("Este n�mero � positivo\n");
	}else{
		printf("Este n�mero � negativo.\n");
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
	printf("O valor de delta (%d� - 4 * %d * %d)�: %d", b, a, c, delta);
}
//=============================================



