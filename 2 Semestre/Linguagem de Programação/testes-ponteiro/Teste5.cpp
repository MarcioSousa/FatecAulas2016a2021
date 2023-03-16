
#include <stdio.h>
 
int main(void)
{
    int m[3][3]={1,2,3,4,5,6,7,8,9};
    int *p1;
	p1 = *m;	
	
	printf("\n %d ", *p1);
	 
    return(0);
	
}

