#include <stdio.h>

void copyvec(int v1[], int v2[], int tam) {
    int indx = 0;
    for (indx = 0; indx < tam; indx++) {
        v2[indx] = v1[indx];
    }
}

int main(void)
{
    int v[10] = {10,9,8,7,6,5,4,3,2,1}, v2[10];
    //maior: {10,9,8,7,6,5,4,3,2,1} //45
    //menor: {1,2,3,4,5,6,7,8,9,10} //0 ou {2,1,3,4,5,6,7,8,9,10} //1
    //medio: {4,2,5,3,10,9,8,7,6,1} {7,6,5,4,3,2,8,1,9,10} //22
    
    int tamanho = 10;
    int i,j,r,aux, 
		contb=0, conts=0;
    
    copyvec(v,v2,10);
    
    printf("Entrada: ");
    for(r = 0; r < 10; ++r)
      printf(" %i",v[r]);
    printf("\n\n");
    
    /*for(i=tamanho-1; i >= 1; i--) 
    {  
      for(j=0; j < i ; j++) 
      {
        if(v[j]>v[j+1]) 
        	{
            aux = v[j];
            v[j] = v[j+1];
            v[j+1] = aux;
            contb++;
                
            //printf("%i\t",cont);
            //for(r = 0; r < 10; ++r)
        		//	printf(" %i",v2[r]);
        		//printf("\n");
          }
      }
    }*/
    
    for(i = 0; i < 10; i++)
    {
			for(j = i; j < 10; j++)
			{
				if(v2[i] > v2[j])
				{
					aux = v2[i];
					v2[i] = v2[j];
					v2[j] = aux;
					conts++;
				}
			}
		}
		
		printf("\n%i\n", conts);
    
    return 0;
}

