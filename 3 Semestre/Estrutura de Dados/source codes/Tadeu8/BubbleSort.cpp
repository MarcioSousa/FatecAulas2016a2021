/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BubbleSort.cpp
 * Author: Matheus
 * 
 * Created on 27 de Setembro de 2016, 13:16
 */

#include "BubbleSort.h"
#include <cstring>
#include <iostream>

using namespace std;

template <class T>
BubbleSort<T>::BubbleSort() {
    /*tamanho = 1;
    vetor = new int[tamanho];
    memset(vetor,0x0,tamanho * sizeof(int));*/
    BubbleSort(1);
}

template <class T>
BubbleSort<T>::BubbleSort(int tam){
    tamanho = tam;
    vetor = new T[tamanho];
    memset(vetor,0x0,tamanho * sizeof(T));
}

//gets e sets
template <class T>
void BubbleSort<T>::SetElemento(int pos,T val){
    vetor[pos] = val;
}

template <class T>
T BubbleSort<T>::GetElemento(int pos){
    return vetor[pos];
}

template <class T>
int BubbleSort<T>::GetTamanho(){
    return tamanho;
}

template <class T>
void BubbleSort<T>::Trocar(int i,int ii){
    T aux = vetor[i];
    vetor[i] = vetor[ii];
    vetor[ii] = aux;
}

template <class T>
void BubbleSort<T>::Mostrar(){
    for(int i = 0; i < tamanho; i++){
        cout << vetor[i] << "\t";
    }
    cout << endl;
}

//interface do objeto
template <class T>
void BubbleSort<T>::Sort(){
    int i = 0;
    int t = tamanho;
    for (; t > 0; t--){
        for(i = 0; i < (t-1); i++){
            if(vetor[i] > vetor[i+1]){
                Trocar(i,i+1);
            }
        }
    }
}

template class BubbleSort<int>;
template class BubbleSort<float>;
template class BubbleSort<double>;
template class BubbleSort<long int>;
template class BubbleSort<short int>;
template class BubbleSort<long long>;
//template class BubbleSort<char>;