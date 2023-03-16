#include <stdio.h>
#include <stdlib.h>
//#include <math.h>
//#include <string.h>

void quickSort(int *x, int inivec, int fimvec);

void printVetor(int *x, int tam);

int main() {
	
	int x[] = {100, 1, 40, 20, 33, 55, 201, 193, 440, 5, 4, 41, 92, 215, 177, 8, 18, 20, 11, 12};
	
	printVetor(x, 20);
	
	quickSort(x,0,19);
	
	printVetor(x, 20);
	
	return 0;
}

void printVetor(int *x, int tam){
	printf("%i", x[0]);
	for(int i = 1; i < tam; i++)
	{
		printf(", %i",x[i]);
	}
	//printf("\n");
}

void quickSort(int *x, int inivec, int fimvec){
	int i, j, pivo, aux;
	
	pivo = x[(inivec+fimvec)/2];
	i = inivec;
	j = fimvec;
	printf("\npivo: %i\n", pivo);
	
	while(i < j){
		while(x[i] < pivo){
			i = i + 1;
		}
		while(x[j] > pivo){
			j = j - 1;
		}
		if(i <= j){
			printf("troca: %i <-> %i\n", x[i], x[j]);
			
			aux = x[i];
			x[i] = x[j];
			x[j] = aux;
			i = i+1;
			j = j-1;
			printVetor(x, 20);//mostra vetor depois de trocar
		}
	}
	
	if(j > inivec){
		quickSort(x,inivec,j);
	}
	if(i < fimvec){
		quickSort(x,i,fimvec);
	}
}
