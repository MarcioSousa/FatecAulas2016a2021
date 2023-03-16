#include <iostream>
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
	
    NODO * L;
    NODO * T;
    NODO * aux = new NODO;
    INFO ia;
    
    CriarLLEncSimples(&L);
    CriarLLEncSimples(&T);
    CriarLLEncSimples(&aux);
    
    cin >> ia.x1 >> ia.y1 >> ia.x2 >> ia.y2;
    while (ia.x1+ia.y1+ia.x2+ia.y2 != 0) {
    	ia.tamanho = sqrt((pow(ia.x1-ia.x2,2) + pow(ia.y1-ia.y2,2)));
        InserirFinalLLEncSimples2(&L,&T,ia);
        
        cin >> ia.x1 >> ia.y1 >> ia.x2 >> ia.y2;
    }

    NODO *L2 = L;
    while (L2 != NULL) {
        cout << setprecision(2) << fixed << L2->info.tamanho<< endl;
        L2 = L2->prox;
    }

    if (L != NULL)
        DestruirLLEncSimples(&L);
    
    return 0;
}
