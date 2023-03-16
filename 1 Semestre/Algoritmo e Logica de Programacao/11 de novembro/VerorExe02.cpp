#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Biblioteca necessária para usar o SETLOCALE()

void armazenarValor();
void cincoNotas();

float num[10];

main(){
	setlocale(LC_ALL, "Portuguese"); //Instrução usada para configurar o idioma Português.	
	
	armazenarValor();
	cincoNotas();
	
	printf("A SOMA DA PRIMEIRA NOTA COM A ÚLTIMA É : %.2f", num[0] + num[9]);
}

void armazenarValor(){
	for(int t = 0; t < 10; t++)
	{
		printf("Digite a %dº nota do aluno: ", t+1);
		scanf("%f", &num[t]);
	}
}

void cincoNotas(){
	printf("\n...ABAIXO AS NOTAS DOS CINCO PRIMEIROS ALUNOS CADASTRADOS...\n");
	for (int t=0; t < 5 ; t++){
		printf("A nota do %dº Aluno é: %.0f\n", t+1, num[t]);
	}
}
