#include <stdio.h>
#include <stdlib.h>
#define LUGARES 48

void carregarDesenho();
void carregarPoltronas();
int lugar[46];

int main(){
	int i, opcao, x; //janela = impares, poltrona = pares
	
	printf("             Gerenciamento de Onibus\n");
	carregarPoltronas();
	carregarDesenho();
	
	do {
		printf("Digite a opcao desejada:\n");
        printf("(1) Ocupar uma poltrona\n(2) Consultar poltrona\n(4) Sair\n-->");
        scanf("%d", &opcao);
        system("CLS");
        
        if(opcao == 1){
        	printf("Digite qual poltrona deseja ocupar: ");
        	scanf("%i", &x);
        	if(lugar[x-1] != -1){
        		lugar[x-1] = -1;
        		printf("Poltrona ocupada com sucesso.\n");
			}else{
				printf("Poltrona já ocupada. Escolha outra Poltrona.\n");
			}
		}
		else if(opcao == 2){
			system("CLS");
			carregarDesenho();
		}
		carregarDesenho();
    } while (1);
	
}

void carregarDesenho(){
	printf("------------------------------------------------\n");
	
	for(int t = 44; t >=0; t--){
		if((t+1) >= 10){
			if(lugar[t] != -1){
				printf("|%i|", lugar[t]);
			}else{
				printf("|**|");
			}
			
		}else{
			if(lugar[t] != -1){
				printf("|0%i|", lugar[t]);
			}else{
				printf("|**|");
			}
		}
		t = t-3;
	}
	
	printf("\n");
	
	for(int u = 45; u >=1; u--){
		if((u+1) >= 10){
			if(lugar[u] != -1){
				printf("|%i|", lugar[u]);
			}else{
				printf("|**|");
			}
			
		}else{
			if(lugar[u] != -1){
				printf("|0%i|", lugar[u]);
			}else{
				printf("|**|");
			}
			
		}
		u = u-3;
	}
	
	printf("\n------------------------------------------------\n");
	printf("\n                   CORREDOR                     \n");
	printf("\n------------------------------------------------\n");
	
	printf("|  |");
	for(int t = 43; t >=1; t--){
		if((t+1) >= 10){
			if(lugar[t] != -1){
				printf("|%i|", lugar[t]);
			}else{
				printf("|**|");
			}
		}else{
			if(lugar[t] != -1){
				printf("|0%i|", lugar[t]);	
			} else{
				printf("|**|");
			}
		}
		t = t-3;
	}

	printf("\n");
	printf("|  |");
	for(int u = 42; u >=1; u--){
		if((u+1) >= 10){
			if(lugar[u] != -1){
				printf("|%i|", lugar[u]);
			}else{
				printf("|**|");
			}
			
		}else{
			if(lugar[u] != -1){
				printf("|0%i|", lugar[u]);
			}else{
				printf("|**|");
			}
			
		}
		u = u-3;
	}
	
	printf("\n------------------------------------------------\n");
	
}

void carregarPoltronas(){
	for(int u=0; u<46; u++){
		lugar[u] = u+1;
	}
}
