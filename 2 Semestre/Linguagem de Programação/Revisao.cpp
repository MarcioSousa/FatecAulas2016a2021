#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
 
main(){
	setlocale(LC_ALL, "Portuguese");

	int ne;
	
	printf("================================================\n");
	printf("==== EXERC�CIOS DE LINGUAGEM DE PROGRAMA��O ====\n");
	printf("================================================\n\n");
	printf("DIGITE O N�MERO DO EXERC�CIO(2 ao 11): ");
	scanf("%d", &ne);
	
	if(ne == 2){
		printf("=====================================================\n");
		printf("|FA�A UM PROGRAMA QUE CALCULE A M�DIA DA DISCIPLINA |\n");
		printf("|DE LP, SEGUNDO A F�RMULA:                          |\n");
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
		
		printf("Sua m�dia em LP �: %f\n", mf);

	}else if(ne == 3){
		printf("=====================================================\n");
		printf("|FA�A UM PROGRMAA QUE RECEBA 3 N�MEROS E COLOQUE-OS |\n");
		printf("|EM ORDEM CRESCENTE.                                |\n");
		printf("=====================================================\n\n");
		
		int n1, n2, n3;
		
		printf("Digite o 1� Numero: ");
		scanf("%d", &n1);
		printf("Digite o 2� Numero: ");
		scanf("%d", &n2);
		printf("Digite o 3� Numero: ");
		scanf("%d", &n3);
		
		if(n1 < n2 && n1 < n3){
			if(n2 < n3){
				printf("ORDEM CRESCENTE � : %d, %d, %d", n1, n2, n3);
			}else{
				printf("ORDEM CRESCENTE � : %d, %d, %d", n1, n3, n2);
			}
		}else if(n2 < n1 && n2 < n3){
			if(n1 < n3){
				printf("ORDEM CRESCENTE � : %d, %d, %d", n2, n1, n3);
			}else{
				printf("ORDEM CRESCENTE � : %d, %d, %d", n2, n3, n1);
			}
		}else if(n3 < n1 && n3 < n2){
			if(n1 < n2){
				printf("ORDEM CRESCENTE � : %d, %d, %d", n3, n1, n2);
			}else{
				printf("ORDEM CRESCENTE � : %d, %d, %d", n3, n2, n1);
			}
		}else if(n1 == n2){
			if(n1 < n3){
				printf("ORDEM CRESCENTE � : %d, %d, %d", n1, n2, n3);
			}else{
				printf("ORDEM CRESCENTE � : %d, %d, %d", n3, n1, n2);
			}
		}else if(n1 == n3){
			if(n1 < n2){
				printf("ORDEM CRESCENTE � : %d, %d, %d", n1, n3, n2);
			}else{
				printf("ORDEM CRESCENTE � : %d, %d, %d", n2, n1, n3);
			}
		}else if(n2 == n3){
			if(n1 < n2){
				printf("ORDEM CRESCENTE � : %d, %d, %d", n1, n3, n2);
			}else{
				printf("ORDEM CRESCENTE � : %d, %d, %d", n2, n1, n3);
			}
		}else if(n1 == n2 && n2 == n3){
			printf("ORDEM CRESCENTE � : %d, %d, %d", n1, n2, n3);
		}		
	}else if(ne == 4){
		printf("=====================================================\n");
		printf("|FA�A UM PROGRAMA QUE RECEBA O SEXO E A ALTURA DE   |\n");
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
		
		printf("O peso ideal �: %f\n", peso);
		
	}else if(ne == 5){
		printf("=====================================================\n");
		printf("|FA�A UM PROGRAMA QUE RECEBA 10 N�MEROS INTEIROS E  |\n");
		printf("|AO FINAL, CONTE QUANTOS S�O PARES E �MPARES.       |\n");
		printf("|CALCULE TAMB�M A SOMA DOS PARES E A M�DIA DOS      |\n");
		printf("|�MPARES.                                           |\n");
		printf("=====================================================\n\n");
		
		int num, qt_p = 0, qt_i = 0, s_p = 0, s_i = 0, m_i = 0; 
		
		for(int t = 0; t < 10; t++){
			printf("Digite o %d� numero: ", t+1);
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
		printf("Qtde de �mpares: %d\n", qt_i);
		printf("Soma dos pares: %d\n", s_p);
		printf("M�dia dos �mpares: %d\n", m_i);
		
	}else if(ne == 6){
		printf("=====================================================\n");
		printf("|FA�A UM PROGRAMA QUE SOLICITE AO USU�RIO DIGITAR   |\n");
		printf("|N�MEROS INTEIROS POSITIVOS. ENCERRE A ENTRADA DE   |\n");
		printf("|DADOS QUANDO FOR DIGITADO 0 OU UM NUMERO NEGATIVO. |\n");
		printf("|AO FINAL, CALCULE A M�DIA DOS N�MEROS V�LIDOS      |\n");
		printf("|INFORMADOS (USAR WHILE).                           |\n");
		printf("=====================================================\n\n");
		
		int num, qt = 0, soma = 0, media = 0;
		
		printf("Digite um n�mero: ");
		scanf("%d", &num);
		
		while(num > 0){
			qt++;
			soma = soma + num;
			printf("Digite um n�mero: ");
			scanf("%d", &num);
		}
		
		media = soma / qt;
		printf("A m�dia dos n�meros positivos �: %d\n", media);
		
	}else if(ne == 7){
		printf("=====================================================\n");
		printf("|FA�A UM PROGRAMA QUE SOLICITE 2 N�MEROS INTEIROS   |\n");
		printf("|POSITIVOS AT� QUE O PRIMEIRO N�O SEJA DIVIS�VEL    |\n");
		printf("|PELO SEGUNDO. AO FINAL, EXIBA QUANTOS DELES ISSO   |\n");
		printf("|FOI POSS�VEL (USAR DO...WHILE).                    |\n");
		printf("=====================================================\n\n");
		
		int num1 = 0, num2 = 0;
		
		do{
			printf("Digite dois n�mero positivo: ");
			scanf("%d %d", &num1, &num2);
			
			if((num1/num2)%2 == 0){
				printf("O resultado da divis�o de %d/%d = %d\n", num1, num2, num1/num2);
			}
			
		}while((num1/num2)%2 == 0);
	}else if(ne == 8){
		printf("=====================================================\n");
		printf("|FA�A UM PROGRAMA QUE RECEBA 10 NUMEROS ARMAZENE-OS |\n");
		printf("|NUM VETOR E EXIBA ESTES N�MEROS NA ORDEM INVERSA.  |\n");
		printf("=====================================================\n\n");
		
		float vetor[10];
		
		for(int t = 0; t < 10; t++){
			printf("Digite o %d� N�mero: ", t + 1);
			scanf("%f", &vetor[t]);
		}
		
		for(int t = 9; t > -1; t--){
			printf("Valores digitados: %.1f\n", vetor[t]);
		}
		
	}else if(ne == 9){
		printf("=====================================================\n");
		printf("|FA�A UM PROGRAMA QUE RECEBA UM VERTOR DE 5 N�MEROS,|\n");
		printf("|COLOQUE-OS EM ORDEM CRESCENTE E EXIBA-OS.          |\n");
		printf("=====================================================\n\n");
		
		float num[5], aux;
		
		for(int t = 0; t < 5; t++){
			printf("Digite o %d� N�mero: ", t+1);
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
		
   		printf("Ordem crescente dos n�meros digitados s�o: %.1f, %.1f, %.1f, %.1f, %.1f.", num[0], num[1], num[2], num[3], num[4]);
   		
	}else if(ne == 10){
		printf("=====================================================\n");
		printf("|FA�A UM PROGRAMA QUE CRIE UMA MATRIZ DE 5 LINHAS E |\n");
		printf("|3 COLUNAS, ARMAZENE OS N�MEROS INTEIROS NESSA      |\n");
		printf("|MATRIZ E EXIBA ESTES N�MEROS.                      |\n");
		printf("=====================================================\n\n");
		
		int num[5][3];
		
		for(int t = 0; t < 5; t++){
			for(int u = 0; u < 3; u++){
				printf("Posi��o %d , %d. Digite um n�mero inteiro: ", t+1, u+1);
				scanf("%d", &num[t][u]);
			}
		}
		
		printf("Os N�meros digitados na ordem �: ");
		
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
		printf("|FA�A UM PROGRAMA QUE CRIE UMA MATRIZ 3X3, ARMAZENE |\n");
		printf("|OS N�MEROS INTEIROS NELA E, AO FINAL, CALCULE A    |\n");
		printf("|SOMA NA SUA DIAGONAL SECUND�RIA.                   |\n");
		printf("|                     EXEMPLO                       |\n"); 
		printf("|3 7 2                                              |\n");
		printf("|1 5 4    SOMA DIAGONAL SEGUND�RIA = 2 + 5 + 9 = 16 |\n");
		printf("|9 5 8                                              |\n");
		printf("=====================================================\n\n");
		
		int num[3][3];
		
		for(int t = 0; t < 3; t++){
			for(int u = 0; u < 3; u++){
				printf("Matriz posi��o %d %d. Digite um n�mero inteiro: ", t+1, u+1);
				scanf("%d", &num[t][u]);
			}
		}
		
		printf("\n----- MATRIZ -----\n");
		
		for(int t = 0; t < 3; t++){
			for(int u = 0; u < 3; u++){
				if(t == 1 && u == 2){
					printf("%d    ", num[t][u]);
					printf("SOMA DIAGONAL SEGUND�RIA : %d + %d + %d = %d\n", num[0][2], num[1][1], num[2][0], num[0][2] + num[1][1] + num[2][0]);
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
