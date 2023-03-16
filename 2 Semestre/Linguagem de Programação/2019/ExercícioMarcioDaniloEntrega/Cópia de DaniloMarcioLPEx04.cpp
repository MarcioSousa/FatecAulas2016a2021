#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float CalculaSalarioBruto(int, int, float);
float CalculaSalarioLiquido(float, float);

main(){
	setlocale(LC_ALL, "Portuguese");
	
	printf("-------------------------------------\n");
	printf("|      TRABALHO DE LP ENTREGA       |\n");
	printf("|            2� SEMESTRE            |\n");
	printf("| ALUNOS:                           |\n");
	printf("|    DANILO RODRIGUES.              |\n");
	printf("|    MARCIO SOUSA.                  |\n");
	printf("-------------------------------------\n\n");
	
	//char tipo;
	int qtdeTvGrande = 0, qtdeTvComum = 0;
	float salarioFixo =0, salarioBruto = 0, salarioLiquido = 0;
	
	printf("Digite o Sal�rio Fixo do Funcion�rio: ");
	scanf("%f", &salarioFixo);
	
	printf("Digite a quantidade de tv Tela Grande Vendido: ");
	scanf("%i", &qtdeTvGrande);
	
	printf("Digite a quantidade de tv Comum Vendido: ");
	scanf("%i", &qtdeTvComum);
	
	salarioBruto = CalculaSalarioBruto(qtdeTvGrande, qtdeTvComum, salarioFixo);
	
	salarioLiquido = CalculaSalarioLiquido(salarioFixo, salarioBruto);
	
	printf("O valor do Sal�rio Bruto �: %.2f\n", salarioBruto);
	printf("O valor do Sal�rio L�quido �: %.2f\n", salarioLiquido);
	printf("-------------------------------------\n\n");
	
	system("pause");
}

float CalculaSalarioBruto(int qtdeTvGrande, int qtdeTvComum, float salarioFixo){
	//sal�rio bruto � o sal�rio registrado em carteira, o ganho total do trabalhador.
	float salarioBruto = 0, totalComissao = 0;
	
	//Calculando Comiss�o dos Televisores.
	if(qtdeTvGrande >= 10){
		totalComissao = 50 * float(qtdeTvGrande);
	}else{
		totalComissao = 5 * float(qtdeTvGrande);
	}
	
	if(qtdeTvComum >= 20){
		totalComissao = totalComissao + (20 * float(qtdeTvComum));
	}else{
		totalComissao = totalComissao + (2 * float(qtdeTvComum));
	}
	
	salarioBruto = totalComissao + salarioFixo;
	
	return salarioBruto;
}

float CalculaSalarioLiquido(float salarioFixo, float salarioBruto){
	//sal�rio l�quido � o valor que a pessoa recebe, realmente, a cada m�s, j� feitos os descontos que constam no holerite.
	float INSS = 0, salarioLiquido = 0, descontado = 0, IR = 0;
	
	INSS = salarioFixo * 0.08;
	salarioLiquido = salarioBruto - INSS;
	
	if(salarioLiquido >= 900){
		IR = salarioLiquido * 0.15;
		salarioLiquido = salarioLiquido - (salarioLiquido * 0.15);
	}
	
	printf("-------------------------------------\n");
	printf("=== INSS: %.2f\n", INSS);
	printf("=== IR:   %.2f\n", IR);
	printf("-------------------------------------\n");
	
	return salarioLiquido;
}

