#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main(){
	setlocale(LC_ALL,"Portuguese");
	
	int numero;
	
	printf("Digite um n�mero: ");
	scanf("%d", &numero);
	
	switch(numero){
		case 1:
			printf("\nO m�s digitado � Janeiro.");
			break;
		case 2:
	
			printf("\nO m�s digitado � Fevereiro.");
			break;
		case 3:
			printf("\nO m�s digitado � Mar�o.");
			break;
		case 4:
			printf("\nO m�s digitado � Abril.");	
			break;
		case 5:
			printf("\nO m�s digitado � Maio.");
			break;
		case 6:
			printf("\nO m�s digitado � Junho.");
			break;
		case 7:
			printf("\nO m�s digitado � Julho.");
			break;
		case 8:
			printf("\nO m�s digitado � Agosto.");
			break;
		case 9:
			printf("\nO m�s digitado � Setembro.");
			break;
		case 10:
			printf("\n O m�s digitado � Outubro.");
			break;
		case 11:
			printf("\n O m�s digitado � Novembro.");
	     	break;
		case 12:
			printf("\nO m�s digitado � Dezembro.");
			break;
		default:
			printf("\nO m�s n�o existe.");	
	}
}
