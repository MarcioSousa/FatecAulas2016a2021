#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Implemente uma funcao que calcule a area da superficie e o volume de uma esfera de raio R.
//Essa funcao deve obedecer ao prototipo: void calc_esfera (float R, float *area, float *volume)
//A area da superficie e o volume sao dados, respectivamente, por: A = 4 . pi . R^2
//e V = 4/3 . pi . R^3

void calc_esfera (float R, float *area, float *volume);

main()
{
	float raio, e_area, e_volume;
	
	printf("Informe o raio da esfera: ");
	scanf("%f",&raio);
	
	calc_esfera (raio, &e_area, &e_volume);
	
	printf("A area da superficie da esfera de raio %f eh %fm^2 e o volume eh %fm^3",raio,e_area,e_volume);


}

void calc_esfera (float R, float *area, float *volume)
{
	*area = 4*3.141592*R*R;
	*volume = 3.141592*R*R*R*1.333333;
}
