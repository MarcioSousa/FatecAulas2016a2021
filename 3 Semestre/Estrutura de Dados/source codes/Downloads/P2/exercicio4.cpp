/*
 * Faça as adaptações no código para atender os requisitos da solução dos exercícios
 *
 */


#include <cstdlib>
#include <iostream>
//#include "LLDupEnc.h"

using namespace std;

typedef struct SDNODO DNODO;
typedef int INFO;

typedef DNODO Fila;

struct SDNODO {
    DNODO * ant;
    INFO info;
    DNODO * prox;
};

void InicializarLLEncDup(DNODO ** LL) {
    *LL = NULL;
}

void InserirInicioLLEncDup(DNODO ** LL, INFO info) {
    DNODO * aux;
    aux = new DNODO;
    aux->info = info;
    aux->ant = NULL;
    aux->prox = NULL;

    if (*LL != NULL) {
        aux->prox = *LL;
        (*LL)->ant = aux;
    }

    *LL = aux;
}

DNODO * ObterUltimoNoLLEncDup(DNODO * LL) {
    DNODO * aux;
    aux = LL;
    while(aux != NULL && aux->prox != NULL){
    	aux = aux->prox;
	}
    return aux;
}

/*DNODO * ObterUltimoNoLLEncDup(DNODO * LL) {
    DNODO * ant = NULL;
    while (LL != NULL) {
        ant = LL;
        LL = LL->prox;
    }
    return ant;
}*/

DNODO * ObterPenultimoNoLLEncDup(DNODO * LL) {
    DNODO * ant = NULL;
    if (LL == NULL) {
        return LL;
    }
    while (LL->prox != NULL) {
        ant = LL;
        LL = LL->prox;
    }
    return ant;
}

void InserirFinalLLEncDup(DNODO ** LL, INFO info) {
    DNODO * aux;
    DNODO * aux2;
    aux = ObterUltimoNoLLEncDup(*LL);
    
    aux2 = new DNODO;
    aux2->info = info;
    aux2->prox = NULL;
    aux2->ant = aux;

    if (aux != NULL) {
        aux->prox = aux2;
    } else {
        *LL = aux2;
    }
}

DNODO *  RemoverInicioLLEncDup(DNODO ** LL) {
    DNODO * aux;
    if (*LL == NULL) {
        return NULL;
    }
    aux = *LL;
    (*LL) = (*LL)->prox;
    if (*LL != NULL) {
        (*LL)->ant = NULL;
	}
    aux->prox = NULL;
    return(aux);
}

DNODO * RemoverFinalLLEncDup(DNODO ** LL) {
    DNODO * ult, * pnult;
    ult = ObterUltimoNoLLEncDup(*LL);
    if(ult != NULL){
    	pnult = ult->ant;
    	if(pnult != NULL){
    		pnult->prox = NULL;
		}else{
			*LL = NULL;
		}
		ult->ant = NULL;
	}else{
		*LL = NULL;
	}
    return ult;
}

void show(DNODO * LL) {
    while (LL != NULL) {
        //cout << "\n-->" << LL->info;
        cout << LL->info << " ";
        LL = LL->prox;
    }
    cout<<endl;
}

void Enqueue(Fila ** fila, INFO info){
	InserirFinalLLEncDup(fila, info);
}

DNODO * Dequeue(Fila ** fila){
	RemoverInicioLLEncDup(fila);
}

INFO Get(Fila * fila){
	DNODO * aux;
	INFO info;
	aux = Dequeue(&fila);
	if(aux != NULL){
		info = aux->info;
		Enqueue(&fila,info);
	}
	return info;
}

int main(){
	const int tam=10;//tam=10
	
	Fila * f, * f2, * f3;
	
	f = new Fila;
	f2 = new Fila;
	f3 = new Fila;
	InicializarLLEncDup(&f);
	InicializarLLEncDup(&f2);
	InicializarLLEncDup(&f3);
	
	int num;
	
	for(int i=0; i<tam/2; i++){
		cin >> num;
		Enqueue(&f,num);
	}
	
	for(int i=0; i<tam/2; i++){
		cin >> num;
		Enqueue(&f2,num);
	}
	
	//show(f);
	//show(f2);
	
	DNODO *aux,*aux2;
	
	aux=Dequeue(&f);
	aux2=Dequeue(&f2);
	
	while(aux != NULL || aux != NULL){//considerar que valores estarao em ordem crescente nas filas
		if(aux != NULL && aux2 != NULL){
			while(aux->info<=aux2->info){
				Enqueue(&f3,aux->info);
				aux=Dequeue(&f);
				if(aux == NULL) break;
			}
		}
		if(aux2 != NULL && aux != NULL){
			while(aux->info>=aux2->info){
				Enqueue(&f3,aux2->info);
				aux2=Dequeue(&f2);
				if(aux2 == NULL) break;
			}
		}
		if(aux == NULL){
			while(aux2 != NULL){
				Enqueue(&f3,aux2->info);
				aux2=Dequeue(&f2);
			}
		}
		if(aux2 == NULL){
			while(aux != NULL){
				Enqueue(&f3,aux->info);
				aux=Dequeue(&f);
			}
		}
	}
	
	show(f3);
	
	return 0;
}
