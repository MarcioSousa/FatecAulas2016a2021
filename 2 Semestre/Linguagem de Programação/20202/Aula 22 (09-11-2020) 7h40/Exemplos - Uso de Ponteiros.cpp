#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//EXERCÍCIO 4 - MATERIAL SOBRE PONTEIROS
/*void Calcula (int *px, int *py);

main()
{
	int x, y;
	printf ("Informe valor para x: ");
	scanf ("%i", &x);
	printf ("Informe valor para y: ");
	scanf ("%i", &y);
	
	printf ("\nValores iniciais de x e y = %i e %i\n", x, y);
		
	Calcula (&x, &y);
	
	printf ("\nNovo valor de x com x+y = %i", x);
	printf ("\nNovo valor de y com x*y = %i", y);	
}
void Calcula (int *px, int *py)
{
	int aux = *px;
	
	*px = *px + *py;
	*py = aux * (*py);
}*/

//EXERCÍCIO 5 - MATERIAL SOBRE PONTEIROS
void F_CalculaReajuste (float *ppreco, int tp, float *preaj);

main()
{
	float preco=1, reaj;
	int tipo;
	
	while (preco != 0 ){
		printf ("Informe o preco do produto: ");
		scanf ("%f", &preco);
		if (preco == 0)
			exit;
		else
		{		
			printf ("Informe o tipo do produto: ");
			scanf ("%i", &tipo);
		
			F_CalculaReajuste (&preco, tipo, &reaj);
				
			printf ("\nValor do reajuste = %.2f", reaj);
			printf ("\nNovo preco do produto = %.2f\n\n", preco);
		}	
	};
}

void F_CalculaReajuste (float *ppreco, int tp, float *preaj)
{
	if (tp == 1)
	{
		*preaj = (*ppreco) * 0.3;
		*ppreco = *ppreco + *preaj;
	}
	if (tp == 2)
	{
		*preaj = (*ppreco) * 0.5;
		*ppreco = *ppreco + *preaj;
	}
	if (tp == 3)
	{
		*preaj = (*ppreco) * 0.7;
		*ppreco = *ppreco + *preaj;
	}
}
