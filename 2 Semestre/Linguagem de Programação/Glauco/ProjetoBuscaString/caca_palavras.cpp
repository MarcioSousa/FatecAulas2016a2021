#include <stdio.h>
#include <string.h>
 
 //quebrando em funções
int armazenaLetrasMatriz();
int armazenaBuscaPalavrasMatriz();
int organizaCadaPalavra();
//int verificaBuscaPalavras();

 // variáveis
int i, j, k, n, p, t; //Contadores
int encontrada; // SIM = 1. NÃO = 0.
char matriz[80][80], palavra[80][80];

int main()
{
    printf("BEM-VINDO AO JOGO DE CACA-PALAVRAS\nDIGITE O TAMANHO DA MATRIZ: ");
    scanf("%d", &n);
 	//{
 	armazenaLetrasMatriz();
	armazenaBuscaPalavrasMatriz();
	printf("RESULTADO:\n");
	organizaCadaPalavra();
	//verificaBuscaPalavras();
	//}
}

int armazenaLetrasMatriz(){
	printf("DIGITE PALAVRAS OU FRASES PARA A MATRIZ:\n\n");
    for (i = 0; i < n; i++) scanf("%s", matriz[i]); //Armazena as letras na matriz.
    printf("\n");
}
int armazenaBuscaPalavrasMatriz(){
	printf("DIGITE O NUMERO DE PALAVRAS DESEJADO: ");
    scanf("%d", &p);
 
    printf("DIGITE AS PALAVRAS:\n");
    // REPTITA ATÉ Q A PALAVRA DA BUSCA DIGITADA SEJA DIFERENTE DE 0
 	//do{
 	for (i = 0; i < p; i++) {
 		scanf("%s", palavra[i]); //Armazena as palavras que serão buscadas na matriz.
    }
	//}while(p != 0);
	//if(palavra[i] == 0)	printf("Encerrado.");
    printf("\n");
}

int organizaCadaPalavra(){
	for (k = 0; k < p; k++) //Para cada palavra
    {
        //Inicialmente a palavra é considerada Não-Encontrada.
        encontrada = 0;
 
        for (i = 0; i < n; i++) //Para cada linha da matriz
        {
            for (j = 0; j < n; j++) //Para cada coluna da matriz
            {
                if (palavra[k][0] == matriz[i][j]) //Se a primeira letra for encontrada
                {
                    if (palavra[k][1] == matriz[i - 1][j]) //Se a segunda letra for encontrada acima (Norte)
                    {
                        encontrada = 1;
 
                        for (t = 0; t < strlen(palavra[k]); t++)
                            if (palavra[k][t] != matriz[i - t][j])
                                encontrada = 0;
 
                        if (encontrada)
                            break;
                    }
 
                    if (palavra[k][1] == matriz[i + 1][j]) //Se a segunda letra for encontrada abaixo (Sul)
                    {
                        encontrada = 1;
 
                        for (t = 0; t < strlen(palavra[k]); t++)
                            if (palavra[k][t] != matriz[i + t][j])
                                encontrada = 0;
 
                        if (encontrada)
                            break;
                    }
 
                    if (palavra[k][1] == matriz[i][j + 1]) //Se a segunda letra for encontrada a direita (Leste)
                    {
                        encontrada = 1;
 
                        for (t = 0; t < strlen(palavra[k]); t++)
                            if (palavra[k][t] != matriz[i][j + t])
                                encontrada = 0;
 
                        if (encontrada)
                            break;
                    }
 
                    if (palavra[k][1] == matriz[i][j - 1]) //Se a segunda letra for encontrada a esquerda (Oeste)
                    {
                        encontrada = 1;
 
                        for (t = 0; t < strlen(palavra[k]); t++)
                            if (palavra[k][t] != matriz[i][j - t])
                                encontrada = 0;
 
                        if (encontrada)
                            break;
                    }
 
                    if (palavra[k][1] == matriz[i - 1][j + 1]) //Se a segunda letra for encontrada acima-direita (Nordeste)
                    {
                        encontrada = 1;
 
                        for (t = 0; t < strlen(palavra[k]); t++)
                            if (palavra[k][t] != matriz[i - t][j + t])
                                encontrada = 0;
 
                        if (encontrada)
                            break;
                    }
 
                    if (palavra[k][1] == matriz[i - 1][j - 1]) //Se a segunda letra for encontrada acima-esquerda (Noroeste)
                    {
                        encontrada = 1;
 
                        for (t = 0; t < strlen(palavra[k]); t++)
                            if (palavra[k][t] != matriz[i - t][j - t])
                                encontrada = 0;
 
                        if (encontrada)
                            break;
                    }
 
                    if (palavra[k][1] == matriz[i + 1][j + 1]) //Se a segunda letra for encontrada abaixo-direita (Sudeste)
                    {
                        encontrada = 1;
 
                        for (t = 0; t < strlen(palavra[k]); t++)
                            if (palavra[k][t] != matriz[i + t][j + t])
                                encontrada = 0;
 
                        if (encontrada)
                            break;
                    }
 
                    if (palavra[k][1] == matriz[i + 1][j - 1]) //Se a segunda letra for encontrada abaixo-esquerda (Sudoeste)
                    {
                        encontrada = 1;
 
                        for (t = 0; t < strlen(palavra[k]); t++)
                            if (palavra[k][t] != matriz[i + t][j - t])
                                encontrada = 0;
 
                        if (encontrada)
                            break;
                    }
                }
            }
 
            if (encontrada)
                break;
        }
 
        //Depois da verificação ele diz se a palavra foi encontrada ou não, então passa para a verificação da próxima palavra.
	    if (encontrada)
	        printf("%s - PALAVRA ENCONTRADA\n", palavra[k]);
	    else
	        printf("%s - PALAVRA NAO ENCONTRADA\n", palavra[k]);
	}
}
//int verificaBuscaPalavras(){
//	
//}
