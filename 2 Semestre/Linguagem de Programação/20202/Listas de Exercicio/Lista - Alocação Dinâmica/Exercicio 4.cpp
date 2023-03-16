#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
Considere um cadastro de pessoas, com as seguintes informações para cada pessoa:
• Nome da pessoa: representado por um valor de 30 caracteres
• Sexo: representado por 1 caractere
• Altura: representada por um valor real
• Idade: representada por um número inteiro

(a) Defina uma estrutura em C, denominada Pessoa, que tenha os campos apropriados para guardar as informações de uma pessoa
(b) Crie dinamicamente um conjunto de n pessoas (n é um valor fornecido pelo usuário) e peça ao usuário para entrar com as informações de cada pessoa.
(c) Encontre as pessoas que possuem idade superior a x anos (x é um número inteiro fornecido pelo usuário).
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
		printf("Não foi possível alocar a memória!");
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
