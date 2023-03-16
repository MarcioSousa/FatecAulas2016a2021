#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Fa�a um programa que crie uma estrutura hidrocarboneto 
//com os campos C e H como inteiros correspondentes a quantidade 
//de carbonos e hidrog�nios, respectivamente. 
//A fun��o principal deve alocar dinamicamente uma vari�vel do tipo 
//hidrocarboneto. Em seguida, devem ser lidas as quantidades de 
//carbonos e hidrog�nios e impressa a massa at�mica do composto, 
//dada por MA = C + H.

typedef struct{
	int C;
	int H;
} hidrocarboneto;

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int qtdeh, ma;
	
	printf("Digite a qtde de Hidrocarboneto que ser�o registrados: ");
	scanf("%i", &qtdeh);
	
	hidrocarboneto *hidrocarb = (hidrocarboneto *) malloc(qtdeh *sizeof(hidrocarboneto));
	
	printf("Hidrocarboneto:\n");
	
	for(int t = 0; t < qtdeh; t++){
		printf("Digite o numero de carbono: ");
		scanf("%i", &hidrocarb[t].C);
		printf("Digite o numero de hidrog�nio: ");
		scanf("%i", &hidrocarb[t].H);
		printf("\n");
	}
	
	printf("Dados do(s) Hidrocarboneto(s)\n");
	
	for(int t = 0; t < qtdeh; t++){
		printf("Carbono: %i; Hidrog�nio: %i; Massa At�mica: %i.\n", hidrocarb[t].C, hidrocarb[t].H, hidrocarb[t].C+hidrocarb[t].H);
	}
	
	free(hidrocarb);
	
	return 0;
	
}
