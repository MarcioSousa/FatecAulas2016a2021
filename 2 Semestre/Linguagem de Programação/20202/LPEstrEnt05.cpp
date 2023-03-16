#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define TAM 2

void CarregaDados();
void FiltroPreco(float preco);
void FiltroMarca(char marca[15]);
void FiltroPreco(char marca[15], int ano, char cor[10]);
//a - Escrever a defini��o da estrutura carro.
struct carro {
	char marca[15];
	int ano;
	char cor[10];
	float preco;
};

//b - Declarar o vetor vetcarros do tipo da estrutura definida acima, de tamanho 20 e global
carro vetcarros[20];

/*
5. Seja uma estrutura para descrever os carros de uma determinada revendedora, contendo
os seguintes campos:
marca: string de tamanho 15
ano: inteiro
cor: string de tamanho 10
pre�o: real
a) Escrever a defini��o da estrutura carro.
b) Declarar o vetor vetcarros do tipo da estrutura definida acima, de tamanho 20 e global.
c) Definir um bloco de programa para ler o vetor vetcarros.
d) Definir um bloco de programa que receba um pre�o e imprima os carros (marca, cor e
ano) que tenham pre�o igual ou menor ao pre�o recebido.
e) Defina um bloco de programa que leia a marca de um carro e imprima as informa��es de
todos os carros dessa marca (pre�o, ano e cor).
f) Defina um bloco de programa que leia uma marca, ano e cor e informe se existe ou n�o
um carro com essas caracter�sticas. Se existir, informar o pre�o.
*/

int main() {
	setlocale(LC_ALL, "Portuguese"); 
	
	float filtroPreco;
	char marcacarro[15];
	int anofiltro;
	char corfiltro[10];
	
	//c - Definir um bloco de programa para ler o vetor vetcarros.
	CarregaDados();
	
	//d - Definir um bloco do programa que receba um pre�o e imprima os 
	//carros (marca, cor e ano) que tenham pre�o igual ou menor ao pre�o recebido.
	printf("======\nDigite um pre�o para ser filtrado com pre�os menor ou igual: ");
	scanf("%f", &filtroPreco);
	FiltroPreco(filtroPreco);
	fflush(stdin);
	
	//e - Defina um bloco de programa que leia a marca de um carro e 
	//imprima as informa��es de todos os carros dessa marca (pre�o, ano, cor)
	printf("\n=====\nDigite a marca de um carro: ");
	gets(marcacarro);
	FiltroMarca(marcacarro);
	
	//f - Defina um bloco do programa que leia uma marca, ano e cor e informe 
	//se existe ou n�o um carro com essas caracter�sticas. Se existir, informar 
	//o pre�o.
	printf("\n=====\nFiltro com Marca, Ano, Cor.\nInforme a Marca: ");
	gets(marcacarro);
	printf("Informe o Ano: ");
	scanf("%i", &anofiltro);
	fflush(stdin);
	printf("Informe a Cor: ");
	gets(corfiltro);
	fflush(stdin);
	FiltroPreco(marcacarro, anofiltro, corfiltro);

	printf("== FINALIZADO ==\n");

	return 0;
}

void CarregaDados(){
	for(int t = 0; t < TAM; t++){
		printf("Dados do %i� de %i Carros: \n", t+1, TAM);
		printf("Marca: ");
		gets(vetcarros[t].marca);
		
		printf("Ano: ");
		scanf("%i", &vetcarros[t].ano);
		fflush(stdin);
		
		printf("Cor: ");
		gets(vetcarros[t].cor);
		
		printf("Pre�o: ");
		scanf("%f", &vetcarros[t].preco);
		fflush(stdin);
	}
}

void FiltroPreco(float preco){
	for(int t = 0; t < TAM; t++){
		if(vetcarros[t].preco <= preco){
			printf("Marca: %s, Cor: %s, Pre�o: %.2f\n", vetcarros[t].marca, vetcarros[t].cor, vetcarros[t].preco);
		}
	}
}

void FiltroMarca(char marca[15]){
	
	for(int t = 0; t < TAM; t++){
		if(strcmp(vetcarros[t].marca, marca) == 0){
			printf("Pre�o: %.2f, Ano: %i, Cor: %s\n", vetcarros[t].preco, vetcarros[t].ano, vetcarros[t].cor);
		}
	}
	
}

void FiltroPreco(char marca[15], int ano, char cor[10]){
	bool encontrou = false;
	
	for(int t = 0; t < TAM; t++){
		if(strcmp(vetcarros[t].marca, marca) == 0 && vetcarros[t].ano == ano && strcmp(vetcarros[t].cor, cor) == 0){
			printf("Pre�o: %.2f\n", vetcarros[t].preco);
			encontrou = true;
			break;
		}
	}
	
	if(encontrou == false){
		printf("== N�o Existe o carro com essas caracter�sticas ==\n");
	}
	
}



