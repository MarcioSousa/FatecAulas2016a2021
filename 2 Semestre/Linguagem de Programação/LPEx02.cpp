#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main(){
	setlocale(LC_ALL, "Portuguese");
	
	int idade = 0, qtdeA = 0, qtdeidades = 0, somaIdade = 0, olhosAzuis = 0, qtdeD = 0;
	float peso = 0, altura = 0, mediaB = 0, porcC = 0;
	char corOlhos, corCabelo;
	
	
	
	printf("===== Digite os dados de 20 pessoas =====\n");
	for(int t = 0; t < 20; t++){
		printf("-----------------------------------------\n");
		printf("%iª pessoa:\n", t + 1);
		
		printf("Idade: ");
		scanf("%i", &idade);
			
		printf("Peso: ");
		scanf("%f", &peso);
		fflush(stdin);
		
		printf("Altura: ");
		scanf("%f", &altura);
		fflush(stdin);
		
		printf("Cor dos Olhos (A = Azul, P = Preto, V = Verde, C = Castanho): "); 
		scanf("%c", &corOlhos);
		fflush(stdin);
		
		printf("Cor dos Cabelos (P = Preto, C = Castanho, L = Loiro, R = Ruivo): "); 
		scanf("%c", &corCabelo);
		
		//Quantidade de pessoas com idade superior a 50 anos e peso inferior a 60 quilos.
		if(idade > 50){
			if(peso < 60){
				qtdeA++;
			}
		}
		
		//Média das idades das pessoas com altura inferior a 1,50
		if(altura < 1.50){
			qtdeidades++;
			somaIdade = somaIdade + idade;
		}
		
		//Percentagem de pessoas com olhos azuis entre todas as pessoas analisadas
		if(corOlhos == 'A'){
			olhosAzuis++;
		}
		
		//quantidade de pessoas ruivas e que não possuem olhos azuis
		if(corCabelo == 'R'){
			if(corOlhos != 'A'){
				qtdeD++;
			}
		}
	}
	//Calculando média das idades.
	if(qtdeidades != 0){
		mediaB = somaIdade/float(qtdeidades);
	}
	
	//Calculando a porcentagem de olhos azuis sabendo que serão 20 pessoas cadastradas
	if(olhosAzuis != 0){
		porcC = float(olhosAzuis)/20;
	}
	
	printf("\n========== RESULTADO ===========\n");
	printf("Quantidade de pessoas com idade superior a 50 anos e peso inferior a 60 quilos: %i\n", qtdeA);
	printf("Média das idades das pessoas com altura inferior a 1,50: %.2f\n", mediaB);
	printf("Percentagem de pessoas com olhos azuis entre todas as pessoas analisadas: %.2f\n", porcC);
	printf("Quantidade de pessoas ruivas e que não possuem olhos azuis: %i\n\n", qtdeD);
	
	system("pause");
}
