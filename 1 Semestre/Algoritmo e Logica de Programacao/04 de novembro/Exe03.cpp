#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Biblioteca necess�ria para usar o SETLOCALE()

int integerPower(int base, int expoente);

main(){
	setlocale(LC_ALL, "Portuguese"); //Instru��o usada para configurar o idioma Portugu�s.
	
	int valor1, valor2, valorTotal;
	
	printf("Digite o primeiro valor: ");
	scanf("%d", &valor1);
	
	printf("Digite o segundo valor: ");
	scanf("%d", &valor2);
	
    valorTotal = integerPower(valor1,valor2);
	
	printf("A multiplica��o do valor1 com valor2 �: %d\n", valorTotal);
	
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
