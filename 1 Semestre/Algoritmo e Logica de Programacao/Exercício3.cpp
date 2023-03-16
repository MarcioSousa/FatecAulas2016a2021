//FAÇA UM PROGRAMA QUE CALCULE O SALÁRIO FINAL DE UM FUNCIONÁRIO.
//VOCÊ DEVERÁ RECEBER O SALÁRIO FIXO, O VALOR DE SUAS VENDAS E O PERCENTUAL
//DE COMISSÃO QUE RECEBERÁ SOBRE AS VENDAS.
//CALCULE:
//--QUAL O VALOR DE COMISSÃO QUE O FUNCIONÁRIO RECEBE.
//--QUAL O SALÁRIO FINAL DO FUNCIONÁRIO (SALÁRIO FIXO + COMISSÃO)

#include <stdio.h>
#include <stdlib.h>

main(){
	float salarioFinal, salarioFixo, valorVendas, percentualComissao, valorComissao;
	
	printf("Digite o Salario Fixo desse funcionario: ");
	scanf("%f", &salarioFixo);
	
	printf("Digite o valor de Vendas desse funcionario: ");
	scanf("%f", &valorVendas);
	
	printf("Digite o percentual de comissão do funcionario: ");
	scanf("%f", &percentualComissao);
	
	valorComissao = valorVendas * (percentualComissao/100);
	salarioFinal = salarioFixo + valorComissao;
	
	printf("O valor da comissao e de: %.2f \n", valorComissao);
	printf("O salario Final do funcionario é de: %.2f \n", salarioFinal);
	
	system("pause");
}
