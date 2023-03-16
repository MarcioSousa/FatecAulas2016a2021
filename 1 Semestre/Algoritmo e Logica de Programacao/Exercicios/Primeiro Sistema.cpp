#include <stdio.h>
#include <stdlib.h>
//scanf (leia)
//printf (escreva)
//int, float, double, char
     //FAZER UM PROGRAMA QUE RECEBA 2 NÚMEROS, CALCULE SUA MÉDIA E EXIBA O RESULTADO:
     
	//PSEUDOCÓDIGO:
    //ALGORÍTMO MÉDIA
    //REAL: NUM1, NUM2, MEDIA;
    //INICIO
	      //LEIA(NUM1);
		  //LEIA(NUM2);
		  //MEDIA <--(NUM1 + NUM2)/2;
		  //ESCREVA(MEDIA);
    //FIM

main()
{
	//DECLARAÇÃO DAS VARIÁVEIS
	float num1, num2, media;
	
	//VALOR A PRIMEIRA VARIÁVEL NUM1
    printf("Digite o primeiro numero: ");
	scanf("%f", &num1);
	
	//VALOR A SEGUNDA VARIÁVEL NUM2
	printf("Digite o segundo numero: ", & num2);
	scanf("%f",& num2);
	
	//PROCESSA O VALOR ENTRE AS VARIÁVEIS
	media = (num1 + num2)/2;
	
	//MOSTRANDO O RESULTADO NA TELA
	printf("A media entre os numeros: %f",media);
	
	system ("PAUSE");
}
