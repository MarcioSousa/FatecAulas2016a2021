#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Biblioteca necessária para usar o SETLOCALE()

main(){
	setlocale(LC_ALL, "Portuguese"); //Instrução usada para configurar o idioma Português.
	
	int porcentagem = 0, pessoas = 0 , canal = 0, pcanal5 = 0, pcanal7 = 0, pcanal10 = 0, pcanal12 = 0;
	
	do
	{
		printf("Digite o número do canal: ");
		scanf("%d", &canal);
		
		printf("Digite a quantidade de pessoas na casa: ");
		scanf("%d", &pessoas);
		
		if(canal == 5)
		{
			pcanal5 = pcanal5 + pessoas;
		}
		else
		{
			if (canal == 7)
			{
				pcanal7 = pcanal7 + pessoas;
			}
			else
			{
				if (canal == 10)
				{
					pcanal10 = pcanal10 + pessoas;
				}
				else
				{
					if (canal == 12)
					{
						pcanal12 = pcanal12 + pessoas;
					}
					else
					{
						printf("Esse canal não existe!\n");
					}
				}
			}
		}
		
	}
	while(canal != 0);
	pessoas = pcanal5 + pcanal7 + pcanal10 + pcanal12;
		
	porcentagem = (100 * pcanal5)/pessoas;
	printf("\nAudiência do canal 5: %d por cento", porcentagem);
	porcentagem = (100 * pcanal7)/pessoas;
	printf("\nAudiência do canal 7: %d por cento", porcentagem);
	porcentagem = (100 * pcanal10)/pessoas;
	printf("\nAudiência do canal 10: %d por cento", porcentagem);
	porcentagem = (100 * pcanal12)/pessoas;
    printf("\nAudiência do canal 12: %d por cento\n", porcentagem);
    
	system("PAUSE");
}
