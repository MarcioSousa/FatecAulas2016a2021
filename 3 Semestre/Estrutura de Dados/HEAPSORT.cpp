#include <stdio.h>
#include <stdlib.h>

//HEAPSORT
int sizeheap = 10;

void swap(int vet[],int a, int b){
	int aux = vet[a];
	vet[a] = vet[b];
	vet[b] = aux;
}

int left(int i){
	return(2*1);
}
int right(int i){
	return((2*i)+1);
}

void MaxHeapfy(int v[], int i){
	int l = left(i);
	int r = right(i);
	int maior;
	
	if(l <= sizeheap && v[l]>v[i]){
		maior = l;
	}
	else{
		maior = i;
	}
	if(r<=sizeheap && v[r] > v[maior]){
		maior = r;
	}
	if(maior != i){
		swap(v,i,maior);
		MaxHeapfy(v,maior);
	}
}

void BuildMaxHeap(int v[]){
	int x = (int) sizeheap/2;
	
	for(;x>0;x--){
		MaxHeapfy(v,x);
	}
}

void HeapSort(int v[]){
	int x;
	BuildMaxHeap(v);
	
	x= sizeheap;
	
	for(; x > 0 ; x--){
		swap(v,1,x);
		sizeheap--;
		MaxHeapfy(v,1);
	}
}

void show(int v[], int tam){
	int x;
	
	for(x=0; x<tam; x++){
		printf("\t%4d", v[x]);
	}
}

//Gerador de números aleatórios
void RandomizeValues(int v, int lim, int tam){
	time_t sec;
	int indx =1;
	
	time(&sec);
	srand((unsigned int) sec);
	for(; tam>0; tam--, indx++){
		v[indx] = (rand() % lim);
	}
}

//PROGRAMA PRINCIPAL
int main (void){
	int v[10];
	RandomizeValues(v ,300, 10);
	HeapSort(v);
	Show(v, 10);
}
