#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Escreva um programa que contenha duas vari�veis inteiras. Leia essas vari�veis do teclado. Em seguida, compare seus endere�os e exiba o conte�do do maior endere�o.

main()
{
int a, b, *pa, *pb;
scanf ("%d", &a);
scanf ("%d", &b);
pa = &a;
pb = &b;
if (pa > pb)
printf ("O endereco de a (%x) eh maior que o endereco de b (%x)", pa, pb);
else
printf ("O endereco de b (%x) eh maior que o endereco de a (%x)", pb, pa);
}
