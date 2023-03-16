#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

main(){
	setlocale(LC_ALL, "Portuguese");

	int ne;
	
	printf("================================================\n");
	printf("==== EXERCÍCIOS DE LINGUAGEM DE PROGRAMAÇÃO ====\n");
	printf("================================================\n\n");
	printf("EXEMPLOS DOS EXERCÍCIOS, DIGITE 0.\n");	
	printf("DIGITE O NÚMERO DO EXERCÍCIO(1 ao 9): ");
	scanf("%d", &ne);
	fflush(stdin);
	
	if(ne == 0){
		char palavra[15];
	
		printf("Digite uma frase: ");
		gets(palavra);
	
		printf("A frase digitada é: %s\n", palavra);
	
		for(int i=0; i < 15; i++){
			printf("Posicao %i = %c\t\n",i , palavra[i]);
		}
		
	}else if(ne == 1){
		printf("=====================================================\n");
		printf("|FAÇA UM PROGRAMA QUE RECEBA SEU NOME E EXIBA AS 4  |\n");
		printf("|PRIMEIRAS LETRAS.                                  |\n");
		printf("=====================================================\n\n");
				    
	    char nome[10];
		printf("Digite seu nome: ");
		gets(nome);
		
		printf("As quatro primeiras letras de seu nome é: ");
		
		for(int t = 0; t < 4; t++){
			if(t == 3){
				printf("%c.\n", nome[t]);
			}else{
				printf("%c", nome[t]);		
			}
		}
			
	}else if(ne == 2){
		printf("=====================================================\n");
		printf("|FAÇA UM PROGRAMA QUE RECEBA E ARMAZENE UMA FRASE   |\n");
		printf("|NUMA STRING DE TAM.20 E MOSTRE SOMENTE AS LETRAS   |\n");
		printf("|DAS POSIÇÕES ÍMPARES.                              |\n");
		printf("=====================================================\n\n");	
		
		char frase[20];
		int t = 0;
		
		printf("Digite uma frase de até 20 caracteres: ");
		gets(frase);
		
		printf("As posições ímpares da frase é: ");
		
		do{
			if(t%2 != 0){
				printf("%c ", frase[t]);
			}
			t++;
		}while(frase[t] != '\0');


	}else if(ne == 3){
		printf("=====================================================\n");
		printf("|FAÇA UM PROGRAMA QUE CRIE 2 STRINGS DE TAM. 10. O  |\n");
		printf("|USUÁRIO DEVERÁ RECEBER E ARMAZENAS ARACTERES NA    |\n");
		printf("|STRING1 E DEPOIS COPIÁ-LIS PARA A STRING2. AO      |\n");
		printf("|FINAL, EXIBIR O CONTEÚDO DA STRING2.               |\n");
		printf("=====================================================\n\n");	
		
		char string1[20];
		char string2[20];
		
		printf("Digite uma palavra de até 20 caracteres: ");
		gets(string1);
		
		strcpy(string2, string1);
		
		printf("%s", string2);		
		
	}else if(ne == 4){
		printf("=====================================================\n");
		printf("|CONTRUA UM PROGRAMA QUE LEIA UMA STRING E RETORNE O|\n");
		printf("|NÚMERO DE CARACTERES QUE A MESMA POSSUI.           |\n");
		printf("=====================================================\n\n");
		
		char frase[20];
		int tamanho;
		
		printf("Digite uma string de até 20 caracteres: ");
		gets(frase);
		
		tamanho = strlen(frase);
		
		printf("O tamanho de string é: %d\n", tamanho);

	}else if(ne == 5){
		printf("=====================================================\n");
		printf("|CONTRUA  UM PROGRAMA QUE RECEBA 2 STRINGS (STRING1 |\n");
		printf("|E STRING2) E UM NÚMERO INTEIRO 'N' E COPIE OS 'N'  |\n");
		printf("|ÚLTIMOS CARACTERES DE STRING1 EM STRING2. PS: USE A|\n");
		printf("|FUNÇÃO STRNCPY().                                  |\n");
		printf("=====================================================\n\n");
	
		char string1[20];
		char string2[20];
		int qtdecaracteres, qtdeTotal, qtderetorno;
		
		printf("Digite a primeira string de até 20 caracteres: ");
		gets(string1);
		
		printf("Digite um número de 0 até 20: ");
		scanf("%d", &qtdecaracteres);
		
		qtdeTotal = strlen(string1);
		
		qtderetorno = qtdeTotal - qtdecaracteres;
		
		strncpy(string2, &string1[qtderetorno], qtdecaracteres);

		printf("String1: %s;\nString2: %s.\n", string1, string2);
	}else if(ne == 6){
		printf("=====================================================\n");
		printf("|RECEBER DO TECLADO UMA MENSAGEM E IMPRIMIR QUANTAS |\n");
		printf("|LETRAS A, E, I, O, U TEM ESTA MENSAGEM. CONSIDERAR |\n");
		printf("|MINÚSCULA E MAIÚSCULA. A FUNÇÃO QUE ACESSA LETRA   |\n");
		printf("|POR LETRA DE UMA PALAVRA É STRLEN (VARIÁVEL,X).(X É|\n");
		printf("|A POSIÇÃO DA LETRA NA FRASE).                      |\n");
		printf("=====================================================\n\n");
		
		char mensagem[100];
		int qtdecaracteres;
		int qtdea = 0, qtdee = 0, qtdei = 0, qtdeo = 0, qtdeu = 0;
		
		printf("Digite uma mensagem de até 100 caracteres: ");
		gets(mensagem);
		
		qtdecaracteres = strlen(mensagem);
		
		for(int t = 0; t < qtdecaracteres; t++){
			if(mensagem[t] == 'A' || mensagem[t] == 'a'){
				qtdea++;
			}else if(mensagem[t] == 'E' || mensagem[t] == 'e'){
				qtdee++;
			}else if(mensagem[t] == 'I' || mensagem[t] == 'i'){
				qtdei++;
			}else if(mensagem[t] == 'O' || mensagem[t] == 'o'){
				qtdeo++;
			}else if(mensagem[t] == 'U' || mensagem[t] == 'u'){
				qtdeu++;
			}
		}
		
		printf("Qtde de letras 'A': %d\n", qtdea);
		printf("Qtde de letras 'E': %d\n", qtdee);
		printf("Qtde de letras 'I': %d\n", qtdei);
		printf("Qtde de letras 'O': %d\n", qtdeo);
		printf("Qtde de letras 'U': %d\n", qtdeu);
		printf("NÃO É CONTADO AS VOGAIS COM ACENTO\n");
		
	}else if(ne == 7){
		printf("=====================================================\n");
		printf("|RECEBER DO TECLADO A SIGLA DO ESTADO DE UMA PESSOA |\n");
		printf("|E IMPRIMIR UMA DAS SEGUINTES MENSAGEM:             |\n");
		printf("|                      CARIOCA;                     |\n");
		printf("|                      PAULISTA;                    |\n");
		printf("|                      MINEIRO;                     |\n");
		printf("|                   OUTROS ESTADOS.                 |\n");
		printf("=====================================================\n\n");
		
		char estado[2];
		
		printf("Digite a sigla de um estado: ");
		gets(estado);
		
		if(strcmp(estado, "RJ") == 0){
			printf("CARIOCA.\n'");
		}else if(strcmp(estado, "SP") == 0){
			printf("PAULISTA.\n");
		}else if(strcmp(estado, "MG") == 0){
			printf("MINEIRO.\n");
		}else{
			printf("OUTROS ESTADOS.\n");
		}
		
	}else if(ne == 8){
		printf("=====================================================\n");
		printf("|CRIE UM PROGRAMA QUE RECEBE UMA STRING E UM        |\n");
		printf("|CARACTER, E RETORNE O NÚMERO DE VEZES QUE ESSE     |\n");
		printf("|CARACTER APARECEU NA STRING.                       |\n");
		printf("=====================================================\n\n");
		
		char string1[30], car;
		int cont =0;
		
		printf("Digite uma string: ");
		gets(string1);
		
		printf("Digite um caracter: ");
		scanf("%c", &car);
		
		for(int t = 0; t < strlen(string1); t++){
			if(string1[t] == car){
				cont ++;
			}
		}

		printf("O caracter %c apareceu %i vezes.\n", car, cont);
		
	}else if(ne == 9){
		printf("=====================================================\n");
		printf("|CRIE UM PROGRAMA QUE VERIFIQUE SE UMA STRING É OU  |\n");
		printf("|NÃO UM PALÍNDROMO (OU SEJA, SE INVERSO DA STRING É |\n");
		printf("|IGUAL A ELA).                                      |\n");
		printf("=====================================================\n\n");
		
		char string1[100], invertido[100];
		int f = 0;
		
		printf("Digite uma string de até 20 caracteres: ");
		gets(string1);
		
		for(int t = strlen(string1)-1; t >= 0; t--){
			invertido[f] = string1[t];
			f++;
		}
		
		invertido[f] = '\0';
		
		if(strcmp(string1, invertido) == 0){
			printf("Eles são um palíndromo, pois\n%s é o inverso de %s\n", invertido, string1);
		}else{
			printf("Não é um palíndromo!\n");
		}
		
		printf("A string é %s, invertida fica %s\n", string1, invertido);

	}else{
		printf("Dados inválidos.\n");
	}
}
