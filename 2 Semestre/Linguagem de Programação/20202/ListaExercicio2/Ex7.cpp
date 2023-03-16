#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Considere um cadastro de pessoas, com as seguintes informações para cada pessoa:
//• Nome da pessoa: representado por um valor de 30 caracteres
//• Sexo: representado por 1 caractere
//• Altura: representada por um valor real
//• Idade: representada por um número inteiro
//(a) Defina uma estrutura em C, denominada Pessoa, que tenha os campos apropriados para
//guardar as informações de uma pessoa
//(b) Crie dinamicamente um conjunto de n pessoas (n é um valor fornecido pelo usuário) e peça
//ao usuário para entrar com as informações de cada pessoa.
//(c) Encontre as pessoas que possuem idade superior a x anos (x é um número inteiro fornecido
//pelo usuário).
//(d) Encontre quantas pessoas do sexo feminino (sexo = F) e masculino (sexo=M) possuem altura
//superior a 1,50m.

typedef struct{
	char Nome[30];
	char Sexo;
	float Altura;
	int Idade;
} Pessoa;

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int qtde, filtroIdade, altsup = 0;
	
	printf("Digite a qtde de Pessoas que serão registrados: ");
	scanf("%i", &qtde);
	
	Pessoa *pessoa = (Pessoa *) malloc(qtde *sizeof(Pessoa));
	
	printf("Cadastro de Pessoas:\n");
	
	for(int t = 0; t < qtde; t++){
		fflush(stdin);
		printf("Digite o Nome da Pessoa: ");
		gets(pessoa[t].Nome);
		fflush(stdin);
		printf("Digite o 'm' pra masculino ou 'f' para feminino: ");
		scanf("%c", &pessoa[t].Sexo);
		fflush(stdin);
		printf("Digite a Altura: ");
		scanf("%f", &pessoa[t].Altura);
		fflush(stdin);
		printf("Digite a Idade: ");
		scanf("%i", &pessoa[t].Idade);
		fflush(stdin);
		printf("\n");
	}
	
	printf("Procurar por idade superior.\nDigite a idade para fazer a procura: ");
	scanf("%i", &filtroIdade);
	
	for(int t = 0; t < qtde; t++){
		if(pessoa[t].Idade > filtroIdade){
			printf("%s ", pessoa[t].Nome);
		}
	}
	
	printf("\nPessoas que possuem altura superior a 1,50m:\n");
	
	for(int t = 0; t < qtde; t++){
		if(pessoa[t].Altura > 1,5){
			if(pessoa[t].Sexo == 'f'){
				altsup++;
			}
		}
	}
	printf("%i pessoas do sexo feminino tem altura superior a 1,50.\n", altsup);
	
	altsup = 0;
	
	for(int t = 0; t < qtde; t++){
		if(pessoa[t].Altura > 1,5){
			if(pessoa[t].Sexo == 'm'){
				altsup++;
			}
		}
	}
	
	printf("\n%i pessoas do sexo masculino tem altura superior a 1,50.\n", altsup);
	
	free(pessoa);
	
	return 0;
	
}
