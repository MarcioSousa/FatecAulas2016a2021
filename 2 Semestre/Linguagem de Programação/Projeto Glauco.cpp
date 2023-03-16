#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h> // Biblioteca necessário para usar o SETLOCALE()

//Cada contato possui um nome e telefone.
//typedef struct {
//  char nome[100];
//  int  telefone;
//} Contato;

typedef struct {
  	char nome[100];
  	char descricao[100];
  	float valorPago;
  	float valorVenda;
  	int qtde;
  
} Produto;
//Funcoes

void novoProduto(Produto *agenda, int *n, int *cap);
void exibeProduto(Produto *agenda, int n);
void apagaProduto (Produto *agenda, int *n); 

void salvarArquivo(Produto *produtos, int n);
Produto * abrirArquivo (int *n, int *cap);

int main(){
  //Ponteiro para estrutura. Vai ser o nosso vetor de 
  //estruturas dinamicas com os dados da agenda.
  Produto *agenda;
  int cap; //Capacidade do vetor (tamanho real do vetor).
  int n;   //Numero de contatos cadastrados (tamanho usado).
  int opc; //Opcao do menu selecionada.
 

  agenda = abrirArquivo(&n, &cap);
  
  do{
    //Exibe o menu de opcoes.
    printf("*** Menu ***\n");
    printf("1) Cadastrar produto.\n");
    printf("2) Exibir produto.\n");
    printf("3) Apagar.\n");
    printf("4) Sair.\n");
    //Le a opcao selecionada.
    scanf("%d",&opc);

	switch(opc){
	      case 1: novoProduto(agenda, &n, &cap); 	break;
	      case 2: exibeProduto(agenda, n); 		break; 
	      case 3: apagaProduto(agenda, &n); 		break;
	}
    
    //Enquanto nao for opcao de saida continua mostrando menu.
  }while(opc!=4); 

  salvarArquivo(agenda, n);

  //Libera a memoria alocada do vetor.
  free(agenda);
  
  return 0;
}

void salvarArquivo(Produto *agenda, int n){
  
   if(n>0){
    //Se existe algum contato cadastrado 
    //entao grava para o disco.

    //Abre arquivo em modo de gravacao ("w" = write).
    FILE *fp = fopen("produto.dat","w");

    //Grava o numero de contatos no inicio do arquivo.
    fwrite(&n, sizeof(int), 1, fp);
    
    //Grava os dados do vetor no arquivo.
    fwrite(agenda, sizeof(Produto), n, fp);
   
    //Fecha arquivo apos a gravacao.
    fclose(fp);
  }
  
}

Produto * abrirArquivo (int *n, int *cap){
 
  Produto *agenda;
 	     
  //Abrindo arquivo em modo de leitura ("r" = read).
  FILE *fp = fopen("produto.dat","r");
  
  //Se retorna NULL eh pq nao encontrou o arquivo.
  //Isso acontece na primeira vez que rodamos o programa.
  if(fp==NULL){
    *n = 0;    //Base de dados inicialmente vazia.
    *cap = 20; //Fixamos uma capacidade inicial (ex: 20).
   //Alocammos o vetor de estruturas de forma
    //dinamica conforme a capacidade.
    agenda = (Produto *)malloc(sizeof(Produto)* (*cap));
  }
  else{ //Arquivo encontrado, logo procedemos com a leitura.

    //Le o numero de registros.
    fread(n, sizeof(int), 1, fp);
    
    //A capacidade deve ser maior ou igual a "n" (ex: n*2).
    *cap = (*n) * 2; 

    //Alocammos o vetor de estruturas de forma
    //dinamica conforme a capacidade.
    agenda = (Produto *)malloc(sizeof(Produto)* (*cap));

    //Leitura dos dados dos registros do arquivo para o vetor.
    fread(agenda, sizeof(Produto), *n, fp);

    //Fecha arquivo apos leitura.
    fclose(fp);
  }
  	
  return agenda;	
}

void exibeProduto(Produto *agenda, int n){
    //Exibe todos contatos cadastrados.
    int i;
    
    for(i=0; i<n; i++){
	    printf("*** Produto %d ***\n",i+1);
        printf("Nome: %s\n",agenda[i].nome);
        printf("Descricao: %s\n", agenda[i].descricao);
        printf("Valor Pago: %s\n", agenda[i].valorPago);
        printf("Valor de Venda: %s\n", agenda[i].valorVenda);
    }
}

void apagaProduto (Produto *agenda, int *n){
	
	  char nome[100];
      int j, i;
      fflush(stdin);
      printf("Digite o nome do produto a ser removido: ");
      gets(nome);
      for(i=0; i < *n; i++){
             if (strcmp(agenda[i].nome, nome)==0){
             	for(j=i; j < *n; j++){
                   agenda[j] = agenda[j+1];
                 }
                (*n) --;
                i  = *n;
              }
      }
    
    
}

void novoProduto(Produto *agenda, int  *n, int *cap){

      if(*n==*cap){
		 //Capacidade esgotada, devemos aumentar o 
		 //vetor usando "realloc" (ex: dobrar capacidade).
	      *cap = *cap * 2;
          agenda = (Produto*)realloc(agenda, sizeof(Produto) * (*cap));
      }
      
      //Leitura dos dados.
      printf("Digite o nome: ");
      fflush(stdin);
      gets(agenda[*n].nome);
      printf("Digite a descrição: ");
      scanf("%d",&agenda[*n].descricao);
      
      //Incrementa numero de registros cadastrados.
	  (*n) ++;	
}
