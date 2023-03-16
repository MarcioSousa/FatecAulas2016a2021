#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Biblioteca necessária para usar o SETLOCALE()

void carregaVetor();
void exibirImpares();

int pares[10];

main(){
	setlocale(LC_ALL, "Portuguese"); //Instrução usada para configurar o idioma Português.
	
	carregaVetor();
	exibirImpares();
	
}

void carregaVetor(){
	int valor = 22;
	
	for(int t =0; t<10; t++){
		pares[t] = valor;
		valor += 2;
	}
}

void exibirImpares(){
	printf("Os 10 Valores impares são: \n");
	for(int t = 0; t < 10; t++){
		if (t == 0)
		{
			printf("%d", pares[t]+1);
		}
		else
		{
			printf(" - %d", pares[t]+1);
		}
	}
}
