#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main(){
	setlocale(LC_ALL, "Portuguese");
	
	int numero, resultado = 1;
	
	printf("Digite um n�mero inteiro para poder fatorar: ");
	scanf("%d", &numero);
	
	for (int t=1; t<=numero; t++){
		
		printf("Resultado das contas �: %d\n", t);
		resultado = resultado * t;
	}
	
	printf("\nO resultado �: %d", resultado);
}
