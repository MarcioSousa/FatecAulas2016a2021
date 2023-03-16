#include <iostream>

using namespace std;

typedef int INFO;
typedef struct DNODO NODO;

struct DNODO{
	INFO info;
	NODO * prox;
	NODO * ant;
};

void InicializarLLEncDup(NODO ** LLDup){
	*LLDup = NULL;
}

void MostrarLLEncSimples(NODO *LLDup) {
    while (LLDup != NULL) {
		cout << LLDup->info << "->";
        LLDup = LLDup->prox;
    }
    cout << "/" << endl;
}

void DestruirLLEncDup(NODO ** LLDup){
	NODO * aux;
    aux = *LLDup;
    while (*LLDup != NULL) {
        *LLDup = (*LLDup)->prox;
        delete aux;
        aux = *LLDup;
    }
}

void InserirInicioLLEncDup(NODO ** LLDup, INFO info){
	NODO * aux;
	aux->ant = NULL;
	aux->info = info;
	aux->prox = *LLDup;
	*LLDup = aux;
}

NODO* RemoverInicioLLEncDup(NODO ** LLDup){
	NODO * aux;
	aux = *LLDup;
	if(LLDup == NULL){
		return *LLDup;
	}
	*LLDup = (*LLDup)->prox;
	if(*LLDup != NULL){
		(*LLDup)->ant = NULL;
	}
	aux->prox = NULL;
	return aux;
}

NODO * ObterUltimoNodoLLEndDup(NODO * LLEncDup){
	NODO * aux;
	aux = LLEncDup;
	while(aux != NULL && aux->prox != NULL){
		aux = aux->prox;
	}
	return aux;
}

void InserirFinalLLEncDup(NODO ** LLEncDup, INFO info){
	NODO * aux;
	NODO * aux2;
	aux = ObterUltimoNodoLLEndDup(*LLEncDup);
	aux2 = new NODO;
	aux2->info = info;
	aux2->prox = NULL;
	aux2->ant = aux;
	if(aux != NULL){
		aux->prox = aux2;
	}else{
		*LLEncDup = aux2;
	}
}

NODO * RemoverFinalLLEncDup(NODO ** LLEncDup){
	NODO *ult,*pnult;
	ult = ObterUltimoNodoLLEndDup(*LLEncDup);
	if(ult != NULL){
		pnult = ult->ant;
		if(pnult != NULL){
			pnult->prox = NULL;
		}else{
			*LLEncDup = NULL;
		}
		ult->ant = NULL;
	}else{
		*LLEncDup = NULL;
	}
	return ult;
}

void OrdenarLLEncDup(NODO *LL) {
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

int main() {
	//usar atribuicao <-(pseudocodigo) ao inves de =(linguagem C) dah wrong type argumento to unary minus
	
	NODO * LLDup;
	
	InicializarLLEncDup(&LLDup);
	
	INFO info;
	
	cin >> info;
	while(info != 0){
		InserirFinalLLEncDup(&LLDup, info);
		cin >> info;
	}
	
	MostrarLLEncSimples(LLDup);
	
	OrdenarLLEncDup(LLDup);
	
	MostrarLLEncSimples(LLDup);
	
	return 0;
}
