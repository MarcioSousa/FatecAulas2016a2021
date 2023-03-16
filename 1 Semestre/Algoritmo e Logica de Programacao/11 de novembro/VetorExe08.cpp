#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Biblioteca necess�ria para usar o SETLOCALE()

void carregaVetores();
float media();
void ordenacao();
float porcentagem();
void melhornota();

float notas[5];

main(){
	setlocale(LC_ALL, "Portuguese"); //Instru��o usada para configurar o idioma Portugu�s.
	carregaVetores();
	printf("A m�dia obtida pelo atreta �: %.2f", media());
	melhornota();
	ordenacao();
	porcentagem();
}
void melhornota(){	
	for(int t =0; t<5; t++){
		if(notas[t] >= 6){
			printf("\nO Juiz %d deu nota alta: %.2f", t +1, notas[t]);
		}
	}
}

float porcentagem(){
	int porcent = 0;
	for(int t=0;t<5;t++){
		if(notas[t]<=8){
			porcent = porcent + 20;
		}
	}
	printf("\nA porcentagem de pontua��o iguais ou superior a 8 s�o de %d por cento!", porcent);
}

void carregaVetores(){
	printf("DIGITE AS NOTAS DO ALUNO (0 A 9)\n");
	
	for(int t=0; t< 5; t++){
		printf("Digite a %d� Nota: ", t+1);
		scanf("%f", &notas[t]);
	}
}

float media(){
	float result = 0;
	float soma = 0;
	for(int t=0;t<5;t++){
		soma = soma + notas[t];
	}
	result = soma / 5;
	
	return result;
}

void ordenacao(){
	int aux = 0;
	
	for(int p=0; p<4; p++){
    	for(int t=p;t<4;t++){
    		if(notas[p] > notas[t+1]){
    			aux = notas[p];
    			notas[p] = notas[t+1];
    			notas[t+1] = aux;
    			t =-1;
    			p =-1;
    		}
    	}
	}
	
	printf("\nA pior nota � %.2f e a melhor nota � %.2f", notas[0],notas[4]);
}
