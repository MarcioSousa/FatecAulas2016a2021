#include <stdio.h>
#include <stdlib.h>

main(){
	int *q, *v, *s;
	q = (int*) malloc(sizeof(int));
	printf("Informe o tamanho do vetor: ");
	scanf("%d", &(*q));
	
	v = (int*) malloc(sizeof(int));
	
	for(int i = 0; i < (*q); i++){
		printf("Informe um número: ");
		scanf("%i", &(v[i]);
	}
	
	s = (int*) malloc(sizeof(int));
	(*s) = 0;
	
	for(int t = 0; t <(*q); t++){
		if(v[t]%2 != 0){
			(*s) = (*s) + v[t];
		}
	}
	
	printf("A soma dos ímpares eh: %d", *s);
	free(q);
	free(s);
}

//FAÇA UM PROFRAMA QUE RECEBA DO USUÁRIO O TAMANHO DE UMA STRING E 
//CHAME UMA FUNÇÃO PARA ALOCAR DINAMICAMENTE ESSA STRING. EM SEGUIDA, 
//O USUÁRIO DEVERÁ INFORMAR O CONTEÚDO PARA A STRING E MOSTRAR A STRING SEM SUAS VOGAIS.
