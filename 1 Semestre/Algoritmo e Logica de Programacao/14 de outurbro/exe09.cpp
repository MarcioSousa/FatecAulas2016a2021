#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main(){
	setlocale(LC_ALL,"Portuguese");
	
	int num1 = 0, produto = 0;
	
	for (int t=0; ;t++)
	{
		printf("Digite o numero inteiro: ");
		scanf("%d", &num1);
		
		if (num1 != 0)
		{
			if (produto != 0)
			{
				produto = produto * num1;
			}
			else
			{
				produto = num1;
			}
		}
		else
		{
			break;
		}		
	}
	printf("\n--------------------------------");
	printf("\nA multiplicação dos números acima é: %d\n", produto);
	
	system("PAUSE");
	
}
