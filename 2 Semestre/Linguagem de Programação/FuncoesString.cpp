#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h> 
 
main(){
	setlocale(LC_ALL, "Portuguese");
	
	//EXEMPLO 1
	//STRCPY E STRNCPY : COPIA O CONTE�DO DE UMA STRING EM OUTRA.
	
	//char p1[10], p2[10], p3[10];
	char p1[10];

	p1[10] = "AMARELO";
	//strcpy(p1,p2);
	//printf("Valor de p2 = %s", p2);
	//strncpy(p3,p2,4);
	//printf("Valor de p3 �: %s", p3);
	
	//EXEMPLO 2
	//STRCAT(y,x) E STRNCAT(y,x,n) : CONCATENA ("JUNTA") UMA STRING EM OUTRA
	//char p1[20], p2[20];
	//p1 = "AMARELO";
	//p2 = "VERDE";
	//strcat(p1, p2);
	//printf("1� Concatena��o: %s", p1);
	//strncat(p2, p1, 3);
	//printf("2� Concatena��o: %s", p2);
	
	//EXEMPLO 3
	//STRLEN(x) : DETERMINA O TAMANHO DE UMA STRING
	
	
	
	//EXEMPLO 4
	//STRCPM : COMPAR O CONTE�DO DE 2 STRINGS.
	//0 -> STRING1 E STRING2 S�O IGUAIS.
	//1 -> STRING1 < STRING2 (DE ACORDO COM A ORDEM ALFAB�TICA).
	
}
