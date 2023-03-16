#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Biblioteca necessária para usar o SETLOCALE()

float peso(float alt, char sexo);

main(){
	setlocale(LC_ALL, "Portuguese"); //Instrução usada para configurar o idioma Português.
	
	float altur, pes;
	char sex;
	
	printf("Digite sua altura: ");
	scanf("%f", &altur);
	
	fflush(stdin);
	
	printf("Digite seu sexo: ");
	scanf("%c", & sex);
	
	pes = peso(altur, sex);
	
	printf("Seu peso ideal é: %.2f\n", pes);
	
	system("PAUSE");
}

float peso(float alt, char sexo){
	float peso = 0;

	if(sexo == 'M')
	{
		peso = 72.7 * alt - 58;
	}
	else
	{
		peso = 62.1 * alt - 44,7; 
	}
	return peso;
}
