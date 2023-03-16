#include <iostream>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int idade = 20;
	
	//criando um ponteiro
	int *pnt;
	
	//apontamento
	pnt = &idade;
	
	//modificando valor do espaço
	*pnt = 22;
	
	printf("Idade %i\n", idade);
	printf("Endereço eh %x\n", pnt);
	
	return 0;
}
