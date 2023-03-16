/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Matheus
 *
 * Created on 4 de Outubro de 2016, 13:51
 */

#include <cstdlib>
#include <iostream>
#include <cstdio>

typedef struct SNODO NODO; //typedef define um tipo de def
typedef int INFO; //INFO é um int, SNODO é um NODO

using namespace std;

struct SNODO{
    INFO info; 
    NODO * prox;//declaracao variavel ponteiro para NODO
};

void CriarLLEncSimples(NODO ** LL){//** é passagem de parametro de um ponteiro por referencia
    *LL = NULL;//para o programa acessar o conteudo de LL, não LL
}

void MostrarLLEncSimples(NODO * LL){//aqui n recebemos o ponteiro por referencia pq n iremos alterar a lista
    while(LL != NULL){
        printf("[%x]:[%d]->[%x]\n",LL,LL->info,LL->prox);
        LL = LL->prox;
    }
}

void DestruirLLEncSimples(NODO ** LL){//ponteiro passado por referencia pq precisamos alterar o conteudo da lista
    NODO * aux;
    aux = *LL;
    while(*LL != NULL){
        MostrarLLEncSimples(*LL);
        *LL = (*LL)->prox;
        delete aux;
        aux = *LL;
    }
}

int main(int argc, char** argv) {
    
    NODO * LHead;
    NODO * aux;
    NODO * aux2;
    NODO * aux3;
    
    CriarLLEncSimples(&LHead);//inicializa
    
    aux = new NODO;
    aux->info = 10;
    aux->prox = NULL;
    
    LHead = aux;//adiciona na mao um elemento na lista
    
    aux2 = new NODO;
    aux2->info = 20;
    aux2->prox = NULL;
    aux->prox = aux2;
    
    aux3 = new NODO;
    aux3->info = 30;
    aux3->prox = NULL;
    aux2->prox = aux3;
    
    MostrarLLEncSimples(LHead);
    printf("\n\n");
    DestruirLLEncSimples(&LHead);
    printf("\n\n");
    MostrarLLEncSimples(LHead);
    
    return 0;
}

