#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main(){
	setlocale(LC_ALL,"Portuguese");
	
	int numero;
	
	for (int t=1;t<=5;t++)
	{
		printf("Digite o %dº número: ", t);
		scanf("%d", &numero);
		
		if (numero /2 == 0)
		{
			if (numero != 0)
			{
				break;
			}
		}
	}
}
