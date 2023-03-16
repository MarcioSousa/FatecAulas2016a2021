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
        cout << LL->info;
        LL = LL->prox;
    }
    cout<<"/"<<endl;
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
	
	const int tam=20;

	char ent[tam];
	char m[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};//26
	
	Fila * f;
	bool b1=false, b2=false;
	
	f = new Fila;
	InicializarLLEncDup(&f);
	
	//esqueci a funcao que limpa string
	for(int i=0; i<20; i++){
		ent[i]='\0';
	}
	
	cin >> ent;
	while(ent[0] != '0'){
		for(int i=0; i<tam && ent[i]!='\0';i++){
			Enqueue(&f,ent[i]);
		}
		
		//copiar fila para mostrar depois
		
		char c = Get(f);
		for(int i=0; i<26; i++){
			if(c == m[i]){
				b1=true;
				break;
			}
		}
		
		while(f != NULL){
			c = Get(f);
			Dequeue(&f);
		}
		
		for(int i=0; i<26; i++){
			if(c == m[i]){
				b2=true;
				break;
			}
		}
		
		cout << (b1&&b2?"(sim)":"(nao)");
		cout<<endl;
		
		//reset
		InicializarLLEncDup(&f);
		b1=false;
		b2=false;
		for(int i=0; i<20; i++){
			ent[i]='\0';
		}
		
		cin >> ent;
	}
	
	return 0;
}
