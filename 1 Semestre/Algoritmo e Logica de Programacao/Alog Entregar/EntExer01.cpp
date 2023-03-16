#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Biblioteca necess�ria para usar o SETLOCALE()
#include <conio.h>
#include <string.h> //Necess�rio para strlen

main(){
	setlocale(LC_ALL, "Portuguese"); //Instru��o usada para configurar o idioma Portugu�s.
	
	int A = 0, B = 0, C = 0, M = 0, T = 0, N = 0, AM = 0, AT = 0, AN = 0, BM = 0, BT = 0, BN = 0, CM = 0, CT = 0, CN = 0;
	char elevador, periodo;
	float porcMaior = 0, porcMenor = 0, porcA = 0, porcB = 0, porcC = 0; 
	
	printf("====== PESQUISA DE USO DE ELEVADORES ======");
	printf("\nDigite o Elevador que voc� usa: A, B ou C. ");
	printf("\nDigite o per�odo de uso do elevador: M = Manh�, T = Tarde ou N = Noite.");
	printf("\nDigite 0 (zero) para encerrar a contagem\n");
	printf("============================================\n");
	
	//ACRESCENTA UM VALOR AS VARI�VEIS A, B, C, M, T, N
	do{
		printf("Elevador que � usado: ");
		scanf("%c", &elevador);	
		fflush(stdin);		
		
		if(elevador == 'A'){
			A += 1;
		}
		else if(elevador == 'B'){
			B += 1;
		}
		else if(elevador == 'C'){
			C += 1;
		}
		
		if(elevador == '0'){
			break;
		}

		printf("Per�odo de uso do Elevador: ");
		scanf("%c", &periodo);	
		fflush(stdin);
				
		if(periodo == 'M'){
			M += 1;
		}
		else if(periodo == 'T'){
			T += 1;
		}
		else if(periodo == 'N'){
			N += 1;
		}
	
	//COLOCANDO VALORES PARA SABER QUE PER�ODO E ELEVADOR EST� SENDO USADO DE UMA S� VEZ.
		if (elevador == 'A' && periodo == 'M'){
			AM += 1;
		}
		else{
			if(elevador == 'A' && periodo == 'T'){
				AT += 1;
			}
			else{
				if(elevador == 'A' && periodo == 'N'){
					AN += 1;
				}
				else{
					if (elevador == 'B' && periodo == 'M'){
						BM += 1;
					}
					else{
						if (elevador == 'B' && periodo == 'T'){
							BT += 1;
						}
						else{
							if (elevador == 'B' && periodo == 'N'){
								BN += 1;
							}
							else{
								if (elevador == 'C' && periodo == 'M'){
									CM += 1;
								}
								else{
									if (elevador == 'C' && periodo == 'T'){
										CT += 1;
									}
									else{
										if (elevador == 'C' && periodo == 'N'){
											CN +=1;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		printf("............................................\n");
	}while (elevador != '0');
	
	printf("Valores: A = %d, B = %d, C = %d, M = %d, T = %d, N = %d\n", A, B, C, M, T, N);
	printf("Valores Juntos: AM = %d, AT = %d, AN = %d, BM = %d, BT = %d, BN = %d, CM = %d, CT = %d, CN = %d\n", AM, AT, AN, BM, BT, BN, CM, CT, CN);
	
	printf("\n=========================\n");
	printf("======= RESULTADO =======\n");
	printf("=========================\n");
	
	//O ELEVADOR MAIS FREQUENTADO E EM QUE PER�ODO SE CONCENTRA O MAIOR FLUXO
	if(A > B && A > C){
		printf("O elevador mais frequentado � o A e ");
		if(AM > AT && AM > AN){
			printf("o per�odo com maior fluxo � de Manh�.\n");
		}
		else if(AT > AM && AT > AN){
			printf("o per�odo com maior fluxo � a Tarde\n");
		}
		else if(AN > AM && AN > AT){
			printf("o per�odo com maior fluxo � a Noite\n");
		}
		else{
			printf("ambos s�o usados em mesmo per�odo.\n");
		}
	}
	else if(B > A && B > C){
		printf("O elevador mais frequentado � o B e ");
		if(BM > BT && BM > BN){
			printf("o per�odo com maior fluxo � de Manh�. \n");
		}
		else if(BT > BM && BT > BN){
			printf("o per�odo com maior fluxo � a Tarde\n");
		}
		else if(BN > BM && BN > BT){
			printf("o per�odo com maior fluxo � a Noite\n");
		}
		else{
			printf("ambos s�o usados em mesmo per�odo.\n");
		}
	}
	else if(C > A && C > B){
		printf("O elevador mais frequentado � o C e ");
		if(CM > CT && CM > CN){
			printf("o per�odo com maior fluxo � de Manh�. \n");
		}
		else if(CT > CM && CT > CN){
			printf("o per�odo com maior fluxo � a Tarde\n");
		}
		else if(CN > CM && CN > CT){
			printf("o per�odo com maior fluxo � a Noite\n");
		}
		else{
			printf("ambos s�o usados em mesmo per�odo.\n");
		}
	}
	else 
	printf("Ambos s�o frequentados igualmente.\n");

    //QUAL O PER�ODO MAIS USADO DE TODOS E A QUE ELEVADOR PERTENCE
    if(M > T && M > N){
    	printf("O periodo mais usado � de Manh� e ");
    	if(AM > BM && AM > CM){
    		printf("pertence ao elevador A.\n");
		}
		else if(BM > AM && BM > CM){
			printf("pertence ao elevador B.\n");
		}
		else if(CM > AM && CM > BM){
			printf("pertence ao elevador C.\n");
		}
		else{
			printf("ambos s�o frequentados igualmente.\n");
		}
	}
	else if(T > M && T > N){
		printf("O per�odo mais usado � a Tarde e ");
		if(AT > BT && AT > CT){
			printf("pertence ao elevador A.\n");
		}
		else if(BT > AT && BT > CT){
			printf("pertende ao elevador B.\n");
		}
		else if(CT > AT && CT > BT){
			printf("pertence ao elevador C.\n");
		}
		else{
			printf("ambos s�o frequentados igualmente.\n");
		}
	}
	else if(N > M &&  N > T){
		printf("O per�odo mais usado � a Noite e ");
		if(AN > BN && AN > CN){
			printf("pertence ao elevador A.");
		}
		else if(BN > AN && BN > CN){
			printf("pertence ao elevador B.");
		}
		else if(CN > AN && CN > BN){
			printf("pertence ao elevador C.");
		}
		else{
			printf("ambos s�o frequentados igualmente.\n");
		}
	}
	else{
		printf("Ambos s�o usados em mesmo per�odo.\n");
	}
	
	//A DIFEREN�A PERCENTUAL ENTRE O MAIS USADO DOS HOR�RIOS E O MENOS USADO
	if(M > T && M > N){
		porcMaior = (M * 100) / (M + T + N);
		if(T > N){
			porcMenor = (N * 100) / (M + T + N);
		}
		else{
			porcMenor = (T * 100) / (M + T + N);
		}
	}
	else if(T > M && T > N){
		porcMaior = (T * 100) / ( M + T + N);
		if(M > N){
			porcMenor = (N * 100) / (M + T + N);
		}
		else{
			porcMenor = (M * 100) / (M + T + N);
		}
	}
	else if(N > M && N > T){
		porcMaior = (N * 100) / (M + T + N);
		if(M > T){
			porcMenor = (T * 100) / (M + T + N);
		}
		else{
			porcMenor = (M * 100) / (M + T + N);
		}
	}
	
	printf("A diferen�a percentual entre o mais usado dos hor�rios e o menos usado �: %.0f\n", porcMaior - porcMenor);
	
	//A PORCENTAGEM SOBRE O TOTAL DE SERVI�OS PRESTADOS DO ELEVADOR DE M�DIA UTILIZADA
	if(A!=0 && B!= 0 && C!=0){
	    porcA = (A * 100) / (A + B + C);
       	porcB = (B * 100) / (A + B + C);
      	porcC = (C * 100) / (A + B + C);
	}

	printf("O Elevador A � utilizado %.0f por cento do dia.\n", porcA);
	printf("O Elevador B � utilizado %.0f por cento do dia.\n", porcB);
	printf("O Elevador C � utilizado %.0f por cento do dia.\n", porcC);
	printf("=== PESQUISA ENCERRADA ===\n\n");
	
	system("PAUSE");
	
}
