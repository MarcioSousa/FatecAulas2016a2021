#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Biblioteca necess�ria para usar o SETLOCALE()

main(){
	setlocale(LC_ALL, "Portuguese"); //Instru��o usada para configurar o idioma Portugu�s.
	
	char tipo;
	int tinto = 0, branco = 0, rose = 0, qtde = 0, resultado = 0;
		
	while (tipo != 'f')
	{
		printf("Digite o tipo do vinho\n");
		printf("T = Tinto, B = Branco, R = Rose, F = Finalizar: ");
		scanf("%c", &tipo);
		
		if (tipo == 't')
		{
			printf("Digite a quantidade de Vinho Tinto: ");
			scanf("%d", &qtde);
			tinto = tinto + qtde;
			printf("------------------------------------\n");
		}
		else
		{
			if (tipo == 'b')
			{
				printf("Digite a quantidade de Vinho Branco: ");
				scanf("%d", &qtde);
				branco = branco + qtde;
				printf("------------------------------------\n");
			}
			else
			{
				if (tipo == 'r')
				{
					printf("Digite a quantidade de vinho Rose: ");
					scanf("%d", &qtde);
					rose = rose + qtde;
					printf("------------------------------------\n");
				}
				else
				{
					printf("Tipo de Vinho Inexistente, Digite novamente...\n");
					printf("------------------------------------\n");
				}
			}
		}
		fflush(stdin);
	}
	
	resultado = tinto * 100 / (tinto + branco + rose);
	printf("A porcentagem de cada Vinho est� listado logo abaixo:\n");
	printf("Vinho Tinto: %d por cento.\n", resultado);
	
	resultado = branco * 100 / (tinto + branco + rose);
	printf("Vinho Branco: %d por cento.\n", resultado);
	
	resultado = rose * 100 / (tinto + branco + rose);
	printf("Vinho Ros�: %d por cento.\n", resultado);
	
}
