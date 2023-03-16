#include <stdio.h>
#include <stdlib.h>

void receberValor();
void somarValor();

int matrizv[12][20];

int a;
int soma;
int qtde;

int main(){
	a = 0;
	
	receberValor();
	
	for(int t =0; t < 20; t++){
		switch (a){
			case 0:
				printf("Janeiro\n");
				break;
			case 1:
				printf("Fevereiro\n");
				break;
			case 2:
				printf("Marco\n");
				break;
			case 3:
				printf("Abril\n");
				break;
			case 4:
				printf("Maio\n");
				break;
			case 5:
				printf("Junho\n");
				break;
			case 6:
				printf("Julho\n");
				break;
			case 7:
				printf("Agosto\n");
				break;
			case 8:
				printf("Setembro\n");
				break;
			case 9:
				printf("Outubro\n");
				break;
			case 10:
				printf("Novembro\n");
				break;
			case 11:
				printf("Dezembro\n");
				break;
		}

		soma = 0;
		somarValor();
		
	    printf("A soma e: %i\n", soma);
	    printf("Quantidade de %i saques.\n", qtde);
	    printf("\n\n");
	    a++;
	}
	
	return 0;
}

void receberValor(){
	
	for(int t = 0; t < 12; t++){
		for(int u = 0; u < 20; u++){
			scanf("%i\n", &matrizv[t][u]);
			
			if(matrizv[t][u] == -1){
				matrizv[t][u] = 0;
				u=20;
			}
		}
	}
}

void somarValor(){
	qtde = 0;
	
	for(int t = 0; t < 20; t++){
		soma = soma + matrizv[a][t];
		if(matrizv[a][t] == 0){
			break;
		}
		qtde ++;
	}
	
}
