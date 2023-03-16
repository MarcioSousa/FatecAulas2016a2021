#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main(){
	setlocale(LC_ALL,"Portuguese");
	
	int qtde, i, valor, soma, positivos, media;
	
	printf("\nInforme a quantidade de números fornecidos: ");
	scanf("%d", &qtde);
	
	for (i = 0; i <= qtde; i++)
	{
		printf("Informe um valor: );
		scanf("%d", valor);
		
		if(valor >= 0)
		{
			soma = soma + valor;
			posivitos = positivos +1;
		}
	}
	
	media = soma/ positivos;
	
	scanf("A média dos números positivos é: ", media);
	
	system("PAUSE");
}
