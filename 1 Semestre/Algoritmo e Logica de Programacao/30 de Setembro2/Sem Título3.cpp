#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main(){
	setlocale(LC_ALL,"Portuguese");
	
	int usuario;
	float resultado, num1, num2;
	
	printf("Digite o Primeiro número: ");
	scanf("%f", &num1);
	
	printf("Digite o Segundo número: ");
	scanf("%f", &num2);
	
	printf("Digite o código do Usuário (1 a 4): ");
	scanf("%d", &usuario);
	
	switch(usuario){
		case 1:
			resultado = (num1 + num2) / 2;
			printf("A média aritmética entre %.2f e %.2f é: %.0f", num1, num2, resultado);
			break;
		case 2:
			if(num1 > num2){
				resultado = num1 - num2;
			}
			else{
				resultado = num2 - num1;
			}
			printf("A diferença entre o maior e o menos é: %.0f", resultado);
			break;	
		case 3:
			resultado = num1 * num2;
			printf("O produto dos dois números digitados é: %.0f", resultado);
			break;
		case 4:
			resultado = num1 / num2;
			printf("A divisão entre o primeiro e o segundo número é: %.1f", resultado);
			break;
	}
	
	
	
}
