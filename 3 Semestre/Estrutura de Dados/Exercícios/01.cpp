/* 
 * File:   main.cpp
 * Author: atm
 *
 * Created on 17 de Novembro de 2017, 16:17
 */
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
int main(int argc, char** argv) {

    LLEncDup * LL;
    TDNODO * aux;
    
    InicializarLLEncDup(&LL);
    InserirInicioLLEncDup(&LL,10);
    InserirInicioLLEncDup(&LL,20);
    InserirInicioLLEncDup(&LL,30);
    InserirInicioLLEncDup(&LL,40);
    InserirFinalLLEncDup(&LL,10);
    InserirFinalLLEncDup(&LL,20);
    InserirFinalLLEncDup(&LL,30);
    InserirFinalLLEncDup(&LL,40);
    //aux = RemoverInicioLLEncDup(&LL);
    //aux = RemoverFinalLLEncDup(&LL);
    
    printf("\n(LL)");
    show(LL);
    
    return 0;
}
