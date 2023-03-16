
#include <stdio.h>
 
int main(void)
{
    int m[3][3]={1,2,3,4,5,6,7,8,9};
	int *p;
	
	p = m[0];
	printf("\n %i", *p);
	
	p = m[1];
	printf("\n %i", *p);
	
	p = m[2];
	printf("\n %i", *p);
	 
    return(0);
		
	
}

