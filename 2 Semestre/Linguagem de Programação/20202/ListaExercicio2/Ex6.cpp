#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Faça um programa que crie uma estrutura hidrocarboneto 
//com os campos C e H como inteiros correspondentes a quantidade 
//de carbonos e hidrogênios, respectivamente. 
//A função principal deve alocar dinamicamente uma variável do tipo 
//hidrocarboneto. Em seguida, devem ser lidas as quantidades de 
//carbonos e hidrogênios e impressa a massa atômica do composto, 
//dada por MA = C + H.

typedef struct{
	int C;
	int H;
} hidrocarboneto;

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int qtdeh, ma;
	
	printf("Digite a qtde de Hidrocarboneto que serão registrados: ");
	scanf("%i", &qtdeh);
	
	hidrocarboneto *hidrocarb = (hidrocarboneto *) malloc(qtdeh *sizeof(hidrocarboneto));
	
	printf("Hidrocarboneto:\n");
	
	for(int t = 0; t < qtdeh; t++){
		printf("Digite o numero de carbono: ");
		scanf("%i", &hidrocarb[t].C);
		printf("Digite o numero de hidrogênio: ");
		scanf("%i", &hidrocarb[t].H);
		printf("\n");
	}
	
	printf("Dados do(s) Hidrocarboneto(s)\n");
	
	for(int t = 0; t < qtdeh; t++){
		printf("Carbono: %i; Hidrogênio: %i; Massa Atômica: %i.\n", hidrocarb[t].C, hidrocarb[t].H, hidrocarb[t].C+hidrocarb[t].H);
	}
	
	free(hidrocarb);
	
	return 0;
	
}
