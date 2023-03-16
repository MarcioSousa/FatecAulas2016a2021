#include <stdio.h>
#include <stdlib.h>

main(){
	int quadrado, idade, exercicio, num1, num2, num3, numMaior, numMedio, numMenor,numExTres,anoNasc, anoAtual;
	float valorProduto,valorVenda, calculo;
	
	printf("Entre com o numero do exercicio: ");
	scanf("%d", &exercicio);
	
	if (exercicio == 1){
		printf("\n==========Exercicio 1===========\n");
		printf("================================\n");

        printf("Entre com o Valor do Produto: ");
        scanf("%f", &valorProduto);
    
        if (valorProduto > 20){
    	    valorVenda = valorProduto*1.45;
            printf("O valor e: %.2f", valorVenda);
	    }
        else{
    	    valorVenda = valorProduto*1.3;
            printf("O valor e: %.2f", valorVenda);
	    }
	}
	else if (exercicio == 2){
		printf("\n==========Exercicio 2===========\n");
		printf("================================\n");
		
		printf("Digite o primeiro numero inteiro: ");
		scanf("%d", &num1);
		
		printf("Digite o segundo numero inteiro: ");
		scanf("%d", &num2);
		
		printf("Digite o terceiro numero inteiro: ");
		scanf("%d", &num3);
		
		if (num1 > num2 && num1>num3){
			numMaior = num1;
			if (num2>num3){
				numMedio = num2;
				numMenor = num3;
			}
			else{
				numMedio = num3;
				numMenor = num2;
			}
		}
		else if (num2>num3 && num2> num1) {
			numMaior = num2;
			if (num1>num3){
				numMedio = num1;
				numMenor = num3;
			}
			else{
				numMedio = num3;
				numMenor = num1;
			}
		}
		else if (num3>num1 && num3>num2) {
			numMaior = num3;
			if (num1>num2){
				numMedio = num1;
				numMenor = num2;
			}
			else{
				numMedio = num2;
				numMenor = num1;
			}
		}
		
	printf("\n\n==================================");
	printf("\n\nApresentando os numeros em ordem Decrescente \n");
	printf("Maior: %d",numMaior);
	printf("\nMedio: %d", numMedio);	
	printf("\nMenor: %d", numMenor);


	printf("\n==========================");
	printf("\n===ALELUIA CONSEGUI=======");
	printf("\n==========================");	
	}
	else if (exercicio ==3){
		printf("\n==========Exercicio 3===========\n");
		printf("================================\n");
		
		printf("Entre com um valor em inteiro: ");
		scanf("%d", &numExTres);
		
		if (numExTres%2==0 && numExTres < 0){
			printf("\nO número %d e par e negativo! \n", numExTres);
		}
		else if(numExTres%2==0 && numExTres >=0){
			printf("O numero %d e par e positivo! \n", numExTres);
		}
		else if(numExTres < 0){
			printf("O numero %d e impar e negativo! \n", numExTres);
		}
		else{
			printf("O numero %d e impar e positivo! \n", numExTres);
		}
	}
	else if (exercicio == 4){
		printf("\n==========Exercicio 4===========\n");
		printf("================================\n");
		
		printf("Esse exercicio foi feito separadamente!!!");
	}
	else if (exercicio == 5){
		printf("\n==========Exercicio 5===========\n");
		printf("================================\n");
		
		printf("Digite o ano de Nascimento: ");
		scanf("%d", &anoNasc);
		
		printf("Digite o ano Atual: ");
		scanf("%d", &anoAtual);
		
		idade = anoAtual - anoNasc;
		
		printf("\nA pessoa tem %d anos \n");
		
		if (idade >= 18){
			printf("A pessoa ja pode tirar carteira de Habilitacao e Votar!");
		}
		else if(idade >= 16){
			printf("A pessoa ja pode votar, mas nao pode tirar carteira de habilitacao!");
		}
		else{
			printf("A pessoa nao pode votar e nao pode tirar carteira de habilitacao!");
		}
		
		//anoNasc,anoAtual,idade
	}
	else{
		printf("\n==========Exercicio 6===========\n");
		printf("================================\n");
		
		printf("Digite um número inteiro: ");
		scanf("%d", &num1);
		
		quadrado = num1*num1;
		
		printf("O quadrado do numero %d e: %d", num1, quadrado);
	}
	
    //system("PAUSE");
}

