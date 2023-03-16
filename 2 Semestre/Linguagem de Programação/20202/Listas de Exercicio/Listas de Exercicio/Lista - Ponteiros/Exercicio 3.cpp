#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Elaborar um programa que leia dois valores inteiros (A e B). Em seguida faça uma função que retorne a soma do dobro dos dois números lidos.
//A função deverá a armazenar o dobro de A na própria variável A e o dobro de B na própria variável B.

void dobro (int *pa, int *pb);

main()
{
	int a,b;
	
	printf("Escreva o primeiro numero inteiro: ");
	scanf("%d",&a);
	printf("Escreva o primeiro numero inteiro: ");
	scanf("%d",&b);
	
	dobro (&a, &b);
	
	printf("\nO dobro de A eh %d e o dobro de B eh %d, a soma dos dois numeros eh %d.",a,b,(a+b));
	
}

void dobro (int *pa, int *pb)
{
	int aux;
	*pa = 2*(*pa);
	*pb = 2*(*pb);
}
