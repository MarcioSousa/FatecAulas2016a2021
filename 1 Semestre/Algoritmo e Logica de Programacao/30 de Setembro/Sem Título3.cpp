#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main(){
	setlocale(LC_ALL,"Portuguese");
	
	int usuario;
	float resultado, num1, num2;
	
	printf("Digite o Primeiro n�mero: ");
	scanf("%f", &num1);
	
	printf("Digite o Segundo n�mero: ");
	scanf("%f", &num2);
	
	printf("Digite o c�digo do Usu�rio (1 a 4): ");
	scanf("%d", &usuario);
	
	switch(usuario){
		case 1:
			resultado = (num1 + num2) / 2;
			printf("A m�dia aritm�tica entre %.2f e %.2f �: %.0f", num1, num2, resultado);
			break;
		case 2:
			if(num1 > num2){
				resultado = num1 - num2;
			}
			else{
				resultado = num2 - num1;
			}
			printf("A diferen�a entre o maior e o menos �: %.0f", resultado);
			break;	
		case 3:
			resultado = num1 * num2;
			printf("O produto dos dois n�meros digitados �: %.0f", resultado);
			break;
		case 4:
			resultado = num1 / num2;
			printf("A divis�o entre o primeiro e o segundo n�mero �: %.1f", resultado);
			break;
	}
	
	
	
}
