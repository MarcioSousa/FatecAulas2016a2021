#include <stdio.h>
#include <stdlib.h>

main(){
	int exercicio;
	float valorProduto,valorVenda;
	
	printf("Entre com o numero do exercicio: ");
	scanf("%d", &exercicio);
	
	if (exercicio == 1){
		printf("\n==========Exercicio 1===========\n");
		printf("================================\n");

        printf("Entre com o Valor do Produto: ");
        scanf("%f", &valorProduto);
    
        if (valorProduto > 20){
    	    valorVenda = valorProduto*1.45;
            printf("O valor e: %.2f", valorVenda);
	    }
        else{
    	    valorVenda = valorProduto*1.3;
            printf("O valor e: %.2f", valorVenda);
	    }
	}
	else if (exercicio == 2){
		printf("\n==========Exercicio 2===========\n");
	}
	


    
    //system("PAUSE");
}

