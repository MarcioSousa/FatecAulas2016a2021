#include <stdio.h>
#include <stdlib.h>

void IncluirFinalLLCEncSImples(LLEncSimples ** LL, TINFO info){
	LLEncSimples * aux = LL;
	LLEncSimples * NODO = (LLEncSimples *) malloc (sizeof(LLEncSimples));
	
	NODO --> info = info;
	NODO --> prox = NULL;
	
	while(aux != NULL && aux --> prox != NULL){
		aux = aux --> prox;
	}
	
	if(aux == NULL){
		*LL = NODO;
	}else{
		aux --> prox = NODO;
	}
}

//======================= EXEMPLOS APENAS ==============
void RemoverInicioLLCEncSImples(LLEncSimples ** LL, TINFO info){
	LLEncSimples * aux = LL;
	LLEncSimples * NODO = (LLEncSimples *) malloc (sizeof(LLEncSimples));
	
	if(aux == NULL){ //Lista está vazia
		return;
	}
	
	if(aux--> prox == NULL){
		*LL=NULL;
		delete(aux);
		return;
	}
	*LL = aux --> prox;
	delete aux;
	return;
}

