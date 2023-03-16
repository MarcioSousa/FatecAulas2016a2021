//FAÇA UM PROGRAMA QUE CRIE UMA ESTRUTURA PESSOA COM OS MEMBROS:
// char nome [30]
// int idade
// char sexo
//
//CRIE UM VETOR COM OS DADOS DE 3 PESSOAS E DEPOIS:
//
//1 - CRIE UMA FUNÇÃO QUE RECEBA UM NOME QUALQUER E VERIFIQUE SE ESSE NOME EXISTE NO VETOR.
#include <stdio.h>
#include <stdio.h>
#include <string.h>

void F_VerificaNome();
void F_InsereDados();

//DEFININDO A ESTRUTURA PESSOAS
//E DECLARANDO UM VETOR DE TAMANHO 3
// DO TIPO PESSOA

struct Pessoa{
	char nome [30]; //Nome é um Vetor da estrutura pessoa.
	int idade;		//Idade é um Vetor da estrutura pessoa.
	char sexo;		//Sexo é um Vetor da estrutura pessoa.
} pessoas[3];

main(){	
	int opc;
	
	while(opc < 3){
		printf("\n****** MENU *******\n");
		printf("(1) Cadastrar Pessoas.\n");
		printf("(2) Buscar por Nome");
	
		printf("\n Digite uma opção: ");
		scanf("%d", &opc);
	
		if(opc == 1){
			F_InsereDados();
		}else if(opc == 2){
			F_VerificaNome();
		}
	}

	
}

void F_VerificaNome(){
	char nome1[30];
	
	printf("Digite o ano da pesquisa: ");
	gets(nome1);
	
	for(int t = 0; t < 3; t++){
		if(strcmp(nome1, pessoas[t].nome) == 0){ // IGUAIS
			printf("\nEsse nome existe");
		}else{
			printf("\nEsse nome não existe");
		}
	}
	
}

void F_InsereDados(){
	for(int t = 0; t < 3; t++){
		printf("Informe o nome: ");
		gets(pessoas[t].nome);
		fflush(stdin);
		printf("Informe a idade: ");
		scanf("%d", &pessoas[t].idade);
		fflush(stdin);
		printf("Informe o sexo: ");
		scanf("%c", &pessoas[t].sexo);
		fflush(stdin);
		
	}
	
}








