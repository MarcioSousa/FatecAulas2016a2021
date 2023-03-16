#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main(){
	setlocale(LC_ALL,"Portuguese");
	
	float H, j;
	
	for (float i=1, j=1; i<=50 ;i++)
	{
		printf("\nO valor de j é: %f",j);
		printf("\nO valor de i é: %f\n",i);
		H = H + (j/i);
		j= j+2;
	}
	
	printf("\nA soma total é: %.2f\n", H);
	
	system("PAUSE");
}
