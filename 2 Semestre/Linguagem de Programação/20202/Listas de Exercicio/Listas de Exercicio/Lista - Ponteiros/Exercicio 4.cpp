#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Implemente uma função que receba como parâmetro um vetor de números reais de tamanho N e retorne quantos números negativos há nesse vetor.
//Essa função deve obedecer ao protótipo: int negativos (float *vet, int N)

int negativos (float *vet, int N);

main()
{
	float vetor[5];
	int i;

	printf("Informe os valores do vetor:\n");
	
	for(i=0;i<5;i++)
	{
		scanf("%f",&vetor[i]);
	}
	
	printf ("\nEsse vetor tem %d numeros negativos!", negativos (&vetor[0], 5));


}

int negativos (float *vet, int N)
{
	int i, qtde=0;
	
	for(i=0;i<N;i++,vet++)
	{
		if (*vet < 0)
		qtde++;
	}

return qtde;
}
