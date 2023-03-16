#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 20

struct carros		//definição da estrutura
{
	char marca[15];
	int ano;	
	char cor[10];
	float preco;
};

main() {
	
	struct carros vetcarros [TAM];
	int i,j,k=0,anodesejado;
	float valordesejado;
	char marcadesejada[15], cordesejada[10];
	
	for (i=0; i<TAM; i++)
	{
		printf("Digite a marca: ");
		gets(vetcarros[i].marca);
		fflush(stdin);
		printf("Digite o ano: ");
		scanf("%d", &vetcarros[i].ano);
		fflush(stdin);
		printf("Digite a cor: ");
		gets(vetcarros[i].cor);
		fflush(stdin);
		printf("Digite o preco: ");
		scanf("%f", &vetcarros[i].preco);
		fflush(stdin);
	}
	printf("\n");
	
	printf("Informe o valor maximo desejado: ");
	scanf("%f", &valordesejado);
	printf("\nCom o valores de ate %.2f temos as seguintes opcoes:\n", valordesejado);
	for (j=0; j<TAM; j++)
	{
		if (vetcarros[j].preco <= valordesejado)
		{
			printf("\nCarro %s, cor %s, ano %d, valor R$%.2f", vetcarros[j].marca, vetcarros[j].cor, vetcarros[j].ano, vetcarros[j].preco);
		}
	}
	
	fflush(stdin);
	printf("\nInforme a marca desejada: ");
	gets(marcadesejada);
	fflush(stdin);
	printf("\nCom a marca %s temos as seguintes opcoes:\n", marcadesejada);
	for (j=0; j<TAM; j++)
	{
		if (strcmp(vetcarros[j].marca, marcadesejada)==0)
		{
			printf("\nCarro %s, cor %s, ano %d, valor R$%.2f", vetcarros[j].marca, vetcarros[j].cor, vetcarros[j].ano, vetcarros[j].preco);
		}
	}
	
	fflush(stdin);
	printf("\nPara o filtro do carro exato, informe a marca, ano e cor desejada.\nMarca: ");
	gets(marcadesejada);
	fflush(stdin);
	printf("Ano: ");
	scanf("%d", &anodesejado);
	fflush(stdin);
	printf("Cor: ");
	gets(cordesejada);
	fflush(stdin);
	printf("\nCom a marca %s, ano %d e cor %s temos as seguintes opcoes:\n", marcadesejada, anodesejado, cordesejada);
	for (j=0; j<TAM; j++)
	{
		if (strcmp(vetcarros[j].marca, marcadesejada)==0 && strcmp(vetcarros[j].cor, cordesejada)==0 && anodesejado == vetcarros[j].ano)
		{
			k++;
			printf("\nCarro %s, cor %s, ano %d, valor R$%.2f", vetcarros[j].marca, vetcarros[j].cor, vetcarros[j].ano, vetcarros[j].preco);
		}
	}
	if (k == 0)
	{
		printf("\nInfelizmente no momento nao possuimos carros com as caracteristicas solicitadas.");
	}
	
}
