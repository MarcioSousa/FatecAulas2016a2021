#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <math.h>
#include <iomanip>

using namespace std;

typedef struct SNODO NODO;
typedef struct Coord INFO;

struct Coord {
    float x1;
    float y1;
    float x2;
    float y2;
    float tamanho;
};

struct SNODO {
    INFO info;
    NODO * prox;
};

void CriarLLEncSimples(NODO **LL) {
    *LL = NULL;
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

//removerFinal

int main(int argc, char** argv) {
    
    //float
    //pitagoras
    
    //171	27	C:\Users\Matheus\Desktop\exerc3.cpp	[Error] base operand of '->' has non-pointer type 'INFO {aka Coord}' 
    //erro pq operador -> eh para ponteiro, nao struct, struct eh . ;
    
    NODO * L;
    NODO * aux = new NODO;
    INFO ia;
    
    CriarLLEncSimples(&L);
    CriarLLEncSimples(&aux);
    
    cin >> ia.x1 >> ia.y1 >> ia.x2 >> ia.y2;
    while (ia.x1+ia.y1+ia.x2+ia.y2 != 0) {
    	//se tamanho < 0 entao tamanho*-1
    	ia.tamanho = sqrt((pow(ia.x1-ia.x2,2) + pow(ia.y1-ia.y2,2)));
        InserirFinalLLEncSimples1(&L, ia);
        
        cin >> ia.x1 >> ia.y1 >> ia.x2 >> ia.y2;
    }

    NODO *L2 = L;
    while (L2 != NULL) {
        cout << setprecision(2) << fixed << L2->info.tamanho;
        L2 = L2->prox;
        cout << endl;
    }

    if (L != NULL)
        DestruirLLEncSimples(&L);
    
    return 0;
}
