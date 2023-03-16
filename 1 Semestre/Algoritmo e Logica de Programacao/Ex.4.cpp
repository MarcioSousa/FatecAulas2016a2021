#include <stdio.h>
#include <stdlib.h>

main(){
	char sexo;
	float altura, calculo;
	
	printf("\n==========Exercicio 4===========\n");
	printf("================================\n");
		
	printf("Digite o sexo da pessoa (m para masculino, f para Feminino): ");
	scanf("%c", &sexo);
		
	printf("Digite a altura da pessoa: ");
	scanf("%f", &altura);
		
	if(sexo == 'm'){
		calculo = (72.7*altura) - 58;
	}
	else{
		calculo = (62.1*altura) - 44.7;
	}
	printf("O peso ideal da pessoa: %.2f", calculo);	
}
    
	

