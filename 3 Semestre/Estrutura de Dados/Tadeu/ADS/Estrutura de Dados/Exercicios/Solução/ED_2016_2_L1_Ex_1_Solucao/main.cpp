/* 
 * File:   main.cpp
 * Author: atm
 *
 * Created on 16 de Agosto de 2016, 11:03
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

/*
 * 
 */

void exibir(long int E, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10) {
    printf("\n\t%d", a1);
    printf("\t%d", a2);
    printf("\t%d", a3);
    printf("\t%d", a4);
    printf("\t%d", a5);
    printf("\t%d", a6);
    printf("\t%d", a7);
    printf("\t%d", a8);
    printf("\t%d", a9);
    printf("\t%d", a10);
    printf("\t= %ld", E);

}

int main(int argc, char** argv) {

    long int E;
    int a1, a2, a3, a4, a5, a6, a7, a8, a9, a10;
    long int num;
    long int vezes;
    long int comparacoes;
    long int acertos;

    E = 0.0;
    a1 = a2 = a3 = a4 = a5 = a6 = a7 = a8 = a9 = a10 = 0;
    vezes = 0;
    acertos = 0;
    comparacoes = 0;

    cout << "\nInforme o numero: ";
    cin >> num;
    
    for (a10 = 0; a10 < 5; a10++) {
        for (a9 = 0; a9 < 5; a9++) {
            for (a8 = 0; a8 < 5; a8++) {
                for (a7 = 0; a7 < 5; a7++) {
                    for (a6 = 0; a6 < 5; a6++) {
                        for (a5 = 0; a5 < 5; a5++) {
                            for (a4 = 0; a4 < 5; a4++) {
                                for (a3 = 0; a3 < 5; a3++) {
                                    for (a2 = 0; a2 < 5; a2++) {
                                        for (a1 = 0; a1 < 5; a1++) {
                                            E = (a1 * 1) +
                                                    (a2 * 2) +
                                                    (a3 * 3) +
                                                    (a4 * 4) +
                                                    (a5 * 5) +
                                                    (a6 * 6) +
                                                    (a7 * 7) +
                                                    (a8 * 8) +
                                                    (a9 * 9) +
                                                    (a10 * 10);
                                            vezes++;
                                            comparacoes++;
                                            if (E == num) {
                                                exibir(E, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
                                                acertos++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << "\n\n";
    cout << "\nRepeticoes : " << vezes;
    cout << "\nAcertos    : " << acertos;
    cout << "\nComparacoes: " << comparacoes;
    cout << "\nTotal Comparacoes + Acertos: " << acertos + comparacoes;
    cout << "\n\n";
}

