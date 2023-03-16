/*
 * Faça as adaptações no código para atender os requisitos da solução dos exercícios
 *
 */


#include <cstdlib>
#include <iostream>
//#include "LLDupEnc.h"

using namespace std;

typedef struct SDNODO DNODO;
typedef char INFO;

typedef DNODO Pilha;

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
    DNODO * ant = NULL;
    while (LL != NULL) {
        ant = LL;
        LL = LL->prox;
    }
    return ant;
}

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
    DNODO * ult = ObterUltimoNoLLEncDup(*LL);
    DNODO * aux = new DNODO;

    aux->ant = ult;
    aux->info = info;
    aux->prox = NULL;

    if (ult != NULL) {
        ult->prox = aux;
    } else {
        *LL = aux;
    }
}

void RemoverInicioLLEncDup(DNODO ** LL) {
    DNODO * aux;
    if (*LL == NULL) {
        return;
    }
    aux = *LL;
    (*LL) = (*LL)->prox;
    if (*LL != NULL) {
        (*LL)->ant = NULL;
    }
    delete(aux);
}

void RemoverFinalLLEncDup(DNODO ** LL) {
    DNODO * aux = ObterPenultimoNoLLEncDup(*LL);
    DNODO * ptr;
    if (aux == NULL) {
        return RemoverInicioLLEncDup(LL);
    }
    ptr = aux->prox;
    aux->prox = NULL;
    delete(ptr);
}

void show(DNODO * LL) {
    while (LL != NULL) {
        cout << "\n-->" << LL->info;
        LL = LL->prox;
    }
}

void Push(Pilha ** pilha, INFO info){
	InserirFinalLLEncDup(pilha, info);
}

DNODO * Pop(Pilha ** pilha){
	RemoverFinalLLEncDup(pilha);
}

INFO Get(Pilha * pilha){
	DNODO * aux;
	INFO info;
	aux = Pop(&pilha);
	if(aux != NULL){
		info = aux->info;
		Push(&pilha,info);
	}
	return info;
}

int main(){
	const int tam=20;

	char ent[tam];
	ent[0]='\0';
	Pilha * p;
	p = new Pilha;
	
	for(int i=0; i<20; i++){
		ent[i]='\0';
	}
	
	cin >> ent;
	
	int te=0;
	for(int i=0; i<20 || ent[i]=='\0';i++){
		Push(&p,ent[i]);
		te++;
	}
	
	//vou ter q guardar o dado da pilha pra usar depois
	char sai[te];
	
	for(int i=0; i<te/2, i++){
		sai[i] = Pop(p);
	}
	
	Pop(p);
	
	bool eh = true;
	for(int i=0; i<te/2, i++){
		if(sai[te+i] != (Pop(p))->info){
			eh = false;
		}
	}
	
	
	return 0;
}
