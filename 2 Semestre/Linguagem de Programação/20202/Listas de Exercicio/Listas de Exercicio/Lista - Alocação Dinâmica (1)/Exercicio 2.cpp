#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
Crie uma função que receba como parâmetros dois vetores de inteiros, v1 e v2, e as suas respectivas quantidades de elementos, n1 e n2.
A função deverá retornar um ponteiro para um terceiro vetor, v3, com capacidade para (n1 + n2) elementos, alocado dinamicamente, contendo a união de v1 e v2.
Por exemplo, se v1 = {11, 13, 45, 7} e v2 = {24, 4, 16, 81, 10, 12}, v3 irá conter {11, 13, 45, 7, 24, 4, 16, 81, 10, 12}.

O cabeçalho dessa função deverá ser o seguinte:
void uniao(int *v1, int n1, int *v2, int n2);

Em seguida, crie a função principal do programa para chamar a função uniao passando dois vetores informados pelo usuário (ou declarados estaticamente).
Em seguida, deve ser exibido na tela os elementos do vetor resultante. Não esqueça de liberar a memória alocada dinamicamente.
*/

void uniao(int *v1, int n1, int *v2, int n2);

main()
{
	int *vetor1, *vetor2, q1, q2, i;
	
	
	
	
	// =========================== DEFINIÇÃO DO VETOR 1 ===========================
	// ============================================================================
	printf("Informe a quantidade de numeros no vetor 1: ");
	scanf("%d", &q1);
	printf("\nInforme os valores do vetor 1:\n");
	
	vetor1 = (int*) malloc((q1)*sizeof(int));
	
	for (i=0;i<q1;i++)
	{
		scanf("%d",&vetor1[i]);
	}
	// ============================================================================
	
	
	
	
	
	// =========================== DEFINIÇÃO DO VETOR 2 ===========================
	// ============================================================================
	printf("Informe a quantidade de numeros no vetor 2: ");
	scanf("%d", &q2);
	printf("\nInforme os valores do vetor 2:\n");
	
	vetor2 = (int*) malloc((q2)*sizeof(int));
	
	for (i=0;i<q2;i++)
	{
		scanf("%d",&vetor2[i]);
	}
	// ============================================================================
	
	
	
	
	
	// ========================= RESUMO DOS VETORES 1 E 2 =========================
	// ============================================================================
	printf("\n\nValores do vetor 1: ");
	for(i=0;i<q1;i++,vetor1++)
	{
		printf("%d ", *vetor1);
	}
	
	vetor1 = vetor1-q1;
		printf("\n\nValores do vetor 2: ");
		for(i=0;i<q2;i++,vetor2++)
	{
		printf("%d ", *vetor2);
	}
	vetor2 = vetor2-q2;
	// ============================================================================
	
	
	
	
	
	uniao(vetor1, q1, vetor2, q2);				// ========================= CHAMADA DA FUNÇÃO UNIÃO  =========================
	

	free(vetor1);								// =========================== LIBERA VETOR 1 ===========================
	free(vetor2);								// =========================== LIBERA VETOR 2 ===========================

}

void uniao(int *v1, int n1, int *v2, int n2)	// =========================== FUNÇÃO UNIÃO  ===========================
{
	int q3, *vetor3, i;
	
	q3 = n1+n2;
	vetor3 = (int*) malloc((q3)*sizeof(int));
	
	for(i=0;i<n1;i++,vetor3++,v1++)
	{
		*vetor3 = *v1;
	}
	
	for(i=0;i<n2;i++,vetor3++,v2++)
	{
		*vetor3 = *v2;
	}
	
	printf("\n\nOs valores do vetor 3 (uniao) sao: ");
	vetor3=vetor3-q3;
	
	for(i=0;i<q3;i++,vetor3++)
	{
		printf("%d ", *vetor3);
	}
	
	free(vetor3);
	
}
