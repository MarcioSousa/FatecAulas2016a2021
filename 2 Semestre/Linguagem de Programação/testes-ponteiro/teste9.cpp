#include <stdio.h>
#include <stdlib.h>
	
int main()
{
         int x[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
         int i;
         
         int *p;
         
         for(i=0; i < 4; i++)
            printf(" %d ", x[i]);
         
		 p = x[3];   
         for(i=0; i < 4; i++)
            printf(" %d ", *p++);
            
         for(i=0; i < 4; i++)
            printf(" %d ", x[0][i]);
         
}
         
         
         
	
