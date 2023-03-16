#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 			// Biblioteca necess�rio para usar o SETLOCALE()

//VETOR - Exerc�cio 1
/*#define TAM 10

main()
{ 
    setlocale(LC_ALL, "Portuguese");      // Instru��o usada para configurar o idioma Portugu�s
      
    int vet[TAM];
      
    for (int i=0; i<TAM; i++)
    {
        printf ("Informe um n�mero: ");
        scanf ("%d", &vet[i]);
    }
    printf ("\n\n");
    for (int i=0; i<TAM; i++)
    {
        printf ("%d\t", vet[i]);
    }
      
    printf ("\n\nVetor em ordem inversa: \n");
    for (int i=TAM-1; i>=0; i--)
    {
       printf ("%d\t", vet[i]);
    }
}

//VETOR - Exerc�cio 2
#define TAM 10
main()
{ 
    setlocale(LC_ALL, "Portuguese");      // Instru��o usada para configurar o idioma Portugu�s
      
    float vet[TAM];
      
    for (int i=0; i<TAM; i++)
    {
        printf ("Informe uma nota: ");
        scanf ("%f", &vet[i]);
    }
    printf ("\n\nExibindo as 5 primeiras notas: ");
    for (int i=0; i<5; i++)
    {
        printf ("%.2f\t", vet[i]);
    }
    printf ("\n\nSoma da primeira com a �ltima nota: %.2f\n\n", (vet[0]+vet[TAM-1]));
}

//VETOR - Exerc�cio 3
#define TAM 5

main()
{ 
    setlocale(LC_ALL, "Portuguese");      // Instru��o usada para configurar o idioma Portugu�s
      
    int vet[TAM], aux;
      
    for (int i=0; i<TAM; i++)
    {
        printf ("Informe um n�mero: ");
        scanf ("%d", &vet[i]);
    }
    printf ("\n\n");
    	for (int i=0; i<TAM; i++)
    {
        printf ("%d\t", vet[i]);
    }
    //Ordena��o do vetor
    for (int i=0; i<TAM-1; i++)
    {
        for (int j=i+1; j<TAM;j++)
        {
            if (vet[i] > vet[j])
            {
                aux = vet [i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }   
    }
    printf ("\n\n");
    for (int i=0; i<TAM; i++)
    {
        printf ("%d\t", vet[i]);
    }
}*/

//MATRIZ - Exerc�cio 1
/*#define lin 5
#define col 3

main()
{
    int matriz [lin][col], i, j;
    for ( i=0; i<lin; i++ ) 
    {
	    for ( j=0; j<col; j++ )
        {
            printf ("Informe um numero: ");
            scanf ("%d", &matriz[ i ][ j ]);
        } 
    }
    for (i=0; i<lin; i++ ) 
    {
	    for ( j=0; j<col; j++ )
	    {
            printf ("%d\t", matriz[ i ][ j ]);
        }
        printf ("\n"); 
    }
}*/

//MATRIZ - Exerc�cio 2
#define lin 3
#define col 3

main()
{
    int matriz [lin][col], A, V[9], cont=0, i, j;
     
    for ( i=0; i<lin; i++ ) 
    {
	    for ( j=0; j<col; j++ )
        {
            printf ("Informe um numero: ");
            scanf ("%d", &matriz[ i ][ j ]);
        } 
    }
    printf ("\nInforme um valor: ");
    scanf ("%d", &A);
     
    for ( i=0; i<lin; i++ ) 
    {
		for ( j=0; j<col; j++ )
        {
            V[cont] = (A * matriz[i][j]);
            cont++;
        } 
    }
    printf ("\n\nOs numeros armazenados no vetor s�o: ");
    for ( i=0; i<9; i++ ) 
	    printf ("\t%d\t", V[i]);
}

//MATRIZ - Exerc�cio 3
#define lin 3
#define col 3

main()
{
    setlocale(LC_ALL, "Portuguese");      // Instru��o usada para configurar o idioma Portugu�s
    
	int matriz [lin][col], i, j, soma=0, prod=1;
    for ( i=0; i<lin; i++ ) 
    {
	    for ( j=0; j<col; j++ )
        {
            printf ("Informe um numero: ");
            scanf ("%d", &matriz[ i ][ j ]);
        } 
    }
    for ( i=0; i<lin; i++ ) 
    {
	    for ( j=0; j<col; j++ )
	    {
            printf ("%d\t", matriz[ i ][ j ]);
        }
        printf ("\n"); 
    }
    //Diagonal Principal
	for ( i=0; i<lin; i++ ) 
     {
	    for ( j=0; j<col; j++ )
	    {
            if (i == j)
                prod = prod * matriz[ i ][ j ];    
        }
        printf ("\n"); 
     }
     printf ("\nO produto da diagonal principal �: %d\n\n", prod);
    //Diagonal Secund�ria
	for ( i=0; i<lin; i++ ) 
    {
	    for ( j=0; j<col; j++ )
	    {
            if ((i+j) == 2)
                soma = soma + matriz[ i ][ j ];
        }
        printf ("\n"); 
    }
    printf ("\nA soma da diagonal secundaria �: %d\n\n", soma);
}


