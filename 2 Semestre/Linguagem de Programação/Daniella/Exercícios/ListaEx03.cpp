#include <stdio.h>
#include <stdlib.h>

int main(){
	int num;
	int qtdePar = 0, qtdeImpar = 0, somaPares = 0, mediaImpar = 0, somaImpar = 0;

	for(int t = 0; t < 10; t++){
		scanf("%i", &num);
		if(num%2 == 0){
			qtdePar++;
			somaPares = somaPares + num;
		}else{
			qtdeImpar++;
			somaImpar = somaImpar + num;
		}
	}
	
	mediaImpar = somaImpar/qtdeImpar;
	
	printf("A qtde de numeros pares e: %i\n", qtdePar);	
	printf("A qtde de numeros impares e: %i\n", qtdeImpar);	
	printf("A soma dos numeros pares e: %i\n", somaPares);
	printf("A media dos numeros impares e: %i", mediaImpar);
}
