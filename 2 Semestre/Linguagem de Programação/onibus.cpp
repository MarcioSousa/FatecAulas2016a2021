#include <stdio.h>
#include <stdlib.h>
#define LUGARES 48


void ocupar(int janela[], int poltrona[]);
void consultar(int janela[], int poltrona[]);
void carregaDesenho();

int main(){
    int i, opcao, janela[LUGARES], poltrona[LUGARES]; //janela = impares, poltrona = pares
	
    carregaDesenho();

    for(i=0;i<LUGARES;i++){
        if(i%2){
            janela[i] = 0;
            poltrona[i] = -1;
        } else {
            janela[i] = -1;
            poltrona[i] = 0;
        }
    }

    printf("\tGerenciamento de Onibus\nDigite a opcao desejada:\n");
    do {
        printf("(1) Ocupar uma poltrona\n(2) Consultar poltrona\n(4) Sair\n-->");
        scanf("%d", &opcao);
        system("CLS");


        switch(opcao){
            case 1: ocupar(janela, poltrona); break;
            case 2: consultar(janela, poltrona); break;
            case 4: exit(1); break;
        }

    } while (1);

    return(0);
}

void ocupar(int janela[], int poltrona[]){
    int x;
    printf("Digite qual poltrona deseja ocupar: ");
    scanf("%d", &x);
    if(x%2){
        janela[x] = 1;
    } else {
        poltrona[x] = 1;
    }
    printf("Poltrona ocupada com sucesso.\n");
}

void consultar(int janela[], int poltrona[]){
    int x;
    printf("Digite qual poltrona deseja consultar: ");
    scanf("%d", &x);
    if(x%2){
        if(janela[x]){
            printf("Esta poltrona esta ocupada.\n");
        } else {
            printf("Esta poltrona esta livre.\n");
        }
    } else {
        if(poltrona[x]){
            printf("Esta poltrona esta ocupada.\n");
        } else {
            printf("Esta poltrona esta livre.\n");
        }
    }
}

void ocupacao(int janela[], int poltrona[]){
    int i;
    for(i=0;i<LUGARES;i++){
        if(i%2){
            if(janela[i]){
                printf("Poltrona %d (janela) = ocupada.\n", i);
            } else {
                printf("Poltrona %d (janela) = livre.\n", i);
            }
        } else {
            if(poltrona[i]){
                printf("Poltrona %d (corredor) = ocupada.\n", i);
            } else {
                printf("Poltrona %d (corredor) = livre.\n", i);
            }
        }
    }
}

void carregaDesenho(){
	printf("------------------------------------------------\n");
	
	
	for(int t = 45; t >=1; t--){
		if(t >= 10){
			printf("|%i|", t);
		}else{
			printf("|0%i|", t);
		}
		t = t -3;
	}
	
	printf("\n------------------------------------------------\n");
	
	
}
