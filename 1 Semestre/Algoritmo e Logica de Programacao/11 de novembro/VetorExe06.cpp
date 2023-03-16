#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Biblioteca necessária para usar o SETLOCALE()

void carregaVetores();
void ordenacao();
void apresentacao();

int valores[20];

main(){
	setlocale(LC_ALL, "Portuguese"); //Instrução usada para configurar o idioma Português.
	
	carregaVetores();	
	ordenacao();
	apresentacao();
}

void carregaVetores(){
	for(int t=0; t< 20; t++){
		printf("Digite o %dº Valor: ", t+1);
		scanf("%d", &valores[t]);
	}
}

void ordenacao(){
	int aux = 0;
	
	for(int p=0; p<19; p++){
    	for(int t=p;t<19;t++){
    		if(valores[p] > valores[t+1]){
    			aux = valores[p];
    			valores[p] = valores[t+1];
    			valores[t+1] = aux;
    			t =-1;
    			p =-1;
    		}
    	}
	}
}

void apresentacao(){
	for(int t = 0; t<20;t++){
		if (t == 0){
			printf("==== Os valores na ordem crescente são ====");
			printf("\n%d", valores[0]);
		}
		else
		{
			printf(" - %d", valores[t]);
		}
	}
}
