//CRIE UM PROGRAMA QUE RECEBA UM N�MERO E VERIFIQUE SE ELE � PAR OU IMPAR
#include <stdio.h>
#include <stdlib.h>

main(){
	int numero;
	
	scanf("%f", &numero);
	
	if (numero%2==0)
	    printf("ESSE NUMERO E PAR");
	else
	    printf("ESSE NUMERO E IMPAR");
	    
	system("PAUSE");
}
