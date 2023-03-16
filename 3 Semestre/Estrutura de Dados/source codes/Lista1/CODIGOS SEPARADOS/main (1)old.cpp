/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Matheus Arruda
 *
 * Created on 14 de Outubro de 2016, 13:43
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>

using namespace std;

typedef struct SNODO NODO;
typedef double INFO;

struct SNODO {
    INFO info;   //conteudo do nodo
    NODO * prox; //ponteiro, guarda o endereço para uma estrutura nodo
};

void CriarLLEncSimples(NODO **LL) {
    *LL = NULL;
}

void MostrarLLEncSimples(NODO *LL) {
	while (LL != NULL) {
        //cout << LL->info << "->";
		cout << setw(8) << setprecision(2) << fixed << LL->info << "->"; //setw ou %6.2f               
        LL = LL->prox; //isto n altera o LL original
    }
    cout << "/" << endl;
}

void DestruirLLEncSimples(NODO **LL) {
    NODO * aux;
    aux = *LL;
    while (*LL != NULL) {
        //MostrarLLEncSimples(*LL);
        *LL = (*LL)->prox;
        delete aux;
        aux = *LL;
    }
}

//A PARTIR DAQUI EH CODIGO PASSADO NA LOUSA

void InserirInicioLLEncSimples(NODO **LL, INFO info) {
    NODO * aux;
    aux = new NODO;
    aux->info = info;
    aux->prox = *LL;
    *LL = aux;
}

void InserirInicioLLEncSimples2(NODO **Head, NODO **Tail, INFO info) {
    NODO * aux;
    aux = new NODO;
    aux->info = info;
    aux->prox = *Head;
    if (Head == NULL) {//se a lista era vazia, elemento eh head e tail
        *Tail = aux;
    }
    *Head = aux;
}

void InserirFinalLLEncSimples1(NODO **LL, INFO info) {
    NODO * aux;
    NODO * tail;
    tail = *LL;
    while (tail != NULL && tail->prox != NULL) { //acha tail
        tail = tail->prox;
    }
    aux = new NODO;
    aux->info = info;
    aux->prox = NULL;
    if (tail == NULL) {
        *LL = aux; //se tail = null, lista eh vazia e LL deve ser iniciado
        tail = aux;
    } else {
        tail->prox = aux;
    }
}

void InserirFinalLLEncSimples2(NODO **Head, NODO **Tail, INFO info) {
    NODO * aux = new NODO;
    aux->info = info;
    aux->prox = NULL;
    if (*Tail == NULL) {
        *Head = aux;
        *Tail = aux;
    } else {
        (*Tail)->prox = aux;
        *Tail = aux;
    }
}

NODO * RemoverInicioLLEncSimples1(NODO ** LL) {
    NODO * aux = *LL;
    if (aux != NULL) {
        *LL = aux->prox;
        aux->prox = NULL;
    }
    return (aux);
}

NODO * RemoverInicioLLEncSimples2(NODO * Head, NODO * Tail) {
    NODO * aux = Head;
    if (aux != NULL) {
        Head = aux->prox;
        aux->prox - NULL;
        if (Head == NULL) {
            *Tail = *Head;
        }
    }
    return (aux);
}

NODO * ObterEnderecoPenultimoNoLLEncSimples(NODO * LL) {
    if (LL == NULL) //vazia
        return LL;
    if (LL->prox == NULL) //1 elemento
        return LL->prox;
    if ((LL->prox)->prox == NULL) //mais de 1 elemento
        return LL;
    return ObterEnderecoPenultimoNoLLEncSimples(LL->prox);
}

//removerFinal

void OrdenarLLEncSimples(NODO *LL) {
    NODO *LL1, *LL2;
    LL1 = LL;
    LL2 = LL1;
    
    while (LL1 != NULL) {
        while(LL2 != NULL){
            if(LL1->info < LL2->info){
                float aux = LL1->info;
                LL1->info = LL2->info;
                LL2->info = aux;
            }
            LL2 = LL2->prox;
        }
        LL1 = LL1->prox;
        LL2 = LL;
    }
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//InserirInicio, InserirFinal, RemoverInicio, RemoverFinal, CriarLista, InicializarLista, //InserirPosN, RemoverPosN, IrParaPosN

int main() {
    
    NODO * L;

    double num;

    cin >> num;

    //if (num != 0)
        CriarLLEncSimples(&L);
    while (num != 0) {
        InserirFinalLLEncSimples1(&L, num);
        cin >> num;
    }

    MostrarLLEncSimples(L);

    if (L != NULL)
        DestruirLLEncSimples(&L);
    
    return 0;
}
