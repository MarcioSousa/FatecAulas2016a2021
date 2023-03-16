#include <stdio.h>
#include <stdlib.h>

struct Aluno{
	int nmat;
	float nota[3];
	float media;
};

int main(){
	float soma;
	Aluno classe[10];
	
	for(int i = 0; i < 10; i++){
		printf("Informe o ra: ");
		scanf("%d", &classe[i].nmat);
		for(int j = 0; j < 3; j++){
			printf("Informe a nota: ");
			scanf("%f", &classe[i].nota[j]);
		}
	}
	for(int i = 0; i < 3; i++){
		soma = 0;
		for(int j = 0; j < 3; j++){
			soma = soma + classe[i].nota[j];
			classe[i].media = soma/3;
			printf("A media do aluno e: %f\n", classe[i].media);
		}
	}
	
	
	return 0;
}
