#include <stdio.h>
#include <stdlib.h>

//int vetor[10];
//int matriz[10][10];

//matriz[9][9];

//int vetor[10];
//int navio[64];
//int i,j;
//for (i=0; i<10; i++)
//    vetor[i] = 0;


int armacontaiporto(int qtde){
	if(qtde <= 200){
		printf("Menor ou igual a 200");
	} else {
		printf("Maior que 200");
	}
}

int inserircontainer(){
	int peso;
	
	for(int cont = 0; cont <= 200 ; cont++){
		scanf("Digite o peso do Container: %i", &peso);
		printf("%i\n", cont);
	}
}

int main() {
	int qtdeContainers;
	double peso;
	
	scanf("%i", &qtde);
	scanf("%lf", &peso);
	
	inserircontainer();
    return 0;
}
