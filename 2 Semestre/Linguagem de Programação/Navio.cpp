#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Entregar até dia 29/03.
//======== Classes separadas =======
int carregaPorto();
int organizarPesos();
int carregarNavio();
int limpandoVetores();

//========Variáveis, Matrizes e Vetores
double pesoC[201];
double pesoN[4][16];
int qtdeCNavio;
int qtdeTotal;

int main(){
	setlocale(LC_ALL,"Portuguese");
	
	do{
		carregaPorto();
    	organizarPesos();
    	carregarNavio();
    	printf("Navio Carregado!\n===================================\n");
    	limpandoVetores();
	} while ((pesoC[0] != 0) || (pesoN[0][0] != 0));

    return 0;
}

int carregaValores(){
	peso[0][0] = 1;
	peso[0][1] = 5;
	peso[0][2] = 9;
	peso[0][3] = 3;
	peso[0][4] = 10;
	peso[0][5] = 14;
	peso[0][6] = 9;
	peso[0][7] = 8;
	peso[0][8] = 3;
	peso[0][9] = 7;
	peso[0][10] = 9;
	peso[0][11] = 10;
	peso[0][12] = 15;
	peso[0][13] = 9;
	peso[0][14] = 5;
	peso[0][15] = 5;
	
	peso[1][0] = 8;
	pes1[1][1] = 10;
	peso[1][2] = 15;
	peso[1][3] = 2;
	peso[1][4] = 1;
	peso[1][5] = 4;
	peso[1][6] = 8;
	peso[1][7] = 8;
	peso[1][8] = 3;
	peso[1][9] = 7;
	peso[1][10] = 10;
	peso[1][11] = 3;
	peso[1][12] = 7;
	peso[1][13] = 7;
	peso[1][14] = 8;
	peso[1][15] = 10;
	
	peso[2][0] = 10;
	peso[2][1] = 5;
	peso[2][2] = 9;
	peso[2][3] = 9;
	peso[2][4] = 11;
	peso[2][5] = 11;
	peso[2][6] = 9;
	peso[2][7] = 8;
	peso[2][8] = 3;
	peso[2][9] = 7;
	peso[2][10] = 10;
	peso[2][11] = 7;
	peso[2][12] = 7;
	peso[2][13] = 7;
	peso[2][14] = 9;
	peso[2][15] = 5;

	peso[3][0] = 1;
	peso[3][1] = 5;
	peso[3][2] = 3;
	peso[3][3] = 3;
	peso[3][4] = 1;
	peso[3][5] = 1;
	peso[3][6] = 10;
	peso[3][7] = 9;
	peso[3][8] = 7;
	peso[3][9] = 9;
	peso[3][10] = 10;
	peso[3][11] = 1;
	peso[3][12] = 1;
	peso[3][13] = 15;
	peso[3][14] = 3;
	peso[3][15] = 8;
	
	
}

int carregaPorto(){
	int qtde, total = 0, cont =0;
	double peso = 0;

	do{
		printf("Digite a quantidade de Containers que chegou ao porto: ");
		scanf("%i", &qtde);
		
		fflush(stdin);
		
		if((qtde + qtdeTotal) > 200){
			printf("No porto não pode ter acima de 200 Containers.\nTotal de Containers no momento é de: %d\n", qtdeTotal);
			printf("-------------------------------------------------------------\n");
		}

	}while((qtde + qtdeTotal) > 200);
	
	qtdeTotal = qtdeTotal + qtde;
	
	//um laço para aumentar a qtde que precisar por no navio
	//Acrescenta um em T e um em qtde, assim ficaria igualado no final 
	//de cada novo estoque.	
	for(int a = 0; a < qtde; a++){
		if(pesoC[a] != 0){
			qtde++;
			cont++;
		}
	}
	
	for (int t = 0; t < (qtde - cont); t++){
		printf("Digite o peso (em Toneladas) do %dº Container: ", t+1);
		scanf("%lf", &peso);
		fflush(stdin);
	
		if((peso >= 1) && (peso <= 15)){
			pesoC[t + cont] = peso;

		} else {
			printf("Peso inapropriado, tente novamente.\n\n");
			t = t - 1;
		}
	}
	
}

int organizarPesos(){
	double aux;
	
	for(int t = 0; t < 200; t++){
		if(pesoC[t] <  pesoC[t+1]){
			aux = pesoC[t];
			pesoC[t] = pesoC[t+1];
			pesoC[t+1] = aux;
			
			if(pesoC[t] == 0){
				break;
			}
			
			t = -1;
		}
	}
}

int carregarNavio(){
	int cont = 0;
	
	for(int p =0; p<1; p++){
        printf("Digite a quantidade de Containers que deseja carregar no Navio: ");
    	scanf("%i", &qtdeCNavio); 	
    	
    	fflush(stdin);
    	
    	if((qtdeCNavio >= 64) || (qtdeCNavio > qtdeTotal)){
    		printf("Carregue o Navio com 64 Containners ou Menos e\nDigite um valor menor ou igual a qtde de container do porto.\nTotal de Containers no Porto: %i\n", qtdeTotal);
    		p--;
		}
    }
    
	qtdeTotal = qtdeTotal - qtdeCNavio;
}

int limpandoVetores(){
	int a = 0, b = 0; 

	//=======Limpando vetores dos pesos dos containers
	for(int t =0; t < qtdeCNavio; t++){
		pesoC[t] = 0;
	}
	
	organizarPesos();
	//=======Limpando vetores do navio
	for (int t = 0; t < 4; t++){
		for(int v = 0; v < 16; v++){
			pesoN[t][v] = 0;
		}
	}
	
}

