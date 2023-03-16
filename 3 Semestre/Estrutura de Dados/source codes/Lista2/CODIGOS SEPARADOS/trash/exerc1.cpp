#include <iostream>

using namespace std;

typedef struct SNODO NODO;
typedef float INFO;

struct SNODO {
    INFO info;
    NODO * prox;
};

struct SCoordNODO {
    float x1;
    float y1;
    float x2;
    float y2;
    float tamanho;
    SCoordNODO * prox;
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
    if (LL->prox == NULL) //1 elemento
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

void PrevLLEncSimples(NODO **LL, int pos, INFO info){//inclui um nó na LLEncSimples antes do elemento indicado por posicao
    
    NODO * L2;
    L2 = *LL;
    
    if((L2) == NULL || pos <= 1 || L2->prox == NULL){ //se lista eh vazia, insere no inicio
    	InserirInicioLLEncSimples(LL,info);
	}else{ //se lista nao eh vazia
		NODO * aux = new NODO;
    	aux->info = info;
    	aux->prox = NULL;
		
		int i=0;
		for(; i<pos-2; i++){ //acha posicao anterior a posicao passada
	    	if((L2->prox) != NULL){
	    		(L2) = (L2)->prox;
			}
		}
		if(i == pos-2){//se chegou ao final, achando a posicao anterior
			aux->prox = (L2)->prox;
			(L2)->prox = aux;
		}
	}
}

void SuccLLEncSimples(NODO **LL, int pos, INFO info){//inclui um nó na LLEncSimples depois do elemento indicado por posicao
    
    NODO * L2;
    L2 = *LL;
    
    if((L2) == NULL || pos <= 0){
    	InserirFinalLLEncSimples1(LL,info);
	}else{
		NODO * aux = new NODO;
    	aux->info = info;
    	aux->prox = NULL;
		
		int i=0;
		for(; i<pos-1; i++){
	    	if((L2) != NULL){
	    		(L2) = (L2)->prox;
			}
			else{
				InserirFinalLLEncSimples1(LL,info);
				break;
			}
		}
		
	    if(i == pos-1 && L2 != NULL){
			aux->prox = (L2)->prox;
	    	(L2)->prox = aux;
		}
	}
}

int main(int argc, char** argv) {
    
    NODO * L;
    
    CriarLLEncSimples(&L);

    char c;
    int n1, n2;
    
    cin >> c;
    while(c != 'F'){
        if(c == 'P'){
        	cin >> n1 >> n2;
            PrevLLEncSimples(&L, n1, n2);
        }
        if(c == 'S'){
        	cin >> n1 >> n2;
            SuccLLEncSimples(&L, n1, n2);
        }
        
        cin >> c;
    }

    MostrarLLEncSimples(L);

    if (L != NULL)
        DestruirLLEncSimples(&L);
    
    return 0;
}

