#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef struct SNODO NODO;
typedef float INFO;

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

//removerFinal

void OrdenarLLEncSimples(NODO *LL) {
    NODO *LL2;
    LL2 = LL;
    
    while (LL != NULL) {
    	LL2 = LL->prox;
        while(LL2 != NULL){
            if(LL->info > LL2->info){
                INFO aux = LL->info;
                LL->info = LL2->info;
                LL2->info = aux;
            }
            LL2 = LL2->prox;
        }
        LL = LL->prox;
    }
}

int main(int argc, char** argv) {
    
    NODO * L;
    NODO * L2;
    
    int num, qtd=0;
    
    CriarLLEncSimples(&L);
    CriarLLEncSimples(&L2);

    cin >> num;

        CriarLLEncSimples(&L);
    while (num != 0) {
    	qtd++;
        InserirFinalLLEncSimples1(&L, num);
        cin >> num;
    }
    
    cin >> num;

        CriarLLEncSimples(&L2);
    while (num != 0) {
        InserirFinalLLEncSimples1(&L2, num);
        cin >> num;
    }
    
    NODO *LA = L;
    NODO *LA2 = L2;
    int pos=0;
    
    while (LA2 != NULL) {
    	LA = L;
        pos=0;
        while(LA != NULL){
            if(LA->info == LA2->info){
                cout << pos+1 << "\n";
                break;
            }
            
            LA = LA->prox;
            pos++;
        }
        if(pos == qtd){
        	cout << 0 << "\n";
		}
        LA2 = LA2->prox;
    }

    /*if (L != NULL)
        DestruirLLEncSimples(&L);
    if (L2 != NULL)
        DestruirLLEncSimples(&L2);*/
    
    return 0;
}

