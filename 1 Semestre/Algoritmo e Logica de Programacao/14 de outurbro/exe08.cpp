#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main(){
	setlocale(LC_ALL,"Portuguese");
	
	for(int t=1000;t <=1999;t++)
	{
		if (t%11 == 5)
		{
			printf("Os n�meros divis�veis por 11 que fica entre 1000 e 1999 e que tem o resto 5 s�o: %d\n", t);
		}
	}
}
