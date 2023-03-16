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
