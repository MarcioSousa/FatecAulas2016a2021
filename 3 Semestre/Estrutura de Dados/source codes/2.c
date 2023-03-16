#include <stdio.h>

int main(void)
{
    int v[10] = {2,1,3,4,5,6,7,8,9,10};
    //maior: {10,9,8,7,6,5,4,3,2,1} //45
    //menor: {1,2,3,4,5,6,7,8,9,10} //0 ou {2,1,3,4,5,6,7,8,9,10} //1
    //medio: {4,2,5,3,10,9,8,7,6,1} {7,6,5,4,3,2,8,1,9,10} //22
    
    int tamanho = 10;
    int i,j,r,aux, cont=0;
    
    printf("\n");
    for(i=tamanho-1; i >= 1; i--) 
    {  
        for(j=0; j < i ; j++) 
        {
            if(v[j]>v[j+1]) 
            {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
                cont++;
                
                printf("%i\t%d %d %d %d %d %d %d %d %d %d\n",cont,v[0],v[1],v[2],v[3],v[4],v[5],v[6],v[7],v[8],v[9]);
            }
        }
    }

    /*for(r = 0; r < 10; ++r)
    {
        printf(" %d",v[r]);
    }*/
    
    return 0;
}

