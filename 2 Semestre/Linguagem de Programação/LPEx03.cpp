#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void montandoPiramide(int, int);

main(){
	setlocale(LC_ALL, "Portuguese");
	
	int maximo = 0, primeiro = 1, numeroGrande = 1;
	
	printf("Digite um número impar menor que 69: ");
	scanf("%i", &maximo);
	
	for(int t = 0; t < maximo; t++){
		
		if(primeiro > 1){
			if(primeiro <= 10){
				for(int e = 0; e < (primeiro -1) * 2; e++){
					printf(" ");
				}
			}else{
				for(int e = 0; e < (primeiro - 1) * 2 + numeroGrande; e++){
					printf(" ");
				}
				numeroGrande++;
			}
			
		}
		
		montandoPiramide(primeiro, maximo);
			
		maximo--;
		primeiro++;
	
	}
	
	printf("\n\n");

	system("pause");
}

void montandoPiramide(int primeiro, int maximo){
	for(int t = primeiro; t <= maximo; t++){
		if(t != maximo){
			printf("%i ", primeiro);
			primeiro++;
		}else{
			printf("%i\n", primeiro);
		}
	}
}
