#include <stdio.h>
#include <stdlib.h>

main(){
	int *q, *v, *s;
	q = (int*) malloc(sizeof(int));
	printf("Informe o tamanho do vetor: ");
	scanf("%d", &(*q));
	
	v = (int*) malloc(sizeof(int));
	
	for(int i = 0; i < (*q); i++){
		printf("Informe um n�mero: ");
		scanf("%i", &(v[i]);
	}
	
	s = (int*) malloc(sizeof(int));
	(*s) = 0;
	
	for(int t = 0; t <(*q); t++){
		if(v[t]%2 != 0){
			(*s) = (*s) + v[t];
		}
	}
	
	printf("A soma dos �mpares eh: %d", *s);
	free(q);
	free(s);
}

//FA�A UM PROFRAMA QUE RECEBA DO USU�RIO O TAMANHO DE UMA STRING E 
//CHAME UMA FUN��O PARA ALOCAR DINAMICAMENTE ESSA STRING. EM SEGUIDA, 
//O USU�RIO DEVER� INFORMAR O CONTE�DO PARA A STRING E MOSTRAR A STRING SEM SUAS VOGAIS.
