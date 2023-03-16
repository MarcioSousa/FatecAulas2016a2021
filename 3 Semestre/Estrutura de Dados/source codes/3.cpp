#include <cstdlib>
#include <iostream>
#include <cstdio>

using namespace std;

//troca valores entre posicoes
void swap(int v[], int pos1, int pos2) {
    int aux;
    aux = v[pos1];
    v[pos1] = v[pos2];
    v[pos2] = aux;
}

//
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

long int SelectionSortFull(int v[], int size) {
    bool trocou = true;
    long int trocas = 0;
    
    int i, j;
    for(i = 0; i < 10; i++)
    {
		for(j = i; j < 10; j++)
		{
			if(v[i] > v[j])
			{
				swap(v, i, j);
				trocas++;
			}
		}
	}
		
    return trocas;
}

long int InsertionSortFull(int v[], int size) {
    bool trocou = true;
    long int trocas = 0;
    
    int i, j, a;
    
    for(i = 0; i < 10; i++)
    {
		a = i;
		
		for(j = i; j < 10; j++)
		{
			if(v[a] > v[j])
			{
				a = j;
			}
		}
		
		if(a != i)
		{
			swap(v, a, i);
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
    //cout << "\n";
    for (indx = 0; indx < tam; indx++) {
        cout << " " << v[indx];
    }
}

int main(int argc, char** argv) {

    //int v[10] = {123, 44, 55, 1982, 3, 2354, 65322, 1, 10, 85};
    int v[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int vp[10];
    int vmax[10];
    int vmin[10];
    int max = INT_MIN;
    int min = INT_MAX;
    int res = 0;
    int indx1 = 0;
    int indx2 = 0;
    
    //BubbleSortFull(v, 10);
    
    copyvec(v, vp, 10);
    copyvec(v, vmax, 10);
    copyvec(v, vmin, 10);
    
    for (indx1 = 0; indx1 < 10; indx1++) {
        for (indx2 = indx1; indx2 < 10; indx2++) {
			copyvec(v, vp, 10);
            res = BubbleSortFull(vp, 10);
            cout << res << "\t bubble";
            //show(v, 10);
            cout << "\n";
        
			copyvec(v, vp, 10);
            res = SelectionSortFull(vp, 10);
			cout << res << "\t selection";
            //show(v, 10);
            cout << "\n";
            
            copyvec(v, vp, 10);
            res = InsertionSortFull(vp, 10);
            cout << res << "\t insertion";
            //show(v, 10);
            cout << "\n\n";
            
            /*if (res > max) {
                max = res;
                copyvec(v, vmax, 10);
            }
            if (res < min) {
                min = res;
                copyvec(v, vmin, 10);
            }*/
            
            swap(v, indx1, indx2);
        }
    }
		
    /*cout << "\n\nMinimo: " << min << endl;
    show(vmin, 10);
    cout << "\nMaximo: " << max << endl;
    show(vmax, 10);*/

    return 0;
}

