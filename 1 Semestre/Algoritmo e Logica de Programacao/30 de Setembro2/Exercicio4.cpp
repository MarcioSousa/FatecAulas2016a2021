#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main(){
	setlocale(LC_ALL,"Portuguese");
	
	int num1, num2;
	char atribuicao;
	float resultado;
	
	printf("Digite o Primeiro N�mero: ");
	scanf("%d", &num1);
	
	printf("Digite o Segundo N�mero: ");
	scanf("%d", &num2);
	
	fflush(stdin);
	printf("Digite qual opera��o deseja fazer: ");
	scanf("%c", &atribuicao);
	
	switch(atribuicao){
		case '+':
			resultado = num1 + num2;
			printf("A soma dos dois n�meros �: %.0f", resultado);
			break;
		case '-':
			resultado = num1 - num2;
			if(num1 > num2){
				printf("A subtra��o entre os dois n�meros �: %.2f", resultado);
			}
			else{
				printf("Numero 1 � menor que n�mero dois, ent�o dar� negativo \n A subtra��o entre os dois n�meros �: %.2f", resultado);
			}
		case '*':
			resultado = num1 * num2;
			printf("A Multiplica��o dentre os dois n�meros �: %.2f", resultado);
			break;
		case '/':
			resultado = num1 / num2;
			printf("A divis�o entre os dois n�meros �: %.2f", resultado);
			break;
		default:
			printf("N�o existe essa opera��o matem�tica...");
    }
}
