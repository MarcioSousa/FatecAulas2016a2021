#include <stdio.h>
#include <stdlib.h>

void zerarVetor();

int matriz[20][1012];

int main(){
	
	zerarVetor();
	
	
	
	//do{
	//}while(t < 6);
	
	return 0;
}

void zerarVetor(){
	for(int t=0; t<2; t++){
		for(int u=0; u<1012; u++){
			vetor[t][u] = 0;
		}
	}
}

//M�XIMO 1012 CADA QUANTIDADE
//1� Filial: 1� qtde: 1
//1� Filial: 2� qtde: 2
//1� Filial: 3� qtde: 40
//1� Filial: 4� qtde: 20
//1� Filial: 5� qtde: -1

//2� Filial: 1� qtde: 2
//2� Filial: 1� qtde: -1

//3� Filial: 1� qtde: -1

//4� Filial: 1� qtde: 20
//4� Filial: 1� qtde: 30
//4� Filial: 1� qtde: -1

//5� Filial: 1� qtde: -1

//6� Filial: 1� qtde: 5
//6� Filial: 1� qtde: -1
