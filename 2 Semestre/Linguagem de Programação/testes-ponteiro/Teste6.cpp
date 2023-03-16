
#include <stdio.h>
 
int main(void)
{
    int m[3][3]={1,2,3,4,5,6,7,8,9};
    int *p1[3];
    int **p2;
    
	p1[0] = *m;	
	p2 = p1;
	
	printf("\n %d ", p2);
	printf("\n %d ", *m);
	printf("\n %d ", *p2);
	printf("\n %d ", **p2);
	
	
	
	
	
	
	
	 
    return(0);
	
}

