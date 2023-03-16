#include <iostream>

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

void PrevLLEncSimples(NODO **LL, int pos, INFO info){//inclui um nó na LLEncSimples antes do elemento indicado por posicao
    
    NODO * L2;
    L2 = *LL;
    
    if((L2) == NULL || pos <= 1 || L2->prox == NULL){ //se lista eh vazia OU posicao nao <= 1 OU soh existe 1 elemento na lista
    	InserirInicioLLEncSimples(LL,info);
	}
	else{ //se lista nao eh vazia
		NODO * aux = new NODO;
    	aux->info = info;
		
		int i=1;
		for(; i<pos-1;){ //acha posicao anterior a posicao passada
	    	if((L2->prox) != NULL){
	    		(L2) = (L2)->prox;
	    		i++;
			}else{
				break;
			}
		}
		//i == pos-1 && 
		if(L2->prox != NULL){//se achou posicao anterior e a prox (que eu insiro antes) nao eh nula
			aux->prox = (L2)->prox;
			(L2)->prox = aux;
		}else{
			InserirInicioLLEncSimples(LL,info);
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

