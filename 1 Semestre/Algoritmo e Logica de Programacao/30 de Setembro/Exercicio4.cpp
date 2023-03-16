#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main(){
	setlocale(LC_ALL,"Portuguese");
	
	int num1, num2;
	char atribuicao;
	float resultado;
	
	printf("Digite o Primeiro Número: ");
	scanf("%d", &num1);
	
	printf("Digite o Segundo Número: ");
	scanf("%d", &num2);
	
	fflush(stdin);
	printf("Digite qual operação deseja fazer: ");
	scanf("%c", &atribuicao);
	
	switch(atribuicao){
		case '+':
			resultado = num1 + num2;
			printf("A soma dos dois números é: %.0f", resultado);
			break;
		case '-':
			resultado = num1 - num2;
			if(num1 > num2){
				printf("A subtração entre os dois números é: %.2f", resultado);
			}
			else{
				printf("Numero 1 é menor que número dois, então dará negativo \n A subtração entre os dois números é: %.2f", resultado);
			}
		case '*':
			resultado = num1 * num2;
			printf("A Multiplicação dentre os dois números é: %.2f", resultado);
			break;
		case '/':
			resultado = num1 / num2;
			printf("A divisão entre os dois números é: %.2f", resultado);
			break;
		default:
			printf("Não existe essa operação matemática...");
    }
}
