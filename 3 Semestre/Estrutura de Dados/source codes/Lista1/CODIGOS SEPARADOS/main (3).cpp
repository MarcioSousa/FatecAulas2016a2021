#include <iostream>
#include <cstdio>
#include <cstdlib>
//#include <iomanip>

using namespace std;

typedef struct SNODO NODO;
typedef int INFO;

struct SNODO {
    INFO info;
    NODO * prox;
};

void CriarLLEncSimples(NODO **LL) {
    *LL = NULL;
}

void MostrarLLEncSimples(NODO *LL) {
    while (LL != NULL) {
		cout << LL->info << "->";
        LL = LL->prox;
    }
    cout << "/" << endl;
}

void DestruirLLEncSimples(NODO **LL) {
    NODO * aux;
    aux = *LL;
    while (*LL != NULL) {
        *LL = (*LL)->prox;
        delete aux;
        aux = *LL;
    }
}

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
    if (Head == NULL) {
        *Tail = aux;
    }
    *Head = aux;
}

void InserirFinalLLEncSimples1(NODO **LL, INFO info) {
    NODO * aux;
    NODO * tail;
    tail = *LL;
    while (tail != NULL && tail->prox != NULL) { 
        tail = tail->prox;
    }
    aux = new NODO;
    aux->info = info;
    aux->prox = NULL;
    if (tail == NULL) {
        *LL = aux;
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
    if (LL == NULL)
        return LL;
    if (LL->prox == NULL)
        return LL->prox;
    if ((LL->prox)->prox == NULL)
        return LL;
    return ObterEnderecoPenultimoNoLLEncSimples(LL->prox);
}

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

int main() {
    
    NODO * L;

    int num;

    cin >> num;
    
        CriarLLEncSimples(&L);
    while (num != 0) {
        if(num % 2 == 0)
            InserirInicioLLEncSimples(&L, num);
        else
            InserirFinalLLEncSimples1(&L, num);
        cin >> num;
    }

    MostrarLLEncSimples(L);

    if (L != NULL)
        DestruirLLEncSimples(&L);
    
    return 0;
}
