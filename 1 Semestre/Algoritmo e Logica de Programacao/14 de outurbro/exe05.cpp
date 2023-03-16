#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main(){
	setlocale(LC_ALL, "Portuguese");
	
	int numero, resultado = 1;
	
	printf("Digite um número inteiro para poder fatorar: ");
	scanf("%d", &numero);
	
	for (int t=1; t<=numero; t++){
		
		printf("Resultado das contas é: %d\n", t);
		resultado = resultado * t;
	}
	
	printf("\nO resultado é: %d", resultado);
}
