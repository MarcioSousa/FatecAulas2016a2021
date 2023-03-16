#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Entregar até dia 29/03.
//======== Classes separadas =======
int zeraPorto();
int carregaPorto();
int carregaVetoPeso();
int testeMostraValorVetorPeso();
int carregarNavio();
int limpaNavio();

//==================================
int peso[200];
int navio[4][16];
int qtdeTotal = 0;
int setor[4];

int main(){
	setlocale(LC_ALL,"Portuguese");
	
	zeraPorto();
	
	do{
		carregaPorto();
	    carregaVetoPeso();
	    carregarNavio();
	
    	limpaNavio();
    	//printf("%i\n", qtdeTotal);
    	printf("====================================================================\n");
	} while (qtdeTotal != 0);
	
	printf("=== Você conseguiu carregar todo os containners no Navio com sucesso! ===\n======== Sistema Encerrado ======\n");
    return 0;
}

int zeraPorto(){
	for (int t =0; t <200; t++){
		peso[t] = 0;
	}
}

int carregaPorto(){
	int qtdeCarregar = 0;
	
	do{
		printf("Digite a quantidade de Containers que chegou ao porto: ");
		scanf("%i", &qtdeCarregar);
		
		if((qtdeTotal + qtdeCarregar) > 200){
			printf("No porto não pode ter acima de 200 Containers.\nTotal de Containers no momento é de: %i\n", qtdeTotal);
			printf("-------------------------------------------------------------\n");
		}

	}while((qtdeTotal + qtdeCarregar) > 200);
	
	qtdeTotal = qtdeTotal + qtdeCarregar;
}

int carregaVetoPeso(){
	int pesoVerif;

	for(int t = 0; t < qtdeTotal; t++){
		if(peso[t] == 0){
			printf("Digite o peso (em Toneladas) do %dº Container: ", t + 1);
			scanf("%i", &pesoVerif);
			
			if((pesoVerif < 16) && (pesoVerif > 0)){
				peso[t] = pesoVerif;
			}else{
				printf("Peso não aceito. Digite entre 0 a 15\n");
				t--;
			}
		}
	}
}

int carregarNavio(){
	int cont = 0;
	int posi0 = 0, posi1 = 0, posi2 = 0, posi3 = 0;
	

	setor[0] = 0;
	setor[1] = 0;
	setor[2] = 0;
	setor[3] = 0;
	
	//Arrumar (looping de 4 por 4 acrescentando um, lembrar na sexta feira! 
	do{
		if((setor[0] <= setor[1]) && (setor[0] <= setor[2]) && (setor[0] <= setor[3])){
			navio[0][posi0] = peso[cont];
			setor[0] = setor[0] + peso[cont];
			peso[cont] = 0;
			posi0++;
		} else if((setor[1] <= setor[0]) && (setor[1] <= setor[2]) && (setor[1] <= setor[3])){
			navio[1][posi1] = peso[cont];
			setor[1] = setor[1] + peso[cont];
			peso[cont] = 0;
			posi1++;
		} else if((setor[2] <= setor[0]) && (setor[2] <= setor[1]) && (setor[2] <= setor[3])){
			navio[2][posi2] = peso[cont];
			setor[2] = setor[2] + peso[cont];
			peso[cont] = 0;
			posi2++;
		} else {
			navio[3][posi3] = peso[cont];
			setor[3] = setor[3] + peso[cont];			
			peso[cont] = 0;
			posi3++;
		}
		cont++;
	}while(cont != qtdeTotal);
	
	printf("\n======Setores do Navio Carregado!=========\n");
	printf("1 = %i         2 = %i          3 = %i          4 = %i\n", setor[0], setor[1], setor[2], setor[3]);
	
	//=====Carregando todos em ordem no navio=====
	for(int t = 0; t < 4; t++){
		for(int u = 12; u < 16; u++){
			if(navio[t][u] < 10){
				printf("0%i ", navio[t][u]);
				if(navio[t][u] != 0){
					qtdeTotal = qtdeTotal - 1;
				}
			} else {
				printf("%i ", navio[t][u]);
				if(navio[t][u] != 0){
					qtdeTotal = qtdeTotal - 1;
				}
			}
		}
		printf(" | ");
	}
	printf("\n");
	
	for(int t = 0; t < 4; t++){
		for(int u = 8; u < 12; u++){
			if(navio[t][u] < 10){
				printf("0%i ", navio[t][u]);
				if(navio[t][u] != 0){
					qtdeTotal = qtdeTotal - 1;
				}
			} else {
				printf("%i ", navio[t][u]);
				if(navio[t][u] != 0){
					qtdeTotal = qtdeTotal - 1;
				}
			}
		}
		printf(" | ");
	}
	printf("\n");
	
	for(int t = 0; t < 4; t++){
		for(int u = 4; u < 8; u++){
			if(navio[t][u] < 10){
				printf("0%i ", navio[t][u]);
				if(navio[t][u] != 0){
					qtdeTotal = qtdeTotal - 1;
				}
			} else {
				printf("%i ", navio[t][u]);
				if(navio[t][u] != 0){
					qtdeTotal = qtdeTotal - 1;
				}
			}
		}
		printf(" | ");
	}
	printf("\n");
		
	for(int t = 0; t < 4; t++){
		for(int u = 0; u < 4; u++){
			if(navio[t][u] < 10){
				printf("0%i ", navio[t][u]);
				if(navio[t][u] != 0){
					qtdeTotal = qtdeTotal - 1;
				}
			} else {
				printf("%i ", navio[t][u]);
				if(navio[t][u] != 0){
					qtdeTotal = qtdeTotal - 1;
				}
			}
		}
		printf(" | ");
	}
	printf("\n");
}

int limpaNavio(){
	for(int t =0; t<4; t++){
		for(int u = 0; u < 16; u++){
			navio[t][u] = 0;
		}
	}
	
}
