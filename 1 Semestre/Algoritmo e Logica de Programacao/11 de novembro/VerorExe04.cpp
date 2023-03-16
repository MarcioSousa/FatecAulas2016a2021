#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Biblioteca necessária para usar o SETLOCALE()

void primeiroVetor();
void segundoVetor();
void calculoVetores();
void mostrandoResultado();

int numero1[5];
int numero2[5];
int resultado[5];

main(){
	setlocale(LC_ALL, "Portuguese"); //Instrução usada para configurar o idioma Português.
	
    primeiroVetor();
	segundoVetor();
	calculoVetores();
	mostrandoResultado();
	
}

void mostrandoResultado(){
	printf("==== Resultado ====\n");
	for(int t = 0; t < 5; t++){
		printf("%d\n", resultado[t]);
	}
}

void calculoVetores(){
	for(int t =0; t < 5; t++){
		resultado[t] = numero1[t] * numero2[t];
	}
}

void primeiroVetor(){
	printf("==== Primeira Lista ====\n");
	
	for (int t = 0; t < 5; t++){
		printf("Digite o %dº Valor Inteiro: ", t+1);
		scanf("%d", &numero1[t]);
	}
}

void segundoVetor(){
	printf("\n==== Segunda Lista ====\n");
	
	for (int t = 0; t < 5; t++){
		printf("Digite o %dº Valor Inteiro: ", t+1);
		scanf("%d", &numero2[t]);
	}
}
