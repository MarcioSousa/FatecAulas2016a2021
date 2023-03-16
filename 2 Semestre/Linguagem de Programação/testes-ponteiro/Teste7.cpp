	#include <stdio.h>
	
	void imprimeMatriz(int *p, int lin, int col);
	void inicializaMatriz(int *p, int size,int valor);
	
	int main()
	{
	    
		 
	    int matriz1[][3]={1,2,3,4,5,6,7,8,9};
	 	int matriz2[][2]={1,2,3,4};      
	    int matriz3[][3]={1,2,3,4,5,6};      
		 
		imprimeMatriz(&matriz1[0][0], 3, 3); 
		imprimeMatriz(&matriz2[0][0], 2, 2); 
		imprimeMatriz(&matriz3[0][0], 2, 3); 
	
	   	int tam = sizeof(matriz1)/sizeof(int);
		inicializaMatriz(&matriz1[0][0], tam, -1); 
	
		imprimeMatriz(&matriz1[0][0], 3, 3); 
		
		
	}

 void imprimeMatriz(int *p, int lin, int col)
 {
        int i,j,pos;
	    
	    for(i = 0;  i< lin; i++)
	       for(j = 0;  j< col; j++)
	       {
	           	pos = (i*lin)+j;
	            printf("\nPos =%d Valor= %d " ,pos, *(p +pos));	     	
		   }   
		
		printf("\n");	     	
	
 }  

void inicializaMatriz(int *p, int elementos,int valor)
 {
        int i,j;
	    
	    for(i = 0;  i< elementos; i++)
	    {
	           	
	            *(p +i) = valor;	     	
		}   
		
		printf("\n");	     	
	
 }  


