/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Matheus
 *
 * Created on 27 de Setembro de 2016, 13:15
 */

#include "BubbleSort.h"
#include <cstdlib>
#include <iostream>

#define TAM 10

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    BubbleSort<float> bs(TAM);//estatico
    
    int i = 0, valor;
    
    for(; i < TAM; i++){
        //cout << "informe o valor: " ;
        //cin >> valor;
        bs.SetElemento(i,/*valor*/10.10-(i+((float)i)/10));
    }
    
    //system("cls");
    bs.Mostrar();
    
    bs.Sort();
    
    bs.Mostrar();
    
    return 0;
}

