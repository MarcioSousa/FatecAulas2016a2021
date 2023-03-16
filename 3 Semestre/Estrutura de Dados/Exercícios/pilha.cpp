#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct SDNODO Pilha;

void initPilha(Pilha ** LL) {
    *LL = NULL;
}

bool pilha_empty(Pilha **recebido) {
	return (*recebido) == NULL;
}

TDNODO * pilha_top(Pilha * LL) {
    TDNODO * ant = NULL;
    while (LL != NULL) {
        ant = LL;
        LL = LL->prox;
    }
    return ant;
}

void pilha_push(Pilha ** LL, TINFO info) {
    TDNODO * ult = pilha_top(*LL);
    TDNODO * aux =  new TDNODO;

    aux->ant = ult;
    aux->info = info;
    aux->prox = NULL;

    if (ult != NULL) {
        ult->prox = aux;
    } else {
        *LL = aux;
    }
}

TDNODO * pilha_pop_back(Pilha ** LL) {
    TDNODO * aux = NULL;
    if (*LL == NULL) {
        return NULL;
    }
    aux = *LL;
    (*LL) = (*LL)->prox;
    if (*LL != NULL) {
        (*LL)->ant = NULL;
    }
    return (aux);
}

TDNODO * pilha_pop(Pilha ** LL) {
	TDNODO * ultimo = pilha_top(*LL);
    TDNODO * aux = ultimo->ant;
    TDNODO * ptr;
    
    if (aux == NULL) {
        return pilha_pop_back(LL);
    }
    
    ptr = aux->prox;
    aux->prox = NULL;
    
    return (ptr);
}
