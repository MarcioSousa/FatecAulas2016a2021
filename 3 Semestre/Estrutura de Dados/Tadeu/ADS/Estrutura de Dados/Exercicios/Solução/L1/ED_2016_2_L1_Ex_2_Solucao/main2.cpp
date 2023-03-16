/* 
 * File:   main.cpp
 * Author: atm
 *
 * Created on 16 de Agosto de 2016, 11:38
 */

#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <math.h>
#include <limits.h>

using namespace std;

/*
 * 
 */
void swap(int v[], int pos1, int pos2) {
    int aux;
    aux = v[pos1];
    v[pos1] = v[pos2];
    v[pos2] = aux;
}

long int BubbleSortFull(int v[], int size) {
    bool trocou = true;
    int indx;
    long int trocas = 0;
    while (trocou) {
        trocou = false;
        for (indx = 0; indx < size - 1; indx++) {
            if (v[indx] > v[indx + 1]) {
                swap(v, indx, indx + 1);
                trocou = true;
                trocas++;
            }
        }
    }
    return trocas;
}

long int SelectionSort(int v[], int size) {
    int indx1, indx2;
    int trocas = 0;

    for (indx1 = 0; indx1 < (size - 1); indx1++) {
        for (indx2 = indx1; indx2 < size; indx2++) {
            if (v[indx1] > v[indx2]) {
                swap(v, indx1, indx2);
                trocas++;
            }
        }
    }

    return trocas;
}

long int InsertionSort(int v[], int size) {
    int indx1, indx2;
    int sel = 0;
    int trocas = 0;

    for (indx1 = 0; indx1 < (size - 1); indx1++) {
        sel = indx1;
        for (indx2 = indx1; indx2 < size; indx2++) {
            if (v[sel] > v[indx2]) {
                sel = indx2;
            }
        }
        if (sel > indx1) {
            swap(v, indx1, sel);
            trocas++;
        }
    }
    return trocas;
}

void copyvec(int v1[], int v2[], int tam) {
    int indx = 0;
    for (indx = 0; indx < tam; indx++) {
        v2[indx] = v1[indx];
    }
}

void show(int v[], int tam) {
    int indx = 0;
    cout << "\n";
    for (indx = 0; indx < tam; indx++) {
        cout << "\t" << v[indx];
    }
}

int main(int argc, char** argv) {

    //int v[10] = {123, 44, 55, 1982, 3, 2354, 65322, 1, 10, 85};
    int v[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int vp[10];
    int vmax[10];
    int vmin[10];
    int max = 0;
    int min = 0;
    int res = 0;
    int res2 = 0;
    int res3 = 0;
    int indx1 = 0;
    int indx2 = 0;
    BubbleSortFull(v, 10);
    copyvec(v, vp, 10);
    copyvec(v, vmax, 10);
    copyvec(v, vmin, 10);
    min = INT_MAX;
    max = INT_MIN;
    for (indx1 = 0; indx1 < 10; indx1++) {
        for (indx2 = indx1; indx2 < 10; indx2++) {
            res = BubbleSortFull(vp, 10);
            copyvec(v, vp, 10);
            res2 = SelectionSort(vp, 10);
            copyvec(v, vp, 10);
            res3 = InsertionSort(vp, 10);
            /*
            if (res3 > max) {
                max = res3;
                copyvec(v, vmax, 10);
            }
            if (res3 < min) {
                min = res3;
                copyvec(v, vmin, 10);
            }
            */
            cout << "\n--> Trocas Bubble:    " << res;
            cout << "\n--> Trocas Selection: " << res2;
            cout << "\n--> Trocas Insertion: " << res3;
            //show(v, 10);
            swap(v, indx1, indx2);
            copyvec(v, vp, 10);
        }
    }

    //cout << "\nMinimo: " << min << endl;
    //show(vmin, 10);
    //cout << "\nMaximo: " << max << endl;
    //show(vmax, 10);

    return 0;
}

