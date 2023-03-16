#include <stdio.h>
#include <stdlib.h>


typedef struct{
      int dia;
      int mes;
      int ano; 
} data; 
 

   
   
data somaEvento (data inicio);   
    
   

int main(void)
{
    struct dma c;  
 	data a, b;

	scanf ("%d %d %d", &c.dia, &c.mes, &c.ano);
   	   	
	b = somaEvento (c);
   	
	printf ("%d %d %d\n", c.dia, c.mes, c.ano);   
	printf ("%d %d %d\n", b.dia, b.mes, b.ano);
   
	
   system("pause");
   return 0;   
}


data somaEvento (data inicio) {
   data fim;
 
   fim.dia = inicio.dia + 1;
   fim.mes = inicio.mes + 1;
   fim.ano = inicio.ano + 1;
   
   inicio.dia = inicio.dia + 10;

   return fim;
}



