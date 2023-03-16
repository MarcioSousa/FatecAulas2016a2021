#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main(){
	setlocale(LC_ALL,"Portuguese");
	
	int tabuada;
	
	for (int x=0; x<=10; x++)
	{
		for (int ini=0;ini<=5;ini++)
		{
			if (ini == 10 and x==10)
			{
				printf("%d X %d = %d| ",ini, x, ini * x);	
			}
			else 
			{
				if (ini > 9 and x > 9)
				{
					printf("%d X %d = 0%d | ",ini, x, ini * x);
				}
				else
				{
					if (ini > 9 and ini*x > 9)
					{
						printf("%d X 0%d = %d | ",ini, x, ini * x);
					}
					else
					{
						if (x > 9 and ini*x>9)
						{
							printf("0%d X %d = %d | ",ini, x, ini * x);
						}
						else
						{
							if (ini >9)
							{
								printf("%d X 0%d = 0%d | ",ini, x, ini * x);
							}
							else
							{
								if (x > 9)
								{
									printf("0%d X %d = 0%d | ",ini, x, ini * x);
								}
								else
								{
									if (ini*x > 9)
									{
										printf("0%d X 0%d = %d | ",ini, x, ini * x);
									}
									else
									{
										printf("0%d X 0%d = 0%d | ",ini, x, ini * x);
									}
								}
							}
						}
					}
				}
			}
		}
		printf("\n");
	}
	
	printf("\n");
	
	for (int x=0; x<=10; x++)
	{
		for (int ini=6;ini<=10;ini++)
		{
			if (ini == 10 and x==10)
			{
				printf("%d X %d = %d| ",ini, x, ini * x);	
			}
			else 
			{
				if (ini > 9 and x > 9)
				{
					printf("%d X %d = 0%d | ",ini, x, ini * x);
				}
				else
				{
					if (ini > 9 and ini*x > 9)
					{
						printf("%d X 0%d = %d | ",ini, x, ini * x);
					}
					else
					{
						if (x > 9 and ini*x>9)
						{
							printf("0%d X %d = %d | ",ini, x, ini * x);
						}
						else
						{
							if (ini >9)
							{
								printf("%d X 0%d = 0%d | ",ini, x, ini * x);
							}
							else
							{
								if (x > 9)
								{
									printf("0%d X %d = 0%d | ",ini, x, ini * x);
								}
								else
								{
									if (ini*x > 9)
									{
										printf("0%d X 0%d = %d | ",ini, x, ini * x);
									}
									else
									{
										printf("0%d X 0%d = 0%d | ",ini, x, ini * x);
									}
								}
							}
						}
					}
				}
			}
		}
		printf("\n");
	}
	
    printf("\n");
    
    printf("Digite um número inteiro de uma tabuada que deseja: ");
    scanf("%d", &tabuada);
    
    printf("Você deseja a tabuada do %d\n", tabuada);
    
    printf("A tabuada está logo abaixo...\n\n");
    
    for (int t=0; t<=10 ;t++)
    {
    	if (t == 10)
    	{
    		printf("%d X %d = %d\n",t , tabuada, t * tabuada);
		}
		else
		{
			printf(" %d X %d = %d\n",t , tabuada, t * tabuada);
		}
    	
	}
    
    printf("\n");
    
    system("PAUSE");
}

