#include <stdio.h>
#include <stdlib.h>

//Exercício 1
/*main()
{
	float vrcompra, vrvenda;
      
    printf ("\nDigite o valor da compra: ");
    scanf ("%f",&vrcompra);
      
    if (vrcompra < 20)
        vrvenda = vrcompra + (vrcompra * 0.45);	
    else
        vrvenda = vrcompra + (vrcompra * 0.30);
      
    printf("\n\nO produto comprado por R$ %.2f foi vendido por R$ %.2f\n\n", vrcompra, vrvenda);
}

//Exercício 2
#define ano 2020

main()
{
	int anonasc, idade;
            
    printf ("\nDigite o ano de nascimento da pessoa: ");
    scanf ("%d",&anonasc);
      
    idade = ano - anonasc;
      
    printf("\nA idade da pessoa eh: %d\n", idade);
                  
    if (idade >= 16 && idade >= 18)
        printf("\n\nA pessoa ja tem idade para votar e conseguir Carteira de Habilitacao!!!\n\n");	
}

//Exercício 3
main()
{
	float peso, altura, imc;
      
    printf("Digite o peso: ");
    scanf ("%f", &peso);
    printf("Digite a altura: ");
    scanf ("%f", &altura);
      
    imc = peso/(altura*altura);
      
    printf("\nSeu IMC eh: %.2f\n", imc);
      
    if (imc <=  18.5)
        printf("\nVoce esta abaixo do peso normal!!!\n\n");
    else
    {
        if (imc > 18.5 && imc <= 25)
            printf("\nVoce esta com peso normal!!!\n\n");
        else
        {
            if (imc > 25 && imc <= 30)
                printf("\nVoce esta acima do peso normal!!!\n\n");
            else
                printf("\nVoce esta obeso!!!\n\n");
        }
    }
}*/

//Exercício 4
main()
{
	float num1, num2, res;
    int op;
    
	printf ("\nInforme o numero 1: ");
    scanf ("%f",&num1);
    printf ("\nInforme o numero 2: ");
    scanf ("%f",&num2);
    printf ("\nInforme a Operação (1 - Media, 2 - Subtracao, 3 -  Multiplicacao, 4 - Divisao): ");
    scanf ("%d",&op);
          
    switch (op) {
        case 1:
            res = (num1 + num2)/2;
            printf ("\n\nA media aritmetica dos numeros eh: %.2f\n\n", res); 
            break;  
        case 2:
            if (num2 > num1)            
                res = num2 - num1;
            else
                res = num1 - num2;
            printf ("\n\nA diferenca entre os numeros eh: %.2f\n\n", res); 
            break;  
        case 3:
            res = num1 * num2;
            printf ("\n\nO produto entre os numeros eh: %.2f\n\n", res); 
            break;
        case 4:
            if (num2 != 0)            
                res = num1 / num2;
            else
                res = num1;
            printf ("\n\nA divisao entre os numeros eh: %.2f\n\n", res); 
            break;                              
        default:
               printf ("\n\nOpcao invalida !!!\n\n");
      }
}

