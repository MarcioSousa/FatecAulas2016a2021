#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define TAM 5

int F_SOMA(int V_IDADE[], int cont);
int V_VALORVETOR(int vet[], int valor);

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
	
	int ne;
	
	printf("================================================\n");
	printf("==== EXERC�CIOS DE LINGUAGEM DE PROGRAMA��O ====\n");
	printf("====== PASSANDO UM VETOR COM PAR�METRO =========\n");
	printf("=============== DE UMA FUN��O ==================\n");
	printf("================================================\n\n");
	printf("EXEMPLOS DOS EXERC�CIOS, DIGITE 0.\n");	
	printf("DIGITE O N�MERO DO EXERC�CIO(1 ao 9): ");
	scanf("%d", &ne);
	fflush(stdin);
	
	if(ne == 0){
		printf("=====================================================\n");
		printf("|FA�A UM PROGRAMA QUE CRIE E ARMAZENE A IDADE DE 5   |\n");
		printf("|PESSOAS. CRIE UMA FUN��O QUE CALCULE A SOMA DESSAS  |\n");
		printf("|IDADES.                                             |\n");
		printf("=====================================================\n\n");
		
		int VET[TAM], soma = 0;
		
		for(int t = 0; t < TAM; t++){
			printf("Informe a Idade: ");
			scanf("%d", &VET[t]);
		}
		
		soma = F_SOMA(VET, TAM);
		
		printf("A soma das idades �: %d", soma);
		
	}else if(ne == 1){
		printf("=====================================================\n");
		printf("|FA�A UM PROGRAMA QUE CRIE E ARMAZENE UM VETOR DE 10 \n");
		printf("|POSI��ES E RECEBA UM VALOR NUMERICO 'X'. CRIE UMA   \n");
		printf("|FUN��O QUE VERIFIQUE SE O VALOR 'X' EXISTE NO VETOR \n");
		printf("|OU N�O. SE SIM, INDIQUE EM QUE POSI��O.             \n");
		printf("=====================================================\n\n");
		
		int vet[10], valor = 0, posicao = 0;
		
		for(int t = 0; t < 10; t++){
			printf("Digite o %i� n�mero: ", t + 1);
			scanf("%d", &vet[t]);
		}
		
		printf("Digite um n�mero para verificar se existe: ");
		scanf("%d", &valor);
		
		posicao = V_VALORVETOR(vet, valor);
		
		if(V_VALORVETOR(vet, valor) != 0){
			printf("O valor %d existe e est� na posi��o %i\n", valor, posicao);
		}else{
			printf("O valor %d n�o existe.\n", valor);
		}
		
	}else if(ne == 2){
		printf("=====================================================\n");
		printf("|FA�A UM PROGRAMA QUE RECEBA UMA STRING. CRIE UMA    \n");
		printf("|FUN��O QUE VERIFIQUE QUE � A VOGAL QUE MAIS APARECE \n");
		printf("|NA STRING INFORMADA.                                \n");
		printf("=====================================================\n\n");
		
		

	}

}

//EXEMPLO
int F_SOMA(int V_IDADE[], int cont){
	int s = 0;
	
	for(int t = 0; t < cont; t++){
		s = s + V_IDADE[t];
	}
	return s;
}
//======= EXERC�CIO 01 ======
int V_VALORVETOR(int vet[], int valor){
	for(int t = 0; t < 10; t++){
		if(valor == vet[t]){
			return t;
		}
	}
	return 0;
}




