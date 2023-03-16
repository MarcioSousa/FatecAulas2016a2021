//***** EXERCÍCIOS FEITOS EM AULA - MATERIAL SOBRE ALOCAÇÃO DINÂMICA *****
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

//EXERCÍCIO 1
/*main()
{
	char *ps;
	float *ph, *pp;
	
	ps = (char *) malloc (sizeof(char));
	if (ps == NULL) 		
	{ 
		printf("Não conseguiu alocar a memória\n"); 
		exit(1); 
	} 
	ph = (float *) malloc (sizeof(float));
	if (ph == NULL) 		
	{ 
		printf("Não conseguiu alocar a memória\n"); 
		exit(1); 
	}
	
	printf ("Informe o sexo: ");
	scanf ("%c", &(*ps));
	printf ("Informe a altura: ");
	scanf ("%f", &(*ph));
	
	pp = (float *) malloc (sizeof(float));
	if (pp == NULL) 		
	{ 
		printf("Não conseguiu alocar a memória\n"); 
		exit(1); 
	}
	if (*ps == 'F')
		*pp = (62.1 * (*ph)) - 44.7;
	else
		*pp = (72.7 * (*ph)) - 58;
		
		
	printf ("O peso ideal da pessoa de sexo %c e altura %.2f eh %.2f", *ps, *ph, *pp);
	
	free (ps);
	free (ph);
	free (pp);
}*/

//EXERCÍCIO 2
/*main()
{
    int i, *num_componentes, *v, *soma;     
    
	num_componentes = (int *) malloc(sizeof(int));
	 
    printf("Informe o numero de componentes do vetor:\n");
    scanf("%d", &(*num_componentes));

	v = (int *) malloc((*num_componentes) * sizeof(int));
    for (i = 0; i < *num_componentes; i++)
    {
      printf("\nDigite o valor para a posicao %d do vetor: ", i+1);
      scanf("%d",&v[i]); 					}   
    
	for (i = 0; i < *num_componentes; i++)
    {
      printf("%d\t", v[i]);					}
		 
    soma = (int *) malloc(sizeof(int));
    *soma = 0;
   	for (i = 0;i < *num_componentes; i++)
   	{
       if (v[i]%2 != 0)	
	   	*soma = *soma + v[i];	 				
	}       
    printf ("\nA soma dos numeros impares do vetor eh: %d", *soma);
    
    free(num_componentes);
	free(v);
	free(soma);
}*/


//EXERCÍCIO 3
/*main()
{
	int *n, i;
	char *pstr1;
	
	n = (int *) malloc (sizeof(int));
	
	printf ("Informe o tamanho da string: ");
	scanf ("%d", &(*n));
	
	getchar();
		
	pstr1 = (char *) malloc ((*n+1)*sizeof(char));
		
	printf ("Informe a string: ");
	gets (pstr1);
	
	printf ("\n\nString impressa sem as vogais: ");
	for (i=0; i<strlen(pstr1); i++)
	{
		if (pstr1[i] != 'A' && pstr1[i] != 'E' && pstr1[i] != 'I'&& pstr1[i] != 'O'&& pstr1[i] != 'U')
			printf ("%c", pstr1[i]);
	}
	
	free (n);
	free (pstr1);
}*/

//EXERCÍCIO 4
/*main()
{
	int *n, i;
	char *pstr1;
	
	n = (int *) malloc (sizeof(int));
	
	printf ("Informe o tamanho da string: ");
	scanf ("%d", &(*n));
	
	getchar();
		
	pstr1 = (char *) malloc ((*n+1)*sizeof(char));
		
	printf ("Informe a string: ");
	gets (pstr1);
	
	printf ("\n\nString impressa na ordem inversa: ");
	for (i=strlen(pstr1)-1; i>=0; i--)
	{
		printf ("%c", pstr1[i]);
	}
	
	free (n);
	free (pstr1);
}*/

//EXERCÍCIO 5
/*main()
{
	int *n;
	char *pstr1, *pstr2;
	
	n = (int *) malloc (sizeof(int));
	
	printf ("Informe o tamanho da string1: ");
	scanf ("%d", &(*n));
	
	getchar();
		
	pstr1 = (char *) malloc ((*n+1)*sizeof(char));
	
	printf ("Informe a string1: ");
	gets (pstr1);
	
	pstr2 = (char *) malloc (((strlen(pstr1)/2)+1)*sizeof(char));
	
	strncpy (pstr2, pstr1, strlen(pstr1)/2);
	
	printf ("\nString1: %s\tString2: %s", pstr1, pstr2);
	
	free (n);
	free (pstr1);
	free (pstr2);
}*/

//EXERCÍCIO 7
void Cadastra (struct produto *p, int x);
void Mostrar (struct produto *p, int x);
void MaiorPreco (struct produto *p, int x);
void MaiorQtde (struct produto *p, int x);

struct produto
{
	int			cod;
	char		nome[50];
	int			qtde;
	float		preco;
};
struct produto *dados;

main()
{
	int *n;
	
	n = (int *) malloc(sizeof(int));
	printf ("\nInforme quantos produtos deseja cadastrar: ");
	scanf ("%d", &(*n));
	
	dados = (struct produto *) malloc ((*n)*sizeof (struct produto));
	
	Cadastra (dados, *n);
	Mostrar (dados, *n);
	MaiorPreco (dados, *n);
	MaiorQtde (dados, *n);
	
	free (dados);
	free (n);
}

void Cadastra (struct produto *p, int x)
{
	int i;
	
	for (i=0; i<x; i++)
	{
		printf ("\nInforme o codigo do produto: ");
		scanf ("%d", &p[i].cod);
		fflush(stdin);
		printf ("\nInforme o nome do produto: ");
		gets(p[i].nome);
		fflush(stdin);
		printf ("\nInforme a quantidade do produto: ");
		scanf ("%d", &p[i].qtde);
		fflush(stdin);
		printf ("\nInforme o preco do produto: ");
		scanf ("%f", &p[i].preco);
		fflush(stdin);
	}	
}
void Mostrar (struct produto *p, int x)
{
	int i;
	printf ("\n");
	for (i=0; i<x; i++)
	{
		printf ("%d\t%s\t\t%d\t%.2f\n", p[i].cod, p[i].nome, p[i].qtde, p[i].preco);
	}
}
void MaiorPreco (struct produto *p, int x)
{
	int i, prod;
	float maior = 0;
	
	for (i=0; i<x; i++)
	{
		if (p[i].preco > maior)
		{
			maior = p[i].preco;
			prod = i;
		}
	}
	printf ("\n\nO produto de maior preco eh %s - %f",p[prod].nome, maior);
}
void MaiorQtde (struct produto *p, int x)
{
	int i, qtde, maior = 0;
	
	for (i=0; i<x; i++)
	{
		if (p[i].qtde > maior)
		{
			maior = p[i].qtde;
			qtde = i;
		}
	}
	printf ("\n\nO produto de maior quantidade eh %s - %d",p[qtde].nome, maior);
}

//EXERCÍCIO 8
/*main() {
	 int qtdIni, qtdNumeros, i, soma;
	 float * p, *pR, media;
	 char resposta;
	 
	 printf ("Informe a quantidade de alunos na turma: ");
	 scanf ("%d",&qtdIni);
	 	 
	 p = (float*) malloc(qtdIni*sizeof(float));

	 printf("Informe as notas dos %d numeros: ", qtdIni);
	 for (i=0; i<qtdIni; i++)
	 {
	 	scanf ("%f", &p[i]);
	 }
	 fflush(stdin);
	 printf("Deseja adicionar mais alunos? (s/n)\n");
	 scanf("%c",&resposta);
	 fflush(stdin);
	 if (resposta == 's') {
	 	printf("Nova quantidade de alunos?:\n");
	 	scanf("%d", &qtdNumeros);
	 	fflush(stdin);
	 	pR = (float*) realloc(p,qtdNumeros*sizeof(float));
		if (pR != NULL) {
			p = pR;
		}
 	} 
 	printf("Informe as notas dos novos alunos:\n");
 	for (i=qtdIni; i<qtdNumeros; i++)
	{
	 	scanf ("%f", &p[i]);
	}
	for (i=0; i<qtdNumeros; i++)
	{
	 	soma = soma + p[i];
	}
	media = soma / (float)qtdNumeros;
	printf("\nA media de notas da turma eh: %.2f", media);
	free (p);
}*/
