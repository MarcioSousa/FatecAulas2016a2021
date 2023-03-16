#include <stdio.h>
#include <stdlib.h>

typedef struct SDNODO TDNODO;
typedef struct SDNODO LLEncDup;
typedef int TINFO;

struct SDNODO {
    TDNODO * ant;
    TINFO info;
    TDNODO * prox;
};

void InicializarLLEncDup(LLEncDup ** LL) {
    *LL = NULL;
}

void InserirInicioLLEncDup(LLEncDup ** LL, TINFO info) {
    TDNODO * aux;
    aux = (TDNODO *)malloc(sizeof(TDNODO));
    aux->info = info;
    aux->ant = NULL;
    aux->prox = NULL;

    if (*LL != NULL) {
        aux->prox = *LL;
        (*LL)->ant = aux;
    }

    *LL = aux;
}

TDNODO * ObterUltimoNoLLEncDup(LLEncDup * LL) {
    TDNODO * ant = NULL;
    while (LL != NULL) {
        ant = LL;
        LL = LL->prox;
    }
    return ant;
}

TDNODO * ObterPenultimoNoLLEncDup(LLEncDup * LL) {
    TDNODO * ant = NULL;
    if (LL == NULL) {
        return LL;
    }
    while (LL->prox != NULL) {
        ant = LL;
        LL = LL->prox;
    }
    return ant;
}

void InserirFinalLLEncDup(LLEncDup ** LL, TINFO info) {
    TDNODO * ult = ObterUltimoNoLLEncDup(*LL);
    TDNODO * aux =  (TDNODO *)malloc(sizeof(TDNODO));

    aux->ant = ult;
    aux->info = info;
    aux->prox = NULL;

    if (ult != NULL) {
        ult->prox = aux;
    } else {
        *LL = aux;
    }
}

TDNODO * RemoverInicioLLEncDup(LLEncDup ** LL) {
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

TDNODO * RemoverFinalLLEncDup(LLEncDup ** LL) {
    TDNODO * aux = ObterPenultimoNoLLEncDup(*LL);
    TDNODO * ptr;
    if (aux == NULL) {
        return RemoverInicioLLEncDup(LL);
    }
    ptr = aux->prox;
    aux->prox = NULL;
    
    return (ptr);
}

void show(TDNODO * LL) {
    while (LL != NULL) {
        printf("--> (%d)", LL->info);
        LL = LL->prox;
    }
}
