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
	printf("======= Digite o exemplo =======\n");
	scanf("%i", &exer);
	
	if(exer == 1){
		int vetor[] = {10, 50, 20, 30};
		//declarando valor do tipo ponteiro
		int *pv;
	
		pv = vetor; //(Ou pv = &vetor[0]);
	
		//ENDEREÇO
		//0x00101
		//0x00102
		//0x00103 [_ _ _ 10 50 20 30 _ _ _]
		//...
		for(int i = 0; i < 4; i++){
			printf("%d, %d\n", *pv, pv);
			pv++;
		}
		
	}else if(exer == 2){
		int vetor[] = {1, 2, 3, 4, 5, 6, 7};
		
		int *pv;
		
		pv = vetor;
		
		for(int t = 0; t < 7; t++){
			printf("%d\n", *pv);
			pv+=2;
		}
		
		printf("======================================\n");
		for(int t = 0; t < 7; t++){
			printf("%d %d %d\n\n", vetor[t], *pv, pv);
		}
		

		
	}

	system("pause");
}

