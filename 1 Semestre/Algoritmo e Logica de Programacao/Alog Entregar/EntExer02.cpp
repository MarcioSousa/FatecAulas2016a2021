#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Biblioteca necessária para usar o SETLOCALE()
#include <conio.h>
#include <string.h> //Necessário para strlen

void carregaVetores();
void somaVetores();
void mediaVetores();
void zeroNegativo();
void numRepetido();

float vetores[12];
//=====POSITIVO SOMA É 52,6====
//=====NEGATIVO SOMA É 15,4====
//==========A SOMA É 37,2======

main(){
	setlocale(LC_ALL, "Portuguese"); //Instrução usada para configurar o idioma Português.
	
	carregaVetores();
	printf("\n================================== RESULTADO ==================================================\n");
	somaVetores();
	mediaVetores();
    zeroNegativo();
	numRepetido();
	
	printf("===============================================================================================\n");
    system("PAUSE");
}

void carregaVetores(){
	//CARREGA OS VETORES AUTOMATICAMENTE, DEPOIS É NECESSÁRIO RETIRAR
//	vetores[0] = 2;
//	vetores[1] = 5;
//	vetores[2] = -6.8;
//	vetores[3] = 9;
//	vetores[4] = 2;
//	vetores[5] = -3.5;
//	vetores[6] = 9;
//	vetores[7] = 7;
//	vetores[8] = 3.2;
//	vetores[9] = 7;
//	vetores[10] = -5.1;
//	vetores[11] = 8.4;
	
	for(int t=0 ; t<12 ; t++){
		printf("Digite um valor inteiro ou decimal ao %dº Vetor: ", t+1);
		scanf("%f", &vetores[t]);
	    fflush(stdin);
	}
}

void somaVetores(){
	float soma = 0;
	for(int t = 0; t < 12; t++){
		soma = soma + vetores[t];
	}
	printf("A soma de todos os Vetores é: %.2f\n", soma);
}

void mediaVetores(){
	float soma = 0;
	float media = 0;
	
	for(int t =0; t < 12; t++){
		soma = soma + vetores[t];
	}
	media = soma / 12;
	printf("A média dos Vetores é: %.2f\n", media);
}

void zeroNegativo(){
	printf("Substituir por Zero os \n");
	printf("Negativos : ");
	for(int t = 0; t < 12; t++){
		if(t != 11){
			if(vetores[t]<0){
				vetores[t] = 0;
	     	}
	   	printf(" %.2f |", vetores[t]);	
		}
		else{
			if(vetores[t]< 0){
				vetores[t] = 0;
			}
			printf(" %.2f\n", vetores[t]);
		}
	}
}

void numRepetido(){
	for(int t = 0; t < 12; t++){
		for(int a = t + 1; a < 12; a++){	
			if(vetores[t] == vetores[a] && vetores[t] > 0 && vetores[t] > 0){
				vetores[t] = 0;
				vetores[a] = 0;
			}
		}
	}
	
	//=========== MOSTRAR RESULTADOS ==========
	printf("Repet. > 0: ");
	
	for(int b = 0; b < 12; b++){
		if(b != 11){
			printf(" %.2f |", vetores[b]);
		}
		else{
			printf(" %.2f\n", vetores[b]);
		}
	}
}
