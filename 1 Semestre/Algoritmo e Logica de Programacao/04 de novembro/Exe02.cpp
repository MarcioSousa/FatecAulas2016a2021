#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Biblioteca necess�ria para usar o SETLOCALE()

float valorDelta(float numA, float numB, float numC);

main(){
	setlocale(LC_ALL, "Portuguese"); //Instru��o usada para configurar o idioma Portugu�s.
	
	float resultado, valorA, valorB, valorC;
	
	printf("Digite o Valor de A da equa��o do segundo grau: ");
	scanf("%f", &valorA);
	
	printf("Digite o Valor de B da equa��o do segundo grau: ");
	scanf("%f", &valorB);
	
	printf("Digite o Valor de C da equa��o do segundo grau: ");
	scanf("%f", &valorC);
	
	resultado = valorDelta(valorA, valorB, valorC);
	
	printf("Delta �: %.2f", resultado);
	
//	system("PAUSE");
}

float valorDelta(float numA, float numB, float numC){
	float resultado;
	
	resultado = (numB * numB) - 4 * (numA * numC);
	return resultado;
}
