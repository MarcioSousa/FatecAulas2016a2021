#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct SDNODO Fila;

void initFila(Fila ** LL) {
    *LL = NULL;
}

bool fila_empty(Fila **recebido) {
	return (*recebido) == NULL;
}

TDNODO * fila_fim(Fila * LL) {
    TDNODO * ant = NULL;
    while (LL != NULL) {
        ant = LL;
        LL = LL->prox;
    }
    return ant;
}

TDNODO * fila_front(Fila * LL) {
	return LL;
}

void fila_insere(Fila ** LL, TINFO info) {
    TDNODO * ult = fila_fim(*LL);
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

TDNODO * fila_remove(Fila ** LL) {
    if (*LL == NULL) {
        return NULL;
    }
    
    TDNODO *aux = *LL;
    
    (*LL) = (*LL)->prox;
    if (*LL != NULL) {
        (*LL)->ant = NULL;
    }
    return (aux);
    
    
}
