#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
 
main(){
	setlocale(LC_ALL, "Portuguese");

	int ne;
	
	printf("================================================\n");
	printf("==== EXERCÍCIOS DE LINGUAGEM DE PROGRAMAÇÃO ====\n");
	printf("================================================\n\n");
	printf("DIGITE O NÚMERO DO EXERCÍCIO(2 ao 11): ");
	scanf("%d", &ne);
	
	if(ne == 2){
		printf("=====================================================\n");
		printf("|FAÇA UM PROGRAMA QUE CALCULE A MÉDIA DA DISCIPLINA |\n");
		printf("|DE LP, SEGUNDO A FÓRMULA:                          |\n");
		printf("|MF=((P1 + P2)/2) * 0.7 + L * 0.1 + PR * 0.2           |\n");
		printf("=====================================================\n\n");
		
		
		float p1, p2, l, pr, mf;
		
		printf("Digite P1: ");
		scanf("%f", &p1);
		printf("Digite P2: ");
		scanf("%f", &p2);
		printf("Digite L: ");
		scanf("%f", &l);
		printf("Digite PR: ");
		scanf("%f", &pr);
		
		mf = (p1 + p2) * 0.7 + l * 0.1 + pr * 0.2;
		
		printf("Sua média em LP é: %f\n", mf);

	}else if(ne == 3){
		printf("=====================================================\n");
		printf("|FAÇA UM PROGRMAA QUE RECEBA 3 NÚMEROS E COLOQUE-OS |\n");
		printf("|EM ORDEM CRESCENTE.                                |\n");
		printf("=====================================================\n\n");
		
		int n1, n2, n3;
		
		printf("Digite o 1º Numero: ");
		scanf("%d", &n1);
		printf("Digite o 2º Numero: ");
		scanf("%d", &n2);
		printf("Digite o 3º Numero: ");
		scanf("%d", &n3);
		
		if(n1 < n2 && n1 < n3){
			if(n2 < n3){
				printf("ORDEM CRESCENTE É : %d, %d, %d", n1, n2, n3);
			}else{
				printf("ORDEM CRESCENTE É : %d, %d, %d", n1, n3, n2);
			}
		}else if(n2 < n1 && n2 < n3){
			if(n1 < n3){
				printf("ORDEM CRESCENTE É : %d, %d, %d", n2, n1, n3);
			}else{
				printf("ORDEM CRESCENTE É : %d, %d, %d", n2, n3, n1);
			}
		}else if(n3 < n1 && n3 < n2){
			if(n1 < n2){
				printf("ORDEM CRESCENTE É : %d, %d, %d", n3, n1, n2);
			}else{
				printf("ORDEM CRESCENTE É : %d, %d, %d", n3, n2, n1);
			}
		}else if(n1 == n2){
			if(n1 < n3){
				printf("ORDEM CRESCENTE É : %d, %d, %d", n1, n2, n3);
			}else{
				printf("ORDEM CRESCENTE É : %d, %d, %d", n3, n1, n2);
			}
		}else if(n1 == n3){
			if(n1 < n2){
				printf("ORDEM CRESCENTE É : %d, %d, %d", n1, n3, n2);
			}else{
				printf("ORDEM CRESCENTE É : %d, %d, %d", n2, n1, n3);
			}
		}else if(n2 == n3){
			if(n1 < n2){
				printf("ORDEM CRESCENTE É : %d, %d, %d", n1, n3, n2);
			}else{
				printf("ORDEM CRESCENTE É : %d, %d, %d", n2, n1, n3);
			}
		}else if(n1 == n2 && n2 == n3){
			printf("ORDEM CRESCENTE É : %d, %d, %d", n1, n2, n3);
		}		
	}else if(ne == 4){
		printf("=====================================================\n");
		printf("|FAÇA UM PROGRAMA QUE RECEBA O SEXO E A ALTURA DE   |\n");
		printf("|UMA PESSOA E CALCULE SEU PESO IDEAL, SEGUINDO AS   |\n");
		printf("|FORMULAS                                           |\n");
		printf("|HOMEM  -> PESO IDEAL = (72.7 * H) - 58             |\n");
		printf("|MULHER -> PESO IDEAL = (62.1 * H) - 44.7           |\n");
		printf("=====================================================\n\n");

		float alt, peso;
		char sexo;
		
		printf("Digite a altura: ");
		scanf("%f", &alt);
		fflush(stdin);
		printf("Digite o sexo (m = Masculino, f = Feminino): ");
		scanf("%c", &sexo);
		
		if(sexo == 'm'){
			peso = (72.7 * alt) - 58;
		}else{
			peso = (62.1 * alt) - 44.7;
		}
		
		printf("O peso ideal é: %f\n", peso);
		
	}else if(ne == 5){
		printf("=====================================================\n");
		printf("|FAÇA UM PROGRAMA QUE RECEBA 10 NÚMEROS INTEIROS E  |\n");
		printf("|AO FINAL, CONTE QUANTOS SÃO PARES E ÍMPARES.       |\n");
		printf("|CALCULE TAMBÉM A SOMA DOS PARES E A MÉDIA DOS      |\n");
		printf("|ÍMPARES.                                           |\n");
		printf("=====================================================\n\n");
		
		int num, qt_p = 0, qt_i = 0, s_p = 0, s_i = 0, m_i = 0; 
		
		for(int t = 0; t < 10; t++){
			printf("Digite o %dº numero: ", t+1);
			scanf("%d", &num);
			
			if(num%2 == 0){
				qt_p++;
				s_p = s_p + num;
			}else{
				qt_i++;
				s_i = s_i + num;
			}
		}
		
		m_i = s_i/qt_i;
		
		printf("Qtde de pares: %d\n", qt_p);
		printf("Qtde de ímpares: %d\n", qt_i);
		printf("Soma dos pares: %d\n", s_p);
		printf("Média dos ímpares: %d\n", m_i);
		
	}else if(ne == 6){
		printf("=====================================================\n");
		printf("|FAÇA UM PROGRAMA QUE SOLICITE AO USUÁRIO DIGITAR   |\n");
		printf("|NÚMEROS INTEIROS POSITIVOS. ENCERRE A ENTRADA DE   |\n");
		printf("|DADOS QUANDO FOR DIGITADO 0 OU UM NUMERO NEGATIVO. |\n");
		printf("|AO FINAL, CALCULE A MÉDIA DOS NÚMEROS VÁLIDOS      |\n");
		printf("|INFORMADOS (USAR WHILE).                           |\n");
		printf("=====================================================\n\n");
		
		int num, qt = 0, soma = 0, media = 0;
		
		printf("Digite um número: ");
		scanf("%d", &num);
		
		while(num > 0){
			qt++;
			soma = soma + num;
			printf("Digite um número: ");
			scanf("%d", &num);
		}
		
		media = soma / qt;
		printf("A média dos números positivos é: %d\n", media);
		
	}else if(ne == 7){
		printf("=====================================================\n");
		printf("|FAÇA UM PROGRAMA QUE SOLICITE 2 NÚMEROS INTEIROS   |\n");
		printf("|POSITIVOS ATÉ QUE O PRIMEIRO NÃO SEJA DIVISÍVEL    |\n");
		printf("|PELO SEGUNDO. AO FINAL, EXIBA QUANTOS DELES ISSO   |\n");
		printf("|FOI POSSÍVEL (USAR DO...WHILE).                    |\n");
		printf("=====================================================\n\n");
		
		int num1 = 0, num2 = 0;
		
		do{
			printf("Digite dois número positivo: ");
			scanf("%d %d", &num1, &num2);
			
			if((num1/num2)%2 == 0){
				printf("O resultado da divisão de %d/%d = %d\n", num1, num2, num1/num2);
			}
			
		}while((num1/num2)%2 == 0);
	}else if(ne == 8){
		printf("=====================================================\n");
		printf("|FAÇA UM PROGRAMA QUE RECEBA 10 NUMEROS ARMAZENE-OS |\n");
		printf("|NUM VETOR E EXIBA ESTES NÚMEROS NA ORDEM INVERSA.  |\n");
		printf("=====================================================\n\n");
		
		float vetor[10];
		
		for(int t = 0; t < 10; t++){
			printf("Digite o %dº Número: ", t + 1);
			scanf("%f", &vetor[t]);
		}
		
		for(int t = 9; t > -1; t--){
			printf("Valores digitados: %.1f\n", vetor[t]);
		}
		
	}else if(ne == 9){
		printf("=====================================================\n");
		printf("|FAÇA UM PROGRAMA QUE RECEBA UM VERTOR DE 5 NÚMEROS,|\n");
		printf("|COLOQUE-OS EM ORDEM CRESCENTE E EXIBA-OS.          |\n");
		printf("=====================================================\n\n");
		
		float num[5], aux;
		
		for(int t = 0; t < 5; t++){
			printf("Digite o %dº Número: ", t+1);
			scanf("%f", &num[t]);
		}
		
		//Bubble Sort
		for(int t = 5 - 1; t > 0; t--){
			for(int i = 0; i < t; i++){
				if(num[i] > num[i + 1]){
					aux = num[i];
					num[i] = num[i + 1];
					num[i + 1] = aux;
				}
			}
		}
		
   		printf("Ordem crescente dos números digitados são: %.1f, %.1f, %.1f, %.1f, %.1f.", num[0], num[1], num[2], num[3], num[4]);
   		
	}else if(ne == 10){
		printf("=====================================================\n");
		printf("|FAÇA UM PROGRAMA QUE CRIE UMA MATRIZ DE 5 LINHAS E |\n");
		printf("|3 COLUNAS, ARMAZENE OS NÚMEROS INTEIROS NESSA      |\n");
		printf("|MATRIZ E EXIBA ESTES NÚMEROS.                      |\n");
		printf("=====================================================\n\n");
		
		int num[5][3];
		
		for(int t = 0; t < 5; t++){
			for(int u = 0; u < 3; u++){
				printf("Posição %d , %d. Digite um número inteiro: ", t+1, u+1);
				scanf("%d", &num[t][u]);
			}
		}
		
		printf("Os Números digitados na ordem é: ");
		
		for(int t = 0; t < 5; t++){
			for(int u = 0; u < 3; u++){
				if(t == 4 && u == 2){
					printf("%d.\n", num[t][u]);
				}else{
					printf("%d, ", num[t][u]);
				}
			}
		}
		
	}else if(ne == 11){
		printf("=====================================================\n");
		printf("|FAÇA UM PROGRAMA QUE CRIE UMA MATRIZ 3X3, ARMAZENE |\n");
		printf("|OS NÚMEROS INTEIROS NELA E, AO FINAL, CALCULE A    |\n");
		printf("|SOMA NA SUA DIAGONAL SECUNDÁRIA.                   |\n");
		printf("|                     EXEMPLO                       |\n"); 
		printf("|3 7 2                                              |\n");
		printf("|1 5 4    SOMA DIAGONAL SEGUNDÁRIA = 2 + 5 + 9 = 16 |\n");
		printf("|9 5 8                                              |\n");
		printf("=====================================================\n\n");
		
		int num[3][3];
		
		for(int t = 0; t < 3; t++){
			for(int u = 0; u < 3; u++){
				printf("Matriz posição %d %d. Digite um número inteiro: ", t+1, u+1);
				scanf("%d", &num[t][u]);
			}
		}
		
		printf("\n----- MATRIZ -----\n");
		
		for(int t = 0; t < 3; t++){
			for(int u = 0; u < 3; u++){
				if(t == 1 && u == 2){
					printf("%d    ", num[t][u]);
					printf("SOMA DIAGONAL SEGUNDÁRIA : %d + %d + %d = %d\n", num[0][2], num[1][1], num[2][0], num[0][2] + num[1][1] + num[2][0]);
				}else if(u != 2){
					printf("%d ", num[t][u]);
				}else{
					printf("%d\n", num[t][u]);
				}
			}
		}
		
	}else{
		printf("Valor incorreto!");
	}
}
