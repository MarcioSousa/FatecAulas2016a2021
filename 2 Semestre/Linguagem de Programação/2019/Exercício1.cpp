#include <stdio.h>
#include <stdlib.h>

//Exercício 01
struct Aluno{
	char nome[50];
	int nmat;
	char curso[20];
};

main(){
	Aluno Pessoa[5];
	
	for(int i = 0; i < 5; i++){
		printf("Informe o nome: ");
		gets(Pessoa[i].nome);
	
		printf("Informe o num. matrícula: ");
		scanf("%d", &Pessoa[i].nmat);
		
		fflush(stdin);
			
		printf("Informe o curso: ");
		gets(Pessoa[i].curso);
	}
	
	for(int i = 0; i < 5; i++){
		printf("Nome - %s, Num. Mat - %d, curso - %s\n", Pessoa[i].nome, Pessoa[i].nmat, Pessoa[i].curso);
	}
}
