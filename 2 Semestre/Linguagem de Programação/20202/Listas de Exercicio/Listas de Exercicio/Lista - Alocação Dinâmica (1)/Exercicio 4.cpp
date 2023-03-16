#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
Considere um cadastro de pessoas, com as seguintes informa��es para cada pessoa:
� Nome da pessoa: representado por um valor de 30 caracteres
� Sexo: representado por 1 caractere
� Altura: representada por um valor real
� Idade: representada por um n�mero inteiro

(a) Defina uma estrutura em C, denominada Pessoa, que tenha os campos apropriados para guardar as informa��es de uma pessoa
(b) Crie dinamicamente um conjunto de n pessoas (n � um valor fornecido pelo usu�rio) e pe�a ao usu�rio para entrar com as informa��es de cada pessoa.
(c) Encontre as pessoas que possuem idade superior a x anos (x � um n�mero inteiro fornecido pelo usu�rio).
(d) Encontre quantas pessoas do sexo feminino (sexo = F) e masculino (sexo=M) possuem altura superior a 1,50m.
*/

main()
{
	struct s_pessoa {
		char nome[30];
		char sexo;
		float altura;
		int idade;
	};
	
	int n,x,i,qi;
	int qm = 0;
	int qf = 0;
	struct s_pessoa *p;
	
	printf("Informe quantas pessoas deseja cadastrar: ");
	scanf("%d",&n);
	
	p = (struct s_pessoa *) malloc(n*sizeof(struct s_pessoa));
	
	if (p == NULL)
	{
		printf("N�o foi poss�vel alocar a mem�ria!");
		exit(1);
	}
	
	for (i=0;i<n;i++)
	{
		fflush(stdin);
		printf("Informe o nome da %da pessoa: ",i+1);
		gets(p[i].nome);
		fflush(stdin);
		printf("Informe o sexo da %da pessoa: ",i+1);
		scanf("%c",&p[i].sexo);
		fflush(stdin);
		printf("Informe a altura da %da pessoa: ",i+1);
		scanf("%f",&p[i].altura);
		fflush(stdin);
		printf("Informe a idade da %da pessoa: ",i+1);
		scanf("%d",&p[i].idade);
		fflush(stdin);
	}
	
	printf("\nPessoas cadastradas:\n");
	for(i=0;i<n;i++)
	{
		printf("\n===== Pessoa %d =====",i+1);
		printf("\nNome: %s",p[i].nome);
		printf("\nSexo: %c",p[i].sexo);
		printf("\nAltura: %.2f",p[i].altura);
		printf("\nIdade: %d",p[i].idade);
		printf("\n====================");
	}
	
	printf("\n\nInforme a idade que deseja verificar: ");
	scanf("%d",&x);
	
	for(i=0;i<n;i++)
	{
		if(p[i].idade > x)
		{
			printf("\n%s possui idade superior a %d (possui %d anos).",p[i].nome,x,p[i].idade);
		}
		
		if(p[i].altura > 1.5 && (p[i].sexo == 'M' || p[i].sexo == 'm'))
		{
			qm++;
		}
		
		if(p[i].altura > 1.5 && (p[i].sexo == 'F' || p[i].sexo == 'f'))
		{
			qf++;
		}
	}
	
		printf("\n\n%d pessoa(s) do sexo masculino possuem altura superior a 1.5m.",qm);
		printf("\n%d pessoa(s) do sexo feminino possuem altura superior a 1.5m.",qf);
	
	free(p);
}
