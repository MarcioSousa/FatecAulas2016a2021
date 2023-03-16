#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//=========== PONTEIROS ===============
//========== VARIÁVEL GLOBAL ==========
void func1(int num);
void func2(int *ptr);

int main(){
	//Cópia. (funcão)
	//Variável Local
	int valor = 10; //====== endereço 1000 exemplo ========
	printf("Valor = %i", valor);
	func1(valor);
	printf("\nValor = %i", valor);
	
	//======== ENDEREÇO DO VALOR COM E COMERCIAL ============
	func2(&valor);
	printf("\nValor = %i\n", valor);
	
	return 0;
}

void func1(int num){
	num = 99;
}

//=========== PONTEIRO GUARDA UM ENDEREÇO =============
void func2(int *ptr){
	*ptr = 99; //====== CONTEÚDO DESSE ENDEREÇO PASSA A SER 99 ======
}
