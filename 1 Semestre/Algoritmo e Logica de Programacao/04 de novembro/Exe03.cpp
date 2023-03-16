#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Biblioteca necessária para usar o SETLOCALE()

int integerPower(int base, int expoente);

main(){
	setlocale(LC_ALL, "Portuguese"); //Instrução usada para configurar o idioma Português.
	
	int valor1, valor2, valorTotal;
	
	printf("Digite o primeiro valor: ");
	scanf("%d", &valor1);
	
	printf("Digite o segundo valor: ");
	scanf("%d", &valor2);
	
    valorTotal = integerPower(valor1,valor2);
	
	printf("A multiplicação do valor1 com valor2 é: %d\n", valorTotal);
	
	system("PAUSE");
}

int integerPower(int base, int expoente)
{
	int total = 1;
	
	for (int t = 0; t < expoente; t++)
	{
		total = total * base;
	}
	return total;
}
