#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Biblioteca necess�ria para usar o SETLOCALE()

void numero(int f1);

main(){
	setlocale(LC_ALL, "Portuguese"); //Instru��o usada para configurar o idioma Portugu�s.
	
	int num;
	
	printf("Digite um n�mero: ");
	scanf("%d", &num);
	
	numero(num);
	
	system("pause");
}
void numero(int f1){
	
	if (f1%2 == 0)
	{
		printf("O n�mero � divis�vel por 2.\n");
	}
	else
	{
		printf("O n�mero n�o � divis�vel por 2.\n");
	}
	
	return;
}
