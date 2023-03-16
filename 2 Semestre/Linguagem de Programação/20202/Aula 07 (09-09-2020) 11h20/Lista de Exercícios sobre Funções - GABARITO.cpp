#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 	// Biblioteca necess�rio para usar o SETLOCALE()
#include <stdbool.h>	// Biblioteca necess�ria para usar valores booleanos (true/false)

//EXERC�CIO 1
/*bool F_PosNeg (int f1);  //prot�tipo da fun��o

main()
{ 
      setlocale(LC_ALL, "Portuguese");      // Instru��o usada para configurar o idioma Portugu�s
      
      int A;
      
      printf ("Informe um n�mero: ");
      scanf ("%d", &A);
            
      if (F_PosNeg (A) == true)
             printf ("\nO valor %d � positivo!\n", A);
      else 
             printf ("\nO valor %d � negativo!\n", A);
}
bool F_PosNeg (int f1)
{
    bool S;
    if (f1 > 0)
        S = true;
    else
        S = false;
    
    return S;
}*/

//EXERC�CIO 2
/*void F_RecebeValores ();  					//prot�tipo da fun��o 
int F_Delta (int n1, int n2, int n3);

main()
{ 
    setlocale(LC_ALL, "Portuguese");      // Instru��o usada para configurar o idioma Portugu�s
      
    F_RecebeValores();
}
void F_RecebeValores ()
{
    int A, B, C, Delta;
    
    printf ("Informe um valor de A: ");
    scanf ("%d", &A);
    printf ("Informe um valor de B: ");
    scanf ("%d", &B);
    printf ("Informe um valor de C: ");
    scanf ("%d", &C);
    
    Delta = F_Delta (A, B, C);
    
    printf ("\nO valor de delta da equa��o �: %d\n", Delta);
}
int F_Delta (int n1, int n2, int n3)
{
    int Delta;
       
    Delta = (n2 * n2) - 4*n1*n3;
    
    return Delta;
}*/

//EXERC�CIO 3
/*int F_integerPower (int b, int e);  //prot�tipo da fun��o 

main()
{ 
    setlocale(LC_ALL, "Portuguese");      // Instru��o usada para configurar o idioma Portugu�s
      
    int base, exp, pot;
      
    printf ("Digite um valor para a base: ");
    scanf ("%d", &base);
    printf ("Informe um valor para o expoente: ");
    scanf ("%d", &exp);
      
    pot = F_integerPower (base, exp);
      
    printf ("\nO valor de %d elevado a %d � %d\n\n", base, exp, pot);
}
int F_integerPower (int b, int e)
{
    int i=1, pot=1;
    while (i <= e)
    {
        pot = b * pot;
        i++;
    }
    
    return pot;
}

//EXERC�CIO 4
float Peso (float alt, char sexo);  //prot�tipo da fun��o

main()
{ 
	setlocale(LC_ALL, "Portuguese");      // Instru��o usada para configurar o idioma Portugu�s
      
    float alt;
    char sexo;
      
    printf ("Informe a altura da pessoa: ");
    scanf ("%f", &alt);
    printf ("Informe o sexo: ");
    scanf ("%s", &sexo);
            
    printf ("\n\nO peso ideal da pessoa �: %.2f Kg\n\n", Peso (alt, sexo));
}
float Peso (float alt, char sexo)
{
    float peso;
    if (sexo == 'M' || sexo == 'm')
        peso = (72.7 * alt) - 58;
    else
        peso = (62.1 * alt) - 44.7;
        
    return peso;
}

//EXERC�CIO 5
bool F_ParImpar (int f1);  //prot�tipo da fun��o

main()
{ 
	setlocale(LC_ALL, "Portuguese");      // Instru��o usada para configurar o idioma Portugu�s
      
    int A;
      
    printf ("Informe um n�mero: ");
    scanf ("%d", &A);
            
    if (F_ParImpar (A) == true)
        printf ("\nO valor %d � par!\n", A);
    else 
        printf ("\nO valor %d � �mpar!\n", A);
}
bool F_ParImpar (int f1)
{
    bool S;
    if (f1%2 == 0)
        S = true;
    else
        S = false;
    
    return S;
}

//EXERC�CIO 6
int F_IdDias (int f1, int f2, int f3);  //prot�tipo da fun��o

main()
{ 
	setlocale(LC_ALL, "Portuguese");      // Instru��o usada para configurar o idioma Portugu�s
      
    int a, m, d, id_dias;
      
    printf ("Informe a idade em anos, meses e dias: ");
    scanf ("%d%d%d", &a, &m, &d);
            
    id_dias = F_IdDias (a, m, d);
      
    printf ("\nA idade da pessoa em dias �: %d dias\n", id_dias);
}
int F_IdDias (int f1, int f2, int f3)
{
    int id_dias;
    
    id_dias = f3 + (f2*30) + (f1*365);
    
    return id_dias;
}*/

//EXERC�CIO 7
/*float F_Valor_S (int n1);  //prot�tipo da fun��o 

main()
{ 
    setlocale(LC_ALL, "Portuguese");      // Instru��o usada para configurar o idioma Portugu�s
      
    int num;
    float S;
     
    printf ("Digite um n�mero: ");
    scanf ("%d", &num);
      
    S = F_Valor_S (num);
            
    printf ("\nO valor de S � = %.2f\n\n", S);
}
float F_Valor_S (int n1)
{
    float S;
    
    for (int i=1; i<= n1; i++)
          S = S + ((i*i)+1)/float((i+3));
        
    return S;
}*/

//EXERC�CIO 8
/*int F_Menu ();  							//prot�tipo da fun��o 
void F_Opc1 (float valor);
void F_Opc2 (float valor);
void F_Opc3 (float valor);

main()
{ 
	setlocale(LC_ALL, "Portuguese");      // Instru��o usada para configurar o idioma Portugu�s
      
    float valor;
    int opc;
      
    printf ("Digite o total gasto pelo cliente: ");
    scanf ("%f", &valor);
      
    opc = F_Menu ();
      
    switch (opc)
    {
        case 1:
            F_Opc1 (valor);
            break;
        case 2:
            F_Opc2 (valor);
            break;
        case 3:
            F_Opc3 (valor);
            break;
    }
}
int F_Menu ()
{
    int opc;
    
    printf ("\n ********* OP��ES DE PAGAMENTO *********\n");
    printf ("\nOp��o 1: a vista com 10%% de desconto\n");
    printf ("Op��o 2: em duas vezes (pre�o da etiqueta)\n");
    printf ("Op��o 3: de 3 at� 10 vezes com 3%% de juros ao m�s (somente para compras acima de R$ 100,00)\n");
    printf ("\n ***************************************\n");
    printf ("\n\nOp��o escolhida: ");
    scanf ("%d", &opc);
    
    return opc;
}
void F_Opc1 (float valor)
{
    printf ("\n\nO valor a pagar ser� de: %.2f\n", (valor * 0.9));
}
void F_Opc2 (float valor)
{
    printf ("\n\nO valor a pagar ser� 2 parcelas de: %.2f\n", (valor/2));
}
void F_Opc3 (float valor)
{
    int qt;
    
    if (valor > 100)
    {
        printf ("\nVoc� poder� pagar de 3 at� 10 vezes com 3%% de juros ao m�s!");
        printf ("\n\nEm quantas vezes voc� quer pagar?");
        scanf ("%d", &qt);
        
        printf ("\n\nO valor a pagar ser� %d parcelas de: %.2f\n\n\n", qt, ((valor*1.03)/qt));
    }
    else
        printf ("\nVoc� n�o pode escolher esta op��o de pagamento!");
}*/

//EXERC�CIO 9
/*#define tam 10

void F_Procura (int vet[], int max, int num);

main()
{
	int vetor[tam], x;
	
	for (int i=0; i<tam; i++)
	{
		printf ("Informe um numero para o vetor: ");
		scanf ("%d", &vetor[i]);
	}
	printf ("\nInforme um numero qualquer: ");
	scanf ("%d", &x);
	
	F_Procura (vetor, tam, x);
}
void F_Procura (int vet[], int max, int num)
{
	for (int i=0; i<max; i++)
	{
		if (num == vet[i])
			printf ("\nAchou na posicao %d!", i);
		else
			printf ("\nNao achou!!!");
	}
}*/

//EXERC�CIO 10
#define l 3
#define c 3

int F_SomaDiagP (int mnum[][c], int lin);
int F_ProdDiagS (int mnum[][c], int tam);

main()
{
	int num, mat[l][c], soma=0, prod=1;
	
	for (int i=0; i<l; i++)
	{
		for (int j=0; j<c; j++)
		{
			printf ("Informe um numero: ");
			scanf ("%d", &mat[i][j]);
		}
	}
	soma = F_SomaDiagP (mat,c);
	prod = F_ProdDiagS (mat,c);
	
	printf ("A soma da diagonal principal eh: %d", soma);
	printf ("\nO produto da diagonal secundaria eh: %d\n\n", prod);
}
int F_SomaDiagP (int mnum[][c], int tam)
{
	int s=0;
	
	for (int i=0; i<tam; i++)
	{
		for(int j=0; j<tam; j++)
		{
			if (i == j)
				s = s + mnum[i][j];
		}
	}
	return s;
}
int F_ProdDiagS (int mnum[][c], int tam)
{
	int p=1;
	for (int i=0; i<tam; i++)
	{
		for(int j=0; j<tam; j++)
		{
			if (i+j == 2)
				p = p * mnum[i][j];
		}
	}
	return p;
}






