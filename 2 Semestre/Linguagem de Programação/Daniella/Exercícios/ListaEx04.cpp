#include <stdio.h>
#include <stdlib.h>

int main(){
	float tempo, velocidade, distancia, litrosUs;
	
	printf("Digite a tempo: ");
	scanf("%f", &tempo);
	
	printf("Digite a valocidade: ");
	scanf("%f", &velocidade);
	
	distancia = tempo * velocidade;
	
	litrosUs = distancia/12;
	
	printf("A velocidade media é de: %f\n", velocidade);
	printf("O tempo gasto na viagem: %f\n", tempo);
	printf("A distancia media e: %f\n", distancia);
	printf("A qtde de litros usados e: %f\n", litrosUs);
}
