#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int verificador(char frase[]);

// definição da função principal
int main(){
	char frase[3];
	int retorno;
	printf("Digite SIM ou NAO: ");
	gets(frase);
	fflush(stdin);
	
	retorno = verificador(frase);
	
	if(retorno == 0){
		printf("Foi digitado SIM.\n");
	}else{
		printf("Foi digitado NAO.\n");
	}
}

int verificador(char frase[]){
	if(strcmp(frase, "SIM") == -1){
		return 1;
	}else{
		return 0;
	}
}
