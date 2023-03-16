Listas Lineares

-> Operacoes
	Cria��o/Inicializacao
	Inser��es	} Inicio, meio, fim
	Remocoes	} Inicio, meio, fim
	Destriu��o da Listas
	Pesquisas
	Ordena��o
	
Estrutura Nodo
	estrutura SNodo
		INFO item;
		  .     .
		  .     .
		  .     .
		 NODO ^prox
		  .	   .
		  . 	   .
		  . 	   .
	fim_estrutura
	TIPO estrutura SNODO NODO;
	TIPO <tipo> INFO;

Listas com Encadeamento Simples

       L HEAD	#100	#300	L TAIL

	...

		nodo	ponteiro	nodo

Cabe�a da lista	elementos encadeados da lista	cauda da lista

estrutura do NODO
	estrutura SNodo
		item : INFO
		prox : ^ NODO
	fim-estrutura
	
Opera��es
	CriarLLEncSimples(LL:^NODO)
		LL <- NULO
	Fim_CriarLLEncSimples
	
	DestruirLLEncSimples(LL:^NODO)
		aux : ^NODO;
		aux <- LL;
		
		enquanto LL != NULO fa�a
			LL <- LL->Prox
			apagar(aux)
			aux <- LL
		fim-enquanto
	Fim-DestruirLLEncSimples

/*
implementacao da Lista Linear (LL)
encadeamento seria
sustenido representa um endere�o de memoria, uma representacao
o TIPO � um typedef
^ � um ponteiro em portugol

Algoritmo
Ao criar a lista, inicia colocando nulo na cabe�a da lista
Destruir a lista � torna-la vazia e eliminar os elementos da memoria.
Apagar = Delete em C++
A lista � limpa fazendo com que a head aponte, n�o para o proximo, mas para o proximo do proximo, e apagando o que a cabe�a anteriormente apontava

*/

Prova
Desenvolver a lista e trazer aqui funcionando para testar no BOCA

2Prova eh prova mesmo, sem choro








#include <iostream>
#include <cstdio>

typedef struct SNODO NODO;
typedef int INFO;

struct SNODO {
	INFO info;
	NODO * prox;
};

void CriarLLEncSimples(NODO ** LL)
{
	*LL = NULL;
}

void MostarLLEncSimples(NODO * LL)
{
	while (LL != NULL)
	{
		printf("\n[%x] : [%d]->[%x]",LL,LL->info,LL->prox);
		LL = LL->prox;
	}
	printf("\n");
}

void DestruirLLEncSimples(NODO ** LL)
{
	NODO * aux;
	aux = *LL;
	while (*LL != NULL)
	{
		MostarLLEncSimples(*LL);
		*LL = (*LL)->prox;
		delete aux;
		aux = *LL;
	}
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	NODO * LHead;
	NODO * aux;
	NODO * aux2;
	
	CriarLLEncSimples(&LHead);
	
	aux = new NODO;
	aux->info = 10;
	aux->prox = NULL;
	
	LHead = aux;
	aux2 = aux;
	
	aux = new NODO;
	aux->info = 20;
	aux->prox = NULL;
	
	aux2->prox = aux;
	aux2 = aux;
	
	aux = new NODO;
	aux->info = 30;
	aux->prox = NULL;
	
	aux2->prox = aux;
	
	DestruirLLEncSimples(&LHead);
		
	return 0;
}
