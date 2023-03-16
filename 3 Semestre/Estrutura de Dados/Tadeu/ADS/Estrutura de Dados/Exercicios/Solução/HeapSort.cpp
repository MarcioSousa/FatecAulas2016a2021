/* 
 * File:   main.cpp
 * Author: atm
 *
 * Created on 8 de Setembro de 2016, 21:46
 */

int sizeheap = 100;


#include <cstdlib>
#include <iostream>

using namespace std;

void show(int v[],int size)
{
    int tam = 1;
    for (;tam <= size; tam++)
    {
        cout << v[tam] << "\t";
    }
    cout << endl;
}

int left(int i) {
    return 2 * i;
}

int right(int i) {
    return 2 * i + 1;
}

void swap(int * a, int * b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void MaxHeapfy(int v[], int i) {
    int l = left(i);
    int r = right(i);
    int maior;

    if (l <= sizeheap && v[l] > v[i]) {
        maior = l;
    } else {
        maior = i;
    }
    if (r <= sizeheap && v[r] > v[maior]) {
        maior = r;
    }
    if (maior != i) {
        swap(&v[i], &v[maior]);
        MaxHeapfy(v, maior);
    }
}

void BuildMaxHeap(int v[]) {
    int indx = (int) (sizeheap / 2);
    for (; indx > 0; indx--) {
        MaxHeapfy(v, indx);
    }
}

void HeapSort(int v[]) {
    BuildMaxHeap(v);
    int indx = sizeheap;
    for (; indx > 0; indx--) {
        swap(&v[1],&v[indx]);
        sizeheap--;
        MaxHeapfy(v, 1);
    }
}

void RandomizeVector(int v[],int lim,int tam)
{
    time_t sec;
    int indx = 1;
    int x;

    time(&sec);
    srand((uint) sec);

    for (; tam > 0; tam--, indx++) {
        v[indx] = (rand() % lim);
    }
}


/*
 * 
 */
int main(int argc, char** argv) {

    int v[101];
    int indx;
    int size = sizeheap;

    RandomizeVector(v,10000,sizeheap);
    
    show(v,100);
    
    HeapSort(v);

    for (indx = 1; indx <= size; indx++) {
        cout << "[" << indx << "] = " << v[indx] << endl;
    }

    return 0;
}


