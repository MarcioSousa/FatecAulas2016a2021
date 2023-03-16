
#include <stdio.h>

void f1(int valor);
void f2(int *valor);
void f3(int vetor[]);
void f4(int *vetor);
 
int main(void)
{
	int x, y[10];
	
	x=10;
	f1(x);
	printf("\nPassagem por valor: %i", x);
	
	
	f2(&x);
	printf("\nPassagem por referencia %i", x);
	
	y[0]=20;
	
	f3(y);
	printf("\nPassagem por referencia %i", y[0]);
	
	f4(y);
	printf("\nPassagem por referencia %i", y[0]);
	
	
}

void f1(int valor)
{
    valor = valor + 1;
}
void f2(int *valor)
{
   *valor = *valor + 1;
}

void f3(int vetor[])
{
    vetor[0] = vetor[0] + 1;
}

void f4(int *vetor)
{
    *vetor = *vetor + 1;
}


