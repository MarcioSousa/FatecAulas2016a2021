#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Escreva um programa que crie um pequeno cadastro de contas banc�rias 
//de um banco em um vetor com a seguinte estrutura:
//N�mero da conta : (integer) 
//Nome do titular: (string de 30 posi��es) 
//Valor do Saldo: (real) 
//Tipo da Conta: (char) //Aqui, C para conta corrente e P para conta poupan�a

//(a) Defina uma estrutura em C, denominada contas, que tenha os 
//campos apropriados para guardar as informa��es de uma conta. 

//(b) Na fun��o principal main(), solicite que o usu�rio 
//informe quantas contas deseja informar e chame uma fun��o 
//para criar dinamicamente um conjunto de n contas e pe�a 
//ao usu�rio para entrar com as informa��es de cada uma delas. 

//(c) Crie uma fun��o para mostrar os dados de todos 
//as contas cadastradas. 

//(d) Crie uma fun��o para mostrar qual(is) conta(s) tem o maior saldo.

typedef struct{
	int NumeroConta;
	char Nome[30];
	float Valor;
	char TipoConta;
} Conta;

void CriarContas(Conta *conta, int qtde);
void MostrarContas(Conta *conta, int qtde);
void MostrarMaiorSaldo(Conta *conta, int qtde);

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int qtdeContas;

	printf("Digite a quantidade de contas: ");
	scanf("%i", &qtdeContas);
	
	Conta *contas = (Conta *) malloc(qtdeContas *sizeof(Conta));
	
	CriarContas(contas, qtdeContas);
	printf("\n================\n");
	MostrarContas(contas, qtdeContas);
	printf("\n================\n");
	MostrarMaiorSaldo(contas, qtdeContas);
	
	free(contas);
	
}

void CriarContas(Conta *conta, int qtde){

	for(int t = 0; t < qtde; t++){		
		printf("N�mero da Conta: ");
		scanf("%i", &conta[t].NumeroConta);
		fflush(stdin);
		printf("Nome: ");
		gets(conta[t].Nome);
		fflush(stdin);
		printf("Valor: ");
		scanf("%f", &conta[t].Valor);
		fflush(stdin);
		printf("Tipo (c = corrente, p = poupanca): ");
		scanf("%c", &conta[t].TipoConta);
		fflush(stdin);
	}
	
}

void MostrarContas(Conta *conta, int qtde){
	printf("Contas cadastradas:\n");
	for(int t = 0; t < qtde; t++){
		printf("N�mero: %i, Nome: %s, Valor: %.2f, Tipo: %c\n", conta[t].NumeroConta, conta[t].Nome, conta[t].Valor, conta[t].TipoConta);
	}
}

void MostrarMaiorSaldo(Conta *conta, int qtde){
	int ms = 0;
	printf("Maior Saldo:\n");
	for(int t = 0; t < qtde; t++){
		if(conta[t].Valor > conta[ms].Valor){
			ms = t;
		}
	}
	printf("Sando com Maior Valor � do(a): %s\n", conta[ms].Nome);
}






