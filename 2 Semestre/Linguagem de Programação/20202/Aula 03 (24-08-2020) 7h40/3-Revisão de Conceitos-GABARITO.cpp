#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 			// Biblioteca necess�rio para usar o SETLOCALE()

//USO DO FOR() - Exerc�cio 1
/*main()
{
    setlocale(LC_ALL, "Portuguese");      // Instru��o usada para configurar o idioma Portugu�s
      
    int i, num, qtdep=0, qtdei=0, somap=0, somai=0;
            
    for (i=0; i < 10; i++)
    {
        printf("Informe um n�mero: ");
        scanf ("%d", &num);
          
        if ((num%2) == 0)
    	{   
			qtdep = qtdep + 1;
			somap = somap + num;
		}
        else
        {
            qtdei = qtdei + 1;
            somai = somai + num;
    	}
    }
    printf("\nQuantidade de pares = %d\n", qtdep);
    printf("Quantidade de �mpares = %d\n\n", qtdei);
      
    printf("\nSoma dos pares = %d\n", somap);
    printf("M�dia dos �mpares = %d\n\n", somai/qtdei);
}

//USO DO FOR() - Exerc�cio 2
main()
{
    setlocale(LC_ALL, "Portuguese");      // Instru��o usada para configurar o idioma Portugu�s
      
    int num;
                
    for (int i=1; i <= 5; i++)
    {
        printf("Informe um n�mero: ");
        scanf ("%d", &num);
            
    	if (num<0)
    	{
    		printf ("\n\nO programa foi encerrado !!!");
            break;
    	}
	}
}

//USO DO WHILE() - Exerc�cio 1
main()
{
    setlocale(LC_ALL, "Portuguese");      // Instru��o usada para configurar o idioma Portugu�s
      
    char vinho;
    int q_t=0, q_b=0, q_r=0, total=0;
      
    while (vinho != 'F')
    {
        printf("Informe o tipo de vinho (T - tinto; B - branco, R - ros�) ou F - para encerrar: ");
        scanf ("%s", &vinho);
            
        switch (vinho)
        {
            case 'T':
                q_t = q_t + 1;
                break;
            case 'B':
                q_b = q_b + 1;
                break;
            case 'R':
                q_r = q_r + 1;
                break;
        }
        total = q_t + q_b + q_r;
    }
      
    printf ("\n\nA porcentagem de vinho tinto �: %.2f", (q_t/float(total)*100));
    printf ("\n\nA porcentagem de vinho branco �: %.2f", (q_b/float(total)*100));
    printf ("\n\nA porcentagem de vinho ros� �: %.2f\n\n", (q_r/float(total)*100));
}

//USO DO WHILE() - Exerc�cio 2
main()
{
    setlocale(LC_ALL, "Portuguese");      // Instru��o usada para configurar o idioma Portugu�s

    int qtde=0, num, maior=0;
      
    while (qtde < 10)
    {
        printf("Informe um n�mero: ");
        scanf ("%d", &num);
          
        if (num > maior)
        {
            maior = num;
    	}
        qtde = qtde + 1;
    }
    printf ("\nO maior n�mero �: %d\n\n", maior);
}

//USO DO DO ... WHILE() - Exerc�cio 1
/*main()
{
    setlocale(LC_ALL, "Portuguese");      // Instru��o usada para configurar o idioma Portugu�s
      
    int num, soma=0, qtde=0;
    float media;
      
    do
    {
        printf("Informe um n�mero: ");
        scanf ("%d", &num);
          
        if (num > 0)
        {
            soma = soma + num;
            qtde = qtde + 1;
        }      
    }
    while (num > 0);
      
    media = float(soma)/(qtde);
      
    printf ("\nA m�dia dos n�meros inteiros positivos �: %.2f\n\n", media);
}*/

//USO DO DO ... WHILE() - Exerc�cio 2
main()
{
    setlocale(LC_ALL, "Portuguese");      // Instru��o usada para configurar o idioma Portugu�s

    int num1, num2, qtde=0;
      
    do
    {
    	printf ("\nInforme o primeiro n�mero: ");
        scanf ("%d", &num1); 
        printf ("Informe o segundo n�mero: ");
        scanf ("%d", &num2);
            
        if (num1%num2 == 0)
        {
            printf ("O n�mero %d � divis�vel pelo n�mero %d\n", num1, num2);
            qtde = qtde + 1;
        }
    }
    while ((num1%num2) == 0);
      
    printf ("\n\n%d n�meros digitados foram divis�veis um pelo outro\n\n", (qtde * 2));
}



