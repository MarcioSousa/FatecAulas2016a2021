#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Biblioteca necessária para usar o SETLOCALE()

void carregaValores();
int calculadiferenca();
void paresimpares();

int valores[10];
int diferenca;

main(){
	setlocale(LC_ALL, "Portuguese"); //Instrução usada para configurar o idioma Português.
	
	carregaValores();
	printf("\nA diferença entre o maior e o menor número é: %d\n\n", calculadiferenca());
	paresimpares();
	printf("\n");
	system("PAUSE");
}

void carregaValores(){
	for(int t=0; t<10; t++){
		printf("Digite o %dº Valor: ", t+1);
		scanf("%d", &valores[t]);
	}
}

int calculadiferenca(){
	int l = 1, maior, menor;
	
	l = valores[0];

	for(int t =1;t<10; t++){
		if(l > valores[t])
		{
			maior = l;
		}
		else
		{
			l = valores[t];
		}
	}
	
	l = valores[0];
	
	for(int t = 1; t <10; t++)
	{
		if(l < valores[t])
		{
			menor = l;
		}
		else
		{
			l = valores[t];
		}
	}
	
	return maior - menor;

}

void paresimpares(){
	printf("== Abaixo, os números Pares ==");
	
	for(int t = 0; t<10; t++){
		if(valores[t] % 2 == 0){
			printf("\nO %dº Valor: %d", t+1, valores[t]);
		}
	}
	
	printf("\n\n== Abaixo, os números Ímpares ==");
	
	for(int t = 0; t<10; t++){
		if(not(valores[t] % 2 == 0)){
			printf("\nO %dº Valor: %d", t+1, valores[t]);
		}
	}
}
