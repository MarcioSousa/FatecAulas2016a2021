#include <stdio.h>
#include <stdlib.h>

struct Data{
	int dia;
	char mes[10];
	int ano;
};

struct Venda{
	int qtdePecas;
	float preco;
	Data dataVenda;
};

int main(){
	Venda A = { 20, 100.0,{7, "Novembro", 2018}};
	
	printf("Qtde de pecas = %d\n", A.qtdePecas);
	printf("Valor da Venda = %.2f\n", A.preco);
	printf("Data de Venda = %d - %s - %d\n", A.dataVenda.dia, A.dataVenda.mes, A.dataVenda.ano);
	
	return 0;
}
