#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main(){
	setlocale(LC_ALL, "Portuguese");
	
	printf("================================\n");
	printf("==== PONTEIROS E VETORES =======\n");
	printf("========== EXEMPLOS ============\n");
	printf("================================\n");
	
	int exer = 0;
	printf("======= Digite o Exerc�cio: =======\n");
	scanf("%i", &exer);
	
	if(exer == 6){
		printf("USANDO PORNTEIROS, ESCREVA UM PROGRAMA QUE IMPRIMA UM VETOR NA ORDEM INVERSA.");
		
		
	}else if(exer == 7){
		printf("USANDO PONTEIRO, ESCREVA UMA FUN��O QUE RECEBA UMA STRING (O ENDERE�O DE MEM�RIA ONDE ELA EST� ALOCADA) E EXIBA-A AO CONTR�RIO. EXEMPLO: AMARELO--->OLERAMA.");
	}

	system("pause");
}

