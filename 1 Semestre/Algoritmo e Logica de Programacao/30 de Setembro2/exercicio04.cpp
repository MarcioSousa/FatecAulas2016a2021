#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main(){
	setlocale(LC_ALL,"Portuguese");
	
	int numero;
	
	printf("Digite um número: ");
	scanf("%d", &numero);
	
	switch(numero){
		case 1:
			printf("\nO mês digitado é Janeiro.");
			break;
		case 2:
	
			printf("\nO mês digitado é Fevereiro.");
			break;
		case 3:
			printf("\nO mês digitado é Março.");
			break;
		case 4:
			printf("\nO mês digitado é Abril.");	
			break;
		case 5:
			printf("\nO mês digitado é Maio.");
			break;
		case 6:
			printf("\nO mês digitado é Junho.");
			break;
		case 7:
			printf("\nO mês digitado é Julho.");
			break;
		case 8:
			printf("\nO mês digitado é Agosto.");
			break;
		case 9:
			printf("\nO mês digitado é Setembro.");
			break;
		case 10:
			printf("\n O mês digitado é Outubro.");
			break;
		case 11:
			printf("\n O mês digitado é Novembro.");
	     	break;
		case 12:
			printf("\nO mês digitado é Dezembro.");
			break;
		default:
			printf("\nO mês não existe.");	
	}
}
