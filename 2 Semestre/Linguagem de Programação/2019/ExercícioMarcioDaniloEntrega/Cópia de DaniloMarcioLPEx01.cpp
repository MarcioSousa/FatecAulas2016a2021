#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main(){
	setlocale(LC_ALL, "Portuguese");
	
	printf("-------------------------------------\n");
	printf("|      TRABALHO DE LP ENTREGA       |\n");
	printf("|            2� SEMESTRE            |\n");
	printf("| ALUNOS:                           |\n");
	printf("|    DANILO RODRIGUES.              |\n");
	printf("|    MARCIO SOUSA.                  |\n");
	printf("-------------------------------------\n\n");
	
	
	
	int qtde = 0, idade = 0, somaidade = 0;
	float media = 0;
	
	do{
		printf("Digite uma idade: ");
		scanf("%i", &idade);
		
		if(idade != -1){
			qtde++;
			somaidade = somaidade + idade;
		}
		
	}while(idade != -1);
	
	media = somaidade / float(qtde);
	printf("A m�dia das idades �: %.2f\n", media);
	
	system("pause");
}

