#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main(){
	setlocale(LC_ALL,"Portuguese");
	
	char busca[5][5];
	char texto[31];
	//int la = 0;
	//int ca = 0;
	int n = 0;
	
	printf("Digite uma palavra: ");
	scanf("%s", &texto);
	
	n = strlen(texto);
	printf("%i",n);
	
	return 0;
}	
	
	
	//for(int t =0; t < 5; t++){
	//	for(u = 0; u < 5; u++){
	//		if(cont == n){
	//			busca[t][u] = '\0';
	//		}
	//		cont ++;
	//	}
	//}
	

	
	//for(int t = 0; t < 5 ; t++){
	//	for(int u = 0; u < 5 ; u++){
	//		printf("%c ", busca[t][u]);
	//	}
	//	printf("\n");
	//}
	
		
	//do{
//		printf("\nTeste \n");
//	}while(u != strlen(texto) );
	
	//printf("Valor 0 = %c", busca[0][0]);
	//printf("Valor 0 = %c", busca[0][1]);	
	
	//printf("Digite uma frase: ");
	//scanf("%s\n", &letra);
	
	//printf("%s\n", letra);
	
	//do{
	//	printf("Teste");
	//} while(letra == '\0');
	
	//for(int t = 0; t != '\0'; t++){
	//	printf("%s", letra[t]);
	//}
	

