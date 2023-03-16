#include <stdio.h>
 
 int main(){
 	
 	int a,b;
	 	printf("Digite quantidade de container que deseja adicionar\n");
 			scanf("%i", &a);
	 	
 	// Adcionando container nas docas		
 	int vetor [200];
 		for (int t = 0; t < a; t++){
 			
 			printf("Digite o peso do container %i: ",t); 
 				scanf("%i", &vetor[t]);
 				vetor [t] = t++;
 				
 	if (vetor [t] >=1 && vetor [t]<=15){
			vetor [t] = t;			
			} else {
				printf("Peso inválido, digite entre 1 a 15 toneladas");
				t --;
				 }	
		 }
	// Teste
		for (int t = 0; t < a; t++){
			printf("Valor %i\n", vetor[t]);
		}
 
 	return 0;
 	
 	
 	
 }
 
 
 	
