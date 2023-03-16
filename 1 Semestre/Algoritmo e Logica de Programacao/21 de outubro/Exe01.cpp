#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Biblioteca necessária para usar o SETLOCALE()

main(){
	setlocale(LC_ALL, "Portuguese"); //Instrução usada para configurar o idioma Português.
	
	int cpf, numdepend;
	float renda, vreceber, imposto;
	
	cpf = 1;
	
	while(cpf != 0)
	{
		printf("Digite o CPF do cliente, digite 0 para encerrar: ");
		scanf("%d", &cpf);
		
		if (cpf == 0)
		{
			break;
		}
		
        printf("Digite o número de dependentes: ");
     	scanf("%d", &numdepend);
	
    	printf("Digite a renda mensal: ");
    	scanf("%f", &renda);
    	
     	vreceber = renda * (1 -(0.05 * numdepend));
     	
     	imposto = renda / 850;
     	
     	if (imposto > 2)
        {
     		if (imposto <= 3)
     		{
     			renda = renda * 0.1;
			}
			else
			{
				if (imposto <=5)
				{
					renda = renda * 0.15;
				}
				else
				{
					if (imposto <= 7)
					{
						renda = renda * 0.20;
					}
					else
					{
						renda = renda * 0.25;
					}
				}
			}
		}
     	
     	printf("O valor a ser pago no imposto de renda é: %.2f\n", renda);
    	printf("O valor a receber é: %.2f\n", vreceber - renda);
    	printf("----------------------------------------------\n");
    }
    
	system("PAUSE");
}
