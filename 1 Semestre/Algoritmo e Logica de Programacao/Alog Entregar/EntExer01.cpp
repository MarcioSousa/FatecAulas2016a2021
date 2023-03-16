#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Biblioteca necessária para usar o SETLOCALE()
#include <conio.h>
#include <string.h> //Necessário para strlen

main(){
	setlocale(LC_ALL, "Portuguese"); //Instrução usada para configurar o idioma Português.
	
	int A = 0, B = 0, C = 0, M = 0, T = 0, N = 0, AM = 0, AT = 0, AN = 0, BM = 0, BT = 0, BN = 0, CM = 0, CT = 0, CN = 0;
	char elevador, periodo;
	float porcMaior = 0, porcMenor = 0, porcA = 0, porcB = 0, porcC = 0; 
	
	printf("====== PESQUISA DE USO DE ELEVADORES ======");
	printf("\nDigite o Elevador que você usa: A, B ou C. ");
	printf("\nDigite o período de uso do elevador: M = Manhã, T = Tarde ou N = Noite.");
	printf("\nDigite 0 (zero) para encerrar a contagem\n");
	printf("============================================\n");
	
	//ACRESCENTA UM VALOR AS VARIÁVEIS A, B, C, M, T, N
	do{
		printf("Elevador que é usado: ");
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

		printf("Período de uso do Elevador: ");
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
	
	//COLOCANDO VALORES PARA SABER QUE PERÍODO E ELEVADOR ESTÁ SENDO USADO DE UMA SÓ VEZ.
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
	
	//O ELEVADOR MAIS FREQUENTADO E EM QUE PERÍODO SE CONCENTRA O MAIOR FLUXO
	if(A > B && A > C){
		printf("O elevador mais frequentado é o A e ");
		if(AM > AT && AM > AN){
			printf("o período com maior fluxo é de Manhã.\n");
		}
		else if(AT > AM && AT > AN){
			printf("o período com maior fluxo é a Tarde\n");
		}
		else if(AN > AM && AN > AT){
			printf("o período com maior fluxo é a Noite\n");
		}
		else{
			printf("ambos são usados em mesmo período.\n");
		}
	}
	else if(B > A && B > C){
		printf("O elevador mais frequentado é o B e ");
		if(BM > BT && BM > BN){
			printf("o período com maior fluxo é de Manhã. \n");
		}
		else if(BT > BM && BT > BN){
			printf("o período com maior fluxo é a Tarde\n");
		}
		else if(BN > BM && BN > BT){
			printf("o período com maior fluxo é a Noite\n");
		}
		else{
			printf("ambos são usados em mesmo período.\n");
		}
	}
	else if(C > A && C > B){
		printf("O elevador mais frequentado é o C e ");
		if(CM > CT && CM > CN){
			printf("o período com maior fluxo é de Manhã. \n");
		}
		else if(CT > CM && CT > CN){
			printf("o período com maior fluxo é a Tarde\n");
		}
		else if(CN > CM && CN > CT){
			printf("o período com maior fluxo é a Noite\n");
		}
		else{
			printf("ambos são usados em mesmo período.\n");
		}
	}
	else 
	printf("Ambos são frequentados igualmente.\n");

    //QUAL O PERÍODO MAIS USADO DE TODOS E A QUE ELEVADOR PERTENCE
    if(M > T && M > N){
    	printf("O periodo mais usado é de Manhã e ");
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
			printf("ambos são frequentados igualmente.\n");
		}
	}
	else if(T > M && T > N){
		printf("O período mais usado é a Tarde e ");
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
			printf("ambos são frequentados igualmente.\n");
		}
	}
	else if(N > M &&  N > T){
		printf("O período mais usado é a Noite e ");
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
			printf("ambos são frequentados igualmente.\n");
		}
	}
	else{
		printf("Ambos são usados em mesmo período.\n");
	}
	
	//A DIFERENÇA PERCENTUAL ENTRE O MAIS USADO DOS HORÁRIOS E O MENOS USADO
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
	
	printf("A diferença percentual entre o mais usado dos horários e o menos usado é: %.0f\n", porcMaior - porcMenor);
	
	//A PORCENTAGEM SOBRE O TOTAL DE SERVIÇOS PRESTADOS DO ELEVADOR DE MÉDIA UTILIZADA
	if(A!=0 && B!= 0 && C!=0){
	    porcA = (A * 100) / (A + B + C);
       	porcB = (B * 100) / (A + B + C);
      	porcC = (C * 100) / (A + B + C);
	}

	printf("O Elevador A é utilizado %.0f por cento do dia.\n", porcA);
	printf("O Elevador B é utilizado %.0f por cento do dia.\n", porcB);
	printf("O Elevador C é utilizado %.0f por cento do dia.\n", porcC);
	printf("=== PESQUISA ENCERRADA ===\n\n");
	
	system("PAUSE");
	
}
