#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//=========== PONTEIROS ===============
//========== VARI�VEL GLOBAL ==========
void func1(int num);
void func2(int *ptr);

int main(){
	//C�pia. (func�o)
	//Vari�vel Local
	int valor = 10; //====== endere�o 1000 exemplo ========
	printf("Valor = %i", valor);
	func1(valor);
	printf("\nValor = %i", valor);
	
	//======== ENDERE�O DO VALOR COM E COMERCIAL ============
	func2(&valor);
	printf("\nValor = %i\n", valor);
	
	return 0;
}

void func1(int num){
	num = 99;
}

//=========== PONTEIRO GUARDA UM ENDERE�O =============
void func2(int *ptr){
	*ptr = 99; //====== CONTE�DO DESSE ENDERE�O PASSA A SER 99 ======
}
