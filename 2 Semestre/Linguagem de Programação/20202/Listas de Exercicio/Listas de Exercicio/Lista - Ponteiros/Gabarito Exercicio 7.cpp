#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void Maior_vetor (int *pV, int n, int *pnum, int *pqtde);
main()

{
int V[] = {5, 2, 15, 3, 7, 15, 8, 6, 15};
int num=0, qtde=0;
Maior_vetor (V, 9, &num, &qtde);
printf ("\nO maior numero do vetor eh o %i e esse numero aparece %i vezes no vetor!", num, qtde);
}
void Maior_vetor (int *pV, int n, int *pnum, int *pqtde)
{
int i, j;
for (i=0; i<n; i++, pV++ )
{
if (*pV > *pnum)
*pnum = *pV;
}
pV--;
for (i=n; i>0; i--, pV-- )
{
if (*pV == *pnum)
(*pqtde)++;
}
}
