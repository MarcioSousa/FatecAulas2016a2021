#include <stdio.h>
#include <stdlib.h>

struct Aluno{
	int nmat;
	float nota[3];
	float media;
};

int main(){
	Aluno Ana;
	Ana.nmat = 102030;
	Ana.nota[0] = 10.0;
	Ana.nota[1] = 5.0;
	Ana.nota[2] = 3.0;
	
	Ana.media = (Ana.nota[0] + Ana.nota[1] + Ana.nota[2])/3;
	
	printf("A média da aluna Ana eh: %.2f", Ana.media);
	
	return 0;
}
