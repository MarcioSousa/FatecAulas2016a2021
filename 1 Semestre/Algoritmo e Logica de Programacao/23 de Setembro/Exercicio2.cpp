#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main(){
	setlocale(LC_ALL,"Portuguese");
	
	int planeta;
	float peso, pesonoplaneta, pesonaterra;
	
	printf("Digite o código do Planeta: ");
	scanf("%d", &planeta);
	
	printf("Digite o peso do Planeta: ");
	scanf("%f", &pesonaterra);
	
	//segundo: peso = massa*gravidade
	//primeiro: massa = peso / 9.8
	
	switch(planeta){
		case 1:
			pesonoplaneta = (pesonaterra / 10) * 0.37;
			printf("O peso no planeta Mercurio é %f", pesonoplaneta);
			break;
			case 2:
				pesonoplaneta = (pesonaterra / 10) * 0.88;
				printf("O peso no planeta Vênus é %f", pesonoplaneta);
				break;
				case 3:
					pesonoplaneta = (pesonaterra / 10) * 0.38;
					printf("O peso no planeta Marte é %f", pesonoplaneta);
					break;
					case 4:
						pesonoplaneta = (pesonaterra / 10) * 2.64;
						printf("O peso no planeta Júpiter é %f", pesonoplaneta);
						break;
						case 5:
							pesonoplaneta = (pesonaterra / 10) * 1.15;
							printf("O peso no planeta Saturno é %f", pesonoplaneta);
							break;
							case 6:
								pesonoplaneta(pesonaterra / 10) * 1.17;
								printf("O peso no planeta Urano é %f", pesonoplaneta);
								break;
								default:
									printf("O número digitado não corresponde ao planeta! Digite novamente:");
	}
	
}
