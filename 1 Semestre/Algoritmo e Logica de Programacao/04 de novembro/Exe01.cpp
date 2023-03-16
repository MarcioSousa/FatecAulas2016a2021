#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Biblioteca necessária para usar o SETLOCALE()

void numero(int f1);

main(){
	setlocale(LC_ALL, "Portuguese"); //Instrução usada para configurar o idioma Português.
	
	int num;
	
	printf("Digite um número: ");
	scanf("%d", &num);
	
	numero(num);
	
	system("pause");
}
void numero(int f1){
	
	if (f1%2 == 0)
	{
		printf("O número é divisível por 2.\n");
	}
	else
	{
		printf("O número não é divisível por 2.\n");
	}
	
	return;
}
