#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Localiza��o
#include <conio.h>
#include <string.h> //Necess�rio para strlen

void carregaVetorUm();
void mostrarNumero();
void inverteNumeros();
void carregarVetorTres();
void multiplicarVetores();
void ultimoDigito();

int numero[5];
int invertido[5];
int soma[6];
int result[4];

int numero1;
int numero2;
int soma1;
int resultado;

main(){
    setlocale(LC_ALL, "Portuguese"); //Instru��o usada para configurar o idioma Portugu�s.
    
    printf("Digite um n�mero de 5 D�gitos: ");
    scanf("%d", &numero1);
    
    carregaVetorUm();
    mostrarNumero();
    inverteNumeros();

	soma1 = numero1 + numero2;
	
    printf("A soma do n�mero com seu inverso � = %d\n", soma1);
    
	carregarVetorTres();
    multiplicarVetores();
	
	ultimoDigito();
	system("PAUSE");
}

void carregaVetorUm(){
	int resto = 0;
	int casa = 10000;
	resto = numero1;
	
	for(int t=0; t<5; t++)
	{
		numero[t] = resto/casa;
		resto = numero1 % casa;
		casa = casa/10;
	}    
}

void mostrarNumero(){
	printf("O N�mero digitado � : ");
	
	for(int t=0; t<5; t++){
		printf("%d", numero[t]);
	}
	printf("\n");
}

void inverteNumeros(){
	int casa = 10000;
	int resto = 0;
	
	printf("O Inverso do n�mero digitado �: ");
	
	for(int t=4; t>=0; t--){
		invertido[t] = numero[t];
		printf("%d", numero[t]);
		numero2 = numero2 + (casa * numero[t]);
		casa = casa /10;
	}
	printf("\n");
	
	casa = 10000;
	resto = numero2;
	for(int t=0; t<5; t++){
		invertido[t] = resto/casa;
		resto = numero2 % casa;
		casa = casa/10;
	}
	
}

void carregarVetorTres(){
	int resto = 0;
	int casa = 100000;
	resto = soma1;
	
	for(int t=0; t<6; t++){
		soma[t] = resto/casa;
		resto = soma1 % casa;
		casa = casa /10;
	}
}

void multiplicarVetores(){
	for(int t = 0; t<6; t++){
		resultado = resultado + (soma[t] * (t+1));
	}
	printf("A soma da multiplica��o por sua ordem posicional �: %d\n", resultado);
}

void ultimoDigito(){
	int resto = 0;
	int casa = 1000;
	resto = resultado;
	
	for(int t=0; t<4;t++){
		result[t] = resto/casa;
		resto = resultado % casa;
		casa= casa /10;
	}
	
	printf("O d�gito verificador da conta, neste caso � o: %d.\n\n", result[3]);
}

