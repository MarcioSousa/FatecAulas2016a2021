#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Biblioteca necess�ria para usar o SETLOCALE()

void armazenarValor();
void cincoNotas();

float num[10];

main(){
	setlocale(LC_ALL, "Portuguese"); //Instru��o usada para configurar o idioma Portugu�s.	
	
	armazenarValor();
	cincoNotas();
	
	printf("A SOMA DA PRIMEIRA NOTA COM A �LTIMA � : %.2f", num[0] + num[9]);
}

void armazenarValor(){
	for(int t = 0; t < 10; t++)
	{
		printf("Digite a %d� nota do aluno: ", t+1);
		scanf("%f", &num[t]);
	}
}

void cincoNotas(){
	printf("\n...ABAIXO AS NOTAS DOS CINCO PRIMEIROS ALUNOS CADASTRADOS...\n");
	for (int t=0; t < 5 ; t++){
		printf("A nota do %d� Aluno �: %.0f\n", t+1, num[t]);
	}
}
