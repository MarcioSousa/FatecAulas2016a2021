#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main(){
	setlocale(LC_ALL,"Portuguese");
	
	int num1, num2, num3;
	
	printf("A sequencia Fibonacci até o 20º termo é a lista abaixo:\n\n");
	
	for (int t=1; t<=20; t++)
	{
		if (t==1)
		{
			printf("%dº = 0\n",t);
			num1 = t;
		}
		else
		{
			if(t==2)
			{
				printf("%dº = 1\n",t);
				num2 = 1;
			}
			else
			{
				num3=num1+num2;
				num1=num2;
				num2=num3;
				
				printf("%dº = %d\n", t, num3);
			}
		}
	}
}
