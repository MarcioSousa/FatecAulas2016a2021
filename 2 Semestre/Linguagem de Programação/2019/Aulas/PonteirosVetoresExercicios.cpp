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
	printf("======= Digite o Exercício: =======\n");
	scanf("%i", &exer);
	
	if(exer == 6){
		printf("USANDO PORNTEIROS, ESCREVA UM PROGRAMA QUE IMPRIMA UM VETOR NA ORDEM INVERSA.");
		
		
	}else if(exer == 7){
		printf("USANDO PONTEIRO, ESCREVA UMA FUNÇÃO QUE RECEBA UMA STRING (O ENDEREÇO DE MEMÓRIA ONDE ELA ESTÁ ALOCADA) E EXIBA-A AO CONTRÁRIO. EXEMPLO: AMARELO--->OLERAMA.");
	}

	system("pause");
}

