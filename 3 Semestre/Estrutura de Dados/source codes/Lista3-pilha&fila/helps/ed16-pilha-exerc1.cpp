#include <iostream>

using namespace std;

typedef int INFO;
typedef struct DNODO NODO;

typedef DNODO LLEncDup;
typedef LLEncDup Pilha;

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
	if(LLDup != NULL){
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

//PILHA
void InicializarPilha(Pilha ** pilha){
	InicializarLLEncDup(pilha);
}

void DestruirPilha(Pilha ** pilha){
	DestruirLLEncDup(pilha);
}

void Push(Pilha ** pilha, INFO info){
	InserirFinalLLEncDup(pilha, info);
}

NODO * Pop(Pilha ** pilha){
	RemoverFinalLLEncDup(pilha);
}

INFO Get(Pilha * pilha){
	NODO * aux;
	INFO info;
	aux = Pop(&pilha);
	if(aux != NULL){
		info = aux->info;
		Push(&pilha,info);
	}
	return info;
}

int main() {
	Pilha * pilha, * aux;
	
	InicializarPilha(&pilha);
	
	INFO info;
	
	cin >> info;
	while(info != 0){
		Push(&pilha, info);
		cin >> info;
	}
	
	while(pilha!=NULL&&aux!=NULL){
		aux=Pop(&pilha);
		cout << aux->info << " ";
	}
	
	return 0;
}

