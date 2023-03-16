#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produto{
	int codigo;
	char nome[30];
	int qtde;
	float preco;
};

main(){
	int qtdep = 0;
	
	struct produto *p;
	
	printf("Informe a quantidade de produtos a serem cadastrados: ");
	scanf("%i", &qtdep);
	
	p = (struct produto *) malloc(qtdep * sizeof(struct produto));
	
	for(int t = 0; t < qtdep; t++){
		printf("Informe o código: ");
		scanf("%f", &p[t].codigo);
		getchar();
		printf("Informe o nome: ");
		gets(p[t].nome);
		printf("Informe a qtde: ");
		scanf("%i", &p[t].qtde);
		printf("Informe o preço: ");
		scanf("%f", &p[t].preco);
	}
	
	printf("teste");
	
}
