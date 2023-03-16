#include <stdlib.h>
#include <stdio.h>

typedef struct SLLEncSimples LLEncSimples;
typedef struct SLLEncSimples TNODO;
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
	TNODO * aux = *LL;
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
	TNODO * aux = (LLEncSimples *)malloc(sizeof(LLEncSimples));
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
	TNODO * aux = *LL;
	TNODO * NODO = (LLEncSimples *)malloc(sizeof(LLEncSimples));
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

TNODO * RemoverInicioLLEncSimples(LLEncSimples ** LL)
{
	TNODO * aux = *LL;
	
	if (aux != NULL)
	{	
		if (aux->prox == NULL)
		{
			*LL = NULL;
		} 
		else 
		{
			*LL = aux->prox;
			aux->prox = NULL;
		}
	}
	return(aux);
}

TNODO * RemoverFinalLLEncSimples(LLEncSimples ** LL)
{
	TNODO * ant = NULL;
	TNODO * aux = *LL;
	
	while (aux != NULL && aux->prox != NULL)
	{
		ant = aux;
		aux = aux->prox;
	}
	if (aux != NULL)
	{
		if (ant != NULL)
		{
			ant->prox = NULL;
		}
		else 
		{
			*LL = ant;
		}
	}
	return (aux);
}

int main(int argc, char** argv) {
	LLEncSimples *LL;
	TNODO * aux;
	
	InicializarLLEncSimples(&LL);	
	InserirInicioLLEncSimples(&LL,10);
	InserirFinalLLEncSimples(&LL,20);
	InserirInicioLLEncSimples(&LL,30);
	InserirFinalLLEncSimples(&LL,40);	
	ShowLLEncSimples(LL);
	aux = RemoverInicioLLEncSimples(&LL);
	ShowLLEncSimples(LL);
	printf("\nno removido (%x)\n",aux);	
	aux = RemoverFinalLLEncSimples(&LL);
	ShowLLEncSimples(LL);
	printf("\nno removido (%x)\n",aux);			
	DestruirLLEncSimples(&LL);	
	ShowLLEncSimples(LL);	
	
	return 0;
}
