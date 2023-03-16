#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL,"Portuguese");
	int vetor[10];
	int entrada, numero, qtde =0, x = 0;
	int valores[10];
	
	vetor[0] = 10;
	vetor[1] = 20;
	vetor[2] = 1;
	vetor[3] = 2;
	vetor[4] = 4;
	vetor[5] = 8;
	vetor[6] = 19;
	vetor[7] = 19;
	vetor[8] = 2;
	vetor[9] = 1;
	
	scanf("%i", &entrada);
	
	for(int t =0; t<10; t++){
		valores[t] = 0;
	}
	
	for(int t = 0; t<10; t++){
		printf("%i ", vetor[t]);
	}
	printf("\n");
	
	for(int t = 0; t< 10; t++){
		if(vetor[t] == entrada){
			numero = vetor[t];
			valores[x] = vetor[t];
			qtde++;
			x++;
		}
	}
	
	printf("%i\n", numero);
	printf("%i\n", qtde);
	
	for(int t = 0; t<10; t++){
		printf("%i\n", valores[t]);
		if(valores[t] == 0){
			break;
		}
	}
}

