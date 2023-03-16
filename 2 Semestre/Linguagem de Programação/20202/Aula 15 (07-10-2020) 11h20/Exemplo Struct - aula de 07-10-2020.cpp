//FAÇA UM PROGRAMA QUE CRIE UMA ESTRUTURA PESSOA COM OS MEMBROS: 
// char	nome[30]
// int	idade
// char	sexo
//
//CRIE UM VETOR COM OS DADOS DE 3 PESSOAS E DEPOIS:
//
//1 - CRIE UMA FUNÇÃO QUE RECEBA UM NOME QUALQUER E VERIFIQUE SE ESSE NOME EXISTE NO VETOR

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//DEFININDO A ESTRUTURA PESSOA E DECLARANDO UM VETOR DE TAMANHO 3 DO TIPO PESSOA
struct Pessoa
{
	char	nome[30];
	int 	idade;
	char 	sexo;
} vet[3];

//PROTÓTIPO DA FUNÇÃO
void F_InsereDados();
void F_VerificaNome ();
void F_OrdemAlf();

main()
{
	int opc=0;
	
	while (opc < 4)
	{
		printf ("\n*********** MENU **************");
		printf ("\n(1) Cadastrar Pessoas");
		printf ("\n(2) Buscar por Nome");
		printf ("\n(3) Colocar em Ordem Alfabetica");
		
		printf ("\nDigite uma opcao: ");
		scanf ("%d", &opc);
		fflush stdin;
		
		if (opc == 1)
			F_InsereDados();
		if (opc == 2)
			F_VerificaNome();	
		if (opc == 3)
			F_OrdemAlf();
	}
}

void F_InsereDados()
{
	int i;
	
	//INSERINDO DADOS DE 3 PESSOAS NO VETOR VET
	printf ("\n");
	for (i=0; i<3; i++)
	{
		printf ("Informe o nome: ");
		gets (vet[i].nome);
		fflush stdin;
		printf ("Informe a idade: ");
		scanf ("%d", &vet[i].idade);
		fflush stdin;
		printf ("Informe o sexo: ");
		scanf ("%c", &vet[i].sexo);
		fflush stdin;		
	}
}

void F_VerificaNome ()
{
	char nome1[30];
	int i;
	
	printf ("Informe um nome qualquer: ");
	gets (nome1);
	
	for (i=0; i<3; i++)
	{
		if (strcmp(nome1, vet[i].nome)==0) 	//SÃO IGUAIS
			printf ("\nESSE NOME EXISTE!");
		else
			printf ("\nESSE NOME NAO EXISTE!");
	}	
}

void F_OrdemAlf()
{
	struct Pessoa aux;

    for (int i = 0; i < 2; i++)
    {
        for (int j = i+1; j < 3; j++)
        {
            if (strcmp(vet[i].nome,vet[j].nome) > 0)		
            {
               aux = vet[i];
               vet[i] = vet[j];
               vet[j] = aux;
            }                                
        }
    }
    printf ("\n");
	for (int i=0; i < 3; i++)
    { 
             printf("%s \t %d \t %c \t", vet[i].nome, vet[i].idade, vet[i].sexo);
    }


}
