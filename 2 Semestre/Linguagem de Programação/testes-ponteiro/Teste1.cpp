#include <stdio.h>
 
int main(void)
{
	int *p=NULL, *p2;
	int numero =10;
	p  = &numero;
	p2 = &numero; 
	
	numero = 10;
	*p = 11;
	
	printf("\nValor de numero = %i", numero);
	numero = 15;
	
	*p = *p + 1;
	printf("\nValor de numero = %i", *p);
	printf("\nValor de numero = %i", numero);
	
	
	
	printf("\nValor de numero = %i", numero);
	printf("\nEndereco de numero %i", &numero);
	
	printf("\nValor do endereco de p =  %i", *p);
	printf("\nEndereco que p guarda   = %i", p);
	
	
	printf("\nChar: %d bytes\n", sizeof(char));
    printf("Int: %d bytes\n", sizeof(int));
    printf("Float: %d bytes\n", sizeof(float));
    printf("Double: %d bytes\n", sizeof(double));
    
    
    int  v[10];
    printf("int [10] : %d bytes\n", sizeof(v));
    
    char nome[]={"FATEC"};
    printf("String : %d bytes\n", sizeof(nome));
    	
	char *str;
    //str = &nome[0]
    str = &nome; //pode ser assim tambem str = &nome[0];
    int i;
    
    for(i=0; i < 100; i++)
    	printf("\n%c", *str++);
    	
}
