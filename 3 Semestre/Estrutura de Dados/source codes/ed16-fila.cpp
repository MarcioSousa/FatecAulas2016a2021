#include <iostream>

using namespace std;

typedef int INFO;
typedef struct DNODO NODO;

typedef DNODO LLEncDup;
typedef LLEncDup Fila;

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

//FILA
void InicializarFila(Fila ** fila){
	InicializarLLEncDup(fila);
}

void DestruirFila(Fila ** fila){
	DestruirLLEncDup(fila);
}

void Enqueue(Fila ** fila, INFO info){
	InserirFinalLLEncDup(fila, info);
}

NODO * Dequeue(Fila ** fila){
	RemoverInicioLLEncDup(fila);
}

INFO Get(Fila * fila){
	NODO * aux;
	INFO info;
	aux = Dequeue(&fila);//tira ele do começo
	if(aux != NULL){
		info = aux->info;
		Enqueue(&fila,info);//poe ele no final
	}
	return info;
}

int main() {
	
	Fila * fila, * aux;
	
	InicializarFila(&fila);
	
	INFO info;
	
	cin >> info;
	while(info != 0){
		Enqueue(&fila, info);
		cin >> info;
	}
	
	while(fila!=NULL&&aux!=NULL){
		aux=Dequeue(&fila);
		cout << fila;
		cout << aux->info << " ";
	}
	
	return 0;
}

