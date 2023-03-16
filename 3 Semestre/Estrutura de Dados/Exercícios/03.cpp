#include <iostream>
#include <cstdlib>
#include <cstdio>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct SLLEncSimples LLEncSimples;
typedef int TINFO;

struct SLLEncSimples {
	TINFO info; 
	LLEncSimples * prox;
};

void InicializarLLEncSimples(LLEncSimples **LL)
{
	if (*LL != NULL)
	{
		*LL = NULL;
	}
}

void DestruirLLEncSimples(LLEncSimples **LL)
{
	LLEncSimples * aux = *LL;
	while (*LL != NULL)
	{
		(*LL) = (*LL)->prox;
		delete(aux);
		aux = (*LL);
	}
	delete(aux);
}

void InserirInicioLLEncSimples(LLEncSimples **LL, TINFO info)
{
	LLEncSimples * aux = (LLEncSimples *)malloc(sizeof(LLEncSimples));
	aux->info = info;
	aux->prox = (*LL);
	(*LL) = aux;
}

void ShowLLEncSimples(LLEncSimples *LL)
{
	printf("\n\n");
	while (LL != NULL)
	{
		printf("[(%x) %d (%x)]->",LL,(LL)->info,(LL)->prox);
		(LL) = (LL)->prox;
	}
	printf("\n\n");
}

void InserirFinalLLEncSimples(LLEncSimples ** LL , TINFO info)
{
	LLEncSimples * aux = *LL;
	LLEncSimples * NODO = (LLEncSimples *)malloc(sizeof(LLEncSimples));
	NODO->info = info;
	NODO->prox = NULL;
	
	while (aux != NULL && aux->prox != NULL)
	{
		aux = aux->prox;
	}
	if (aux == NULL)
	{
		*LL = NODO;
	}
	else
	{
		aux->prox = NODO;
	}
}

void RemoverInicioLLEncSimples(LLEncSimples ** LL)
{
	LLEncSimples * aux = *LL;
	
	if (aux == NULL)
	{
		return;
	}
	if (aux->prox == NULL)
	{
		*LL = NULL;
		delete(aux);
		return;
	}
	
	*LL = aux->prox;
	delete(aux);
	
}

int main(int argc, char** argv) {
	LLEncSimples *LL;
	
	InicializarLLEncSimples(&LL);
	
	InserirInicioLLEncSimples(&LL,10);
	InserirFinalLLEncSimples(&LL,20);
	InserirInicioLLEncSimples(&LL,30);
	InserirFinalLLEncSimples(&LL,40);
	
	ShowLLEncSimples(LL);

	RemoverInicioLLEncSimples(&LL);
	
	ShowLLEncSimples(LL);	

	RemoverInicioLLEncSimples(&LL);

	ShowLLEncSimples(LL);	

	DestruirLLEncSimples(&LL);	
	
	ShowLLEncSimples(LL);	
	
	return 0;
}
