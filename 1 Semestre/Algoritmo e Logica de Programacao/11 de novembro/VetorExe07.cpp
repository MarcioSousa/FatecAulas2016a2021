#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Biblioteca necess�ria para usar o SETLOCALE()

void carregaVetores();
void ordenacao();
void apresentacao();

int valores[20];

main(){
	setlocale(LC_ALL, "Portuguese"); //Instru��o usada para configurar o idioma Portugu�s.
	
	carregaVetores();
	ordenacao();
	apresentacao();
}

void carregaVetores(){
	for(int t=0; t< 20; t++){
		printf("Digite o %d� Valor: ", t+1);
		scanf("%d", &valores[t]);
	}
}

void ordenacao(){
	int aux = 0, cont = 0;

	for(int t=19; t>10; t--){
		aux = valores[cont];
		valores[cont] = valores[t];
		valores[t] = aux;
		cont++;
	}
}

void apresentacao(){
	for(int t = 0; t<20;t++){
		if (t == 0){
			printf("==== Os valores em ordem trocadas s�o ====");
			printf("\n%d", valores[0]);
		}
		else
		{
			printf(" - %d", valores[t]);
		}
	}
}
