#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main(){
	setlocale(LC_ALL,"Portuguese");
	
	float valor, atualizado;
	int num1, num2;
	
	printf("Digite o valor: ");
	scanf("%f", &valor);
	
	for (int j=0; j<=40; j = j+10)
	{	
		for (int i=1; i<=10; i++)
		{
			atualizado = valor * i;
			printf("%d=%.2f ",i+j, atualizado);
		}
		printf("\n");
	}
	system("PAUSE");
}

