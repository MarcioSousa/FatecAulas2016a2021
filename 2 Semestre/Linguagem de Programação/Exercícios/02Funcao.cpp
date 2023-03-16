#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//VARI�VEIS GLOBAIS
int a, b, c;

void F_ENTRADA();
int F_SOMAR(int, int);
void V_POSNEG(int numero);
void E_VALORES();
void CAL_DELTA();
int INTEGERPOWER(int, int);
float PESO_IDEAL(float altura, char sexo);

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
	}else if(ne == 1){
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
		
	}else if(ne == 3){
		printf("=====================================================\n");
		printf("|ESCREVA UMA FUN��O CHAMADA INTEGERPOWER(BASE,      |\n");
		printf("|EXPOENTE) QUE RETORNE O VALOR DE. POR EXEMPLO,     |\n");
		printf("|INTEGERPOWER (3,4) = 3 * 3 * 3 * 3. SUPONHA QUE    |\n");
		printf("|EXPOENTE SEJA UM INTEIRO DIFERENTE DE ZERO E A BASE|\n");
		printf("|SEJA UM INTEIRO. A FUN��O INTEGERPOWER DEVE USAR   |\n");
		printf("|FOR OU WHILE PARA CONTROLAR O C�LCULO.)            |\n");
		printf("=====================================================\n\n");
		
		int total, base, expoente;
		printf("Insira o valor da Base: ");
		scanf("%d", &base);
		printf("Insira o valor do Expoente: ");
		scanf("%d", &expoente);
		
		total = INTEGERPOWER(base, expoente);
		
		printf("O resultado de ");
		
		for(int t = 0; t < expoente; t++){
			if(t == expoente - 1){
				printf("%d = ", base);
			}else{
				printf("%d * ", base);
			}
		}

		printf("%d\n", total);

	}else if(ne == 4){
		printf("=====================================================\n");
		printf("|ESCREVA UMA FUN��O QUE RECEBE, POR PAR�METRO, A    |\n");
		printf("|ALTURA (ALT) E O SEXO DE UMA PESSOA E RETORNA O SEU|\n");
		printf("|PESO IDEAL. PARA HOMENS, CALCULAR O PESO IDEAL     |\n");
		printf("|USANDO A F�RMULA PESO IDEAL = 72.7 X ALT - 58 E,   |\n");
		printf("|PARA MULHERES, PESO IDEAL = 62.1 X ALT - 44.7.     |\n");
		printf("=====================================================\n\n");
		
		float altura, pid;
		char sexo;
		
		printf("Digite a altura: ");
		scanf("%f", &altura);
		printf("Digite o sexo: 'm' para masculino e 'f' para feminino: ");
		scanf("%c", &sexo);
		fflush(stdin);
		
		pid = PESO_IDEAL(altura, sexo);
		
		printf("O peso ideal �: %.2f\n", pid);
		
	}else if(ne == 5){
	}else if(ne == 6){
	}else if(ne == 7){
	}else if(ne == 8){
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
	printf("O valor de delta (%d� - 4 * %d * %d) �: %d", b, a, c, delta);
}
//=============================================
//EXERC�CIO 03
int INTEGERPOWER(int base, int expoente){
	int total = 1;
	
	for(int t = 0; t < expoente; t++){
		total = total * base;
	}
	
	return total;	
}
//EXERC�CIO 04 - PESO IDEAL
float PESO_IDEAL(float altura, char sexo){
	float pesoIdeal = 0;
	
	if(sexo == 'm'){
		pesoIdeal = 72.7 * altura - 58;
	}else if(sexo == 'f'){
		pesoIdeal = 62.1 * altura - 44.7;
	}
	
	return pesoIdeal;
}



