//FA�A UM PROGRAMA QUE CALCULE O SAL�RIO FINAL DE UM FUNCION�RIO.
//VOC� DEVER� RECEBER O SAL�RIO FIXO, O VALOR DE SUAS VENDAS E O PERCENTUAL
//DE COMISS�O QUE RECEBER� SOBRE AS VENDAS.
//CALCULE:
//--QUAL O VALOR DE COMISS�O QUE O FUNCION�RIO RECEBE.
//--QUAL O SAL�RIO FINAL DO FUNCION�RIO (SAL�RIO FIXO + COMISS�O)

#include <stdio.h>
#include <stdlib.h>

main(){
	float salarioFinal, salarioFixo, valorVendas, percentualComissao, valorComissao;
	
	printf("Digite o Salario Fixo desse funcionario: ");
	scanf("%f", &salarioFixo);
	
	printf("Digite o valor de Vendas desse funcionario: ");
	scanf("%f", &valorVendas);
	
	printf("Digite o percentual de comiss�o do funcionario: ");
	scanf("%f", &percentualComissao);
	
	valorComissao = valorVendas * (percentualComissao/100);
	salarioFinal = salarioFixo + valorComissao;
	
	printf("O valor da comissao e de: %.2f \n", valorComissao);
	printf("O salario Final do funcionario � de: %.2f \n", salarioFinal);
	
	system("pause");
}
