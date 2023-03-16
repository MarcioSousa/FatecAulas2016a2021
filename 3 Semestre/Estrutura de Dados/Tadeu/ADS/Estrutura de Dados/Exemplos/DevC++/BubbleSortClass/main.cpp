#include <iostream>
#include "BubbleSort.h"

#define TAMANHO 10

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int main(int argc, char** argv) {
	BubbleSort bs(TAMANHO);
	int i = 0;
	int valor = 0;
	
	for (; i < TAMANHO; i++)
	{
		cout << "Informe o valor: ";
		cin >> valor;
		bs.SetElemento(i,valor); 
	}
	system("cls");
	bs.Mostrar();
	bs.Sort();
	bs.Mostrar();
	system("pause");
	return 0;
}
