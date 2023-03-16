/*
 * Faça as adaptações no código para atender os requisitos da solução dos exercícios
 *
 */


#include <cstdlib>
#include <iostream>
#include "LLDupEnc.h"

using namespace std;

typedef struct SDNODO DNODO;
typedef int INFO;

struct SDNODO {
    DNODO * ant;
    INFO info;
    DNODO * prox;
};

void InicializarLLEncDup(DNODO ** LL) {
    *LL = NULL;
}

void InserirInicioLLEncDup(DNODO ** LL, INFO info) {
    DNODO * aux;
    aux = new DNODO;
    aux->info = info;
    aux->ant = NULL;
    aux->prox = NULL;

    if (*LL != NULL) {
        aux->prox = *LL;
        (*LL)->ant = aux;
    }

    *LL = aux;
}

DNODO * ObterUltimoNoLLEncDup(DNODO * LL) {
    DNODO * ant = NULL;
    while (LL != NULL) {
        ant = LL;
        LL = LL->prox;
    }
    return ant;
}

DNODO * ObterPenultimoNoLLEncDup(DNODO * LL) {
    DNODO * ant = NULL;
    if (LL == NULL) {
        return LL;
    }
    while (LL->prox != NULL) {
        ant = LL;
        LL = LL->prox;
    }
    return ant;
}

void InserirFinalLLEncDup(DNODO ** LL, INFO info) {
    DNODO * ult = ObterUltimoNoLLEncDup(*LL);
    DNODO * aux = new DNODO;

    aux->ant = ult;
    aux->info = info;
    aux->prox = NULL;

    if (ult != NULL) {
        ult->prox = aux;
    } else {
        *LL = aux;
    }
}

void RemoverInicioLLEncDup(DNODO ** LL) {
    DNODO * aux;
    if (*LL == NULL) {
        return;
    }
    aux = *LL;
    (*LL) = (*LL)->prox;
    if (*LL != NULL) {
        (*LL)->ant = NULL;
    }
    delete(aux);
}

void RemoverFinalLLEncDup(DNODO ** LL) {
    DNODO * aux = ObterPenultimoNoLLEncDup(*LL);
    DNODO * ptr;
    if (aux == NULL) {
        return RemoverInicioLLEncDup(LL);
    }
    ptr = aux->prox;
    aux->prox = NULL;
    delete(ptr);
}

void show(DNODO * LL) {
    while (LL != NULL) {
        cout << "\n-->" << LL->info;
        LL = LL->prox;
    }
}
