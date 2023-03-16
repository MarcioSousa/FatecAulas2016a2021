#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void EscreverDiaSemana(int);
void ImprimirData(int, int, int);

main(){
	setlocale(LC_ALL, "Portuguese");
	
	int M = 0, D = 0, S = 0, A = 0, ano = 0, diaSemana = 0, numeroDiaSemana = 0;
	
	do{
		printf("Digite o Dia Mes Ano. Digite '0 0 0' para encerrar.\n");
		scanf("%i %i %i", &D, &M, &ano);
		
		if(D != 0 && M != 0 && ano != 0){
			ImprimirData(D, M, ano);
			
			//Separando. EX: 1863, S = 18 e A = 63
			S = ano/100;
			A = ano - (S * 100);
	
			//Diminuir mes com 2, março = 1, abril = 2 e colocando mes 11 e 12 como Janeiro e Fevereiro.
			//Diminuindo o ano com A--;
			if(M != 1 && M != 2){
				M = M - 2;
			}else{
				if(M == 1){
					M = 11;
				}else{
					M = 12;
				}
				A--;
			}
		
			diaSemana = ((2.6 * M) - 0.1) + D + A + A/4 + S/4 -(2*S);
			numeroDiaSemana = (int)diaSemana%7;	
			
			EscreverDiaSemana(numeroDiaSemana);
			
		}else{
			printf("Projeto Finalizado!\n==========\n");
		}
	
	}while(D != 0 && M != 0 && ano != 0);

	system("pause");
}

void EscreverDiaSemana(int NumeroDiaSemana){
	switch(NumeroDiaSemana){
		case 0:
			printf("Domingo.\n");
			break;
		case 1:
			printf("Segunda-Feira.\n");
			break;
		case 2:
			printf("Terça-Feira.\n");
			break;
		case 3:
			printf("Quarta-Feira.\n");
			break;
		case 4:
			printf("Quinta-Feira.\n");
			break;
		case 5:
			printf("Sexta-Feira.\n");
			break;
		case 6:
			printf("Sábado.\n");
			break;
		default:
			printf("Não foi possível verificar o dia da semana.\n");
	}
	printf("---------------------------------------\n");
}

void ImprimirData(int dia, int mes, int ano){
	if(dia < 10){
		printf("0%i/", dia);
	}else{
		printf("%i/", dia);
	}
	
	if(mes < 10){
		printf("0%i/", mes);
	}else{
		printf("%i/", mes);
	}
	
	printf("%i: ", ano);
	
}

