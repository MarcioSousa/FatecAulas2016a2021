#include <stdio.h>
#include <stdlib.h>

int main(){
	int id1, id2, difer;
	scanf("%i %i", &id1, &id2);
	if(id1 == id2){
		printf("A diferen�a e Zero!");
	}else if(id1 > id2){
		difer = id1 - id2;
		printf("A diferen�a e %i", difer);
	}else{
		difer = id2 - id1;
		printf("A diferen�a e %i", difer);
	}
}
