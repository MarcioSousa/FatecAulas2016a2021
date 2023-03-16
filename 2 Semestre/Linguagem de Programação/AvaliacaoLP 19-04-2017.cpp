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

//MÁXIMO 1012 CADA QUANTIDADE
//1ª Filial: 1ª qtde: 1
//1ª Filial: 2ª qtde: 2
//1ª Filial: 3ª qtde: 40
//1ª Filial: 4ª qtde: 20
//1ª Filial: 5ª qtde: -1

//2ª Filial: 1ª qtde: 2
//2ª Filial: 1ª qtde: -1

//3ª Filial: 1ª qtde: -1

//4ª Filial: 1ª qtde: 20
//4ª Filial: 1ª qtde: 30
//4ª Filial: 1ª qtde: -1

//5ª Filial: 1ª qtde: -1

//6ª Filial: 1ª qtde: 5
//6ª Filial: 1ª qtde: -1
