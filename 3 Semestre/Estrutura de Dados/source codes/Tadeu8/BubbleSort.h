/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BubbleSort.h
 * Author: Matheus
 *
 * Created on 27 de Setembro de 2016, 13:16
 */

#ifndef BUBBLESORT_H
#define BUBBLESORT_H

template <class T> class BubbleSort {
public:
    //construtores
    BubbleSort();
    BubbleSort(int);
    
    //gets e sets
    void SetElemento(int, T);
    T GetElemento(int);
    int GetTamanho();
    
    //interface do objeto
    void Sort();
    
    void Mostrar();
protected:
    //atributos
    T * vetor;
    int tamanho;
    
    void Trocar(int,int);
};

#endif /* BUBBLESORT_H */

