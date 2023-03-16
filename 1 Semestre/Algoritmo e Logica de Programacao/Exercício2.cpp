//EXERCICIO 2: FAÇA UM PROGRAMA QUE RECEBA 2 NUMEROS E CALCULE:
//-- A SOMA ENTRE ELES
//-- O PRODUTO ENTRE ELES
//-- AO FINAL, MOSTRE OS RESULTADOS:
#include <stdio.h>
#include <stdlib.h>

main(){
	float num1, num2, soma, produto;
	
	printf("Digite o primeiro numero: ");
	scanf("%f", &num1);
	
	printf("Digite o segundo numero: ");
	scanf("%f", &num2);
	
	soma = num1 + num2;
	produto = num1 * num2;
	
	printf("RESULTADO:\n");
	printf("Soma: %f \n", soma);
	printf("Produto: %f \n", produto);
	
	system("pause");
}
