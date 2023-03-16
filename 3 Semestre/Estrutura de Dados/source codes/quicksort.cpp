#include <stdio.h>
#include <stdlib.h>
//#include <math.h>
//#include <string.h>

void quickSort(int *x, int inivec, int fimvec);

int main() {
	
	int x[7] = {2,40,1,30,15,5,12}, i;
	
	quickSort(x,0,6);
	
	for(i = 0; i < 7; i++)
	{
		printf("%i	",x[i]);
	}
	
	return 0;
}

void quickSort(int *x, int inivec, int fimvec){
	int i, j, pivo, aux;
	
	i = inivec;
	j = fimvec;
	pivo = x[(inivec+fimvec)/2];
	
	while(i < j){
		while(x[i] < pivo){
			i = i + 1;
		}
		while(x[j] > pivo){
			j = j - 1;
		}
		if(i <= j){
			aux = x[i];
			x[i] = x[j];
			x[j] = aux;
			i = i+1;
			j = j-1;
		}
	}
	
	if(j > inivec){
		quickSort(x,inivec,j);
	}
	if(i < fimvec){
		quickSort(x,i,fimvec);
	}
}
