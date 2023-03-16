#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h> // Biblioteca necessário para usar o SETLOCALE()

typedef struct {
  	char nome[100];
  	char descricao[100];
  	float valorPago;
  	float valorVenda;
  	int qtde;
  
} Produto;

typedef struct {
  	char nome[100];
  	char cpf[100];
  	int cep;
  	char endereco[100];
  	char email[100];
  	int telefone;
  
} Cliente;

typedef struct {
  	char nomeCli[100];
  	char nomePro[100];
  	int qtde;
  	float precoUnit;
  	float precoTotal;
} Venda;

int Funcao_Menu();  //protótipo da função 
int Funcao_MenuProduto();
int Funcao_MenuCliente();
int Funcao_MenuVenda();

//Funcoes do produto
void novoProduto (Produto *listaProduto, int *numProdutosCad, int *cap);
void exibeProdutos(Produto *listaProduto, int numProdutosCad);
void apagaProduto (Produto *listaProduto, int *numProdutosCad);

void salvarArquivoProduto(Produto *Produtos, int numProdutosCad);
Produto * abrirArquivoProduto (int *numProdutosCad, int *cap);

//Funções do cliente
void novoCliente (Cliente *listaCliente, int *numClienteCad, int *cap);
void exibeClientes(Cliente *listaCliente, int numClienteCad);
void apagaCliente (Cliente *listaCliente, int *numClienteCad);

void salvarArquivoCliente(Cliente *Clientes, int numClienteCad);
Cliente * abrirArquivoCliente (int *numClienteCad, int *cap);

//Funções do venda
void novaVenda(Venda *listaVenda, int *numVendaCad, int *cap);
void exibeVendas(Venda *listaVenda, int numVendaCad);
void apagaVenda (Venda *listaVenda, int *numVendaCad);

void salvarArquivoVenda(Venda *Vendas, int numVendaCad);
Venda * abrirArquivoVenda (int *numVendaCad, int *cap);

int main(){
	setlocale(LC_ALL, "Portuguese");      // Instrução usada para configurar o idioma Português
	//Ponteiro para estrutura. Vai ser o nosso vetor de 
  	//estruturas dinamicas com os dados da agenda.
  	Produto *listaProduto;
  	Cliente *listaCliente;
  	Venda *listaVenda;
  	
  	int capProduto;       //Capacidade do vetor de produto (tamanho real do vetor).
  	int capCliente; 	  //Capacidade do vetor de cliente (tamanho real do vetor).
  	int capVenda; 		  //Capacidade do vetor de venda (tamanho real do vetor).
  	int numProdutosCad;   //Numero de produtos cadastrados (tamanho usado).
  	int numClienteCad;    //Numero de clientes cadastrados (tamanho usado).
  	int numVendaCad;	  //Numero de vendas cadastrados (tamanho usado).
  	int opc; //Opcao do menu selecionada.
 	int opcProduto, opcCliente, opcVenda;

  	listaProduto = abrirArquivoProduto(&numProdutosCad, &capProduto);
  	listaCliente = abrirArquivoCliente(&numClienteCad, &capCliente);
  
  	do{
  		opc = Funcao_Menu();
  		
  		switch(opc){
  			case 1:
  				system("cls");
  				do{
  					opcProduto = Funcao_MenuProduto();
  					switch(opcProduto){
  						case 1:
  							system("cls");
  							novoProduto (listaProduto, &numProdutosCad, &capProduto); break;
  						case 2:
  							system("cls");
  							exibeProdutos(listaProduto, numProdutosCad); break;
  						case 3:
  							system("cls");
  							apagaProduto (listaProduto, &numProdutosCad); break;
  						default:
  							system("cls");
					}
				}while(opcProduto!=4);
			break;
			case 2:
				system("cls");
				do{
					opcCliente = Funcao_MenuCliente();
					switch(opcCliente){
  						case 1:
  							system("cls");
  							novoCliente (listaCliente, &numClienteCad, &capCliente); break;
  						case 2:
  							system("cls");
  							exibeClientes(listaCliente, numClienteCad); break;
  						case 3:
  							system("cls");
  							apagaCliente (listaCliente, &numClienteCad); break;
  						default:
  							system("cls");
					}
				}while(opcCliente!=4);
			break;
			case 3:
				system("cls");
				do{
					opcVenda = Funcao_MenuVenda();
					switch(opcVenda){
  						case 1:
  							system("cls");
  							novaVenda (listaVenda, &numVendaCad, &capVenda); break;
  						case 2:
  							system("cls");
  							printf("exibeVenda\n");/*exibeProdutos(lista, n);*/ break;
  						case 3:
  							system("cls");
  							printf("apagaVenda\n");/*apagaProduto (lista, &n);*/ break;
  						default:
  							system("cls");
					}
				}while(opcVenda!=4);
			break;
		}
    //Enquanto nao for opcao de saida continua mostrando menu.
  	}while(opc!=4); 

  	salvarArquivoProduto(listaProduto, numProdutosCad);
  	salvarArquivoCliente(listaCliente, numClienteCad);

  	//Libera a memoria alocada do vetor.
  	free(listaProduto);
  	free(listaCliente);
  
  	return 0;
}
/******************************* funções do menu e submenus *******************************/
int Funcao_Menu(){
	//Exibe o menu de opcoes.
	int opc;
	
   	printf("*** Menu ***\n");
    printf("1) Produto.\n");
    printf("2) Cliente.\n");
    printf("3) Venda.\n");
    printf("4) Sair.\n");
	//Le a opcao selecionada.
	scanf("%d",&opc);
	
	return opc;
}
int Funcao_MenuProduto(){
	int opcProduto;
	
	printf("*** Menu Produto ***\n");
	printf("1) Cadastrar.\n");
	printf("2) Exibir.\n");
	printf("3) Apagar.\n");
	printf("4) Voltar.\n");
	//Le a opcao selecionada.
	scanf("%d",&opcProduto);
	
	return opcProduto;
}
int Funcao_MenuCliente(){
	int opcCliente;
	
	printf("*** Menu Cliente ***\n");
	printf("1) Cadastrar.\n");
	printf("2) Exibir.\n");
	printf("3) Apagar.\n");
	printf("4) Voltar.\n");
	//Le a opcao selecionada.
	scanf("%d",&opcCliente);
	
	return opcCliente;
}
int Funcao_MenuVenda(){
	int opcVenda;
	
	printf("*** Menu Venda ***\n");
	printf("1) Cadastrar.\n");
	printf("2) Exibir.\n");
	printf("3) Apagar.\n");
	printf("4) Voltar.\n");
	//Le a opcao selecionada.
	scanf("%d",&opcVenda);
	
	return opcVenda;
}
//===================================================================================================================================
/***************************************** funções salvar, exibir, remover o(s) Produto(s) *****************************************/
//===================================================================================================================================
void salvarArquivoProduto(Produto *listaProduto, int numProdutosCad){
  
    if(numProdutosCad>0){
	    //Se existe algum produto cadastrado 
	    //entao grava para o disco.
	
	    //Abre arquivo em modo de gravacao ("w" = write).
	    FILE *fp = fopen("Produto.dat","w");
	
	    //Grava o numero de produtos no inicio do arquivo.
	    fwrite(&numProdutosCad, sizeof(int), 1, fp);
	    
	    //Grava os dados do vetor no arquivo.
	    fwrite(listaProduto, sizeof(Produto), numProdutosCad, fp);
	   
	    //Fecha arquivo apos a gravacao.
	    fclose(fp);
    }
}

/**********************************************************
Funcao abre arquivo
*/
Produto * abrirArquivoProduto (int *numProdutosCad, int *capProduto){
 
  	Produto *listaProduto;
 	     
  	//Abrindo arquivo em modo de leitura ("r" = read).
  	FILE *fp = fopen("Produto.dat","r");
  
  
  	//Se retorna NULL eh pq nao encontrou o arquivo.
  	//Isso acontece na primeira vez que rodamos o programa.
  	if(fp==NULL){
    	*numProdutosCad = 0;    //Base de dados inicialmente vazia.
    	*capProduto = 20; //Fixamos uma capacidade inicial (ex: 20).
   		//Alocammos o vetor de estruturas de forma
    	//dinamica conforme a capacidade.
    	listaProduto = (Produto *)malloc(sizeof(Produto)* (*capProduto));
 	}
  	else{ //Arquivo encontrado, logo procedemos com a leitura.

    //Le o numero de registros.
    fread(numProdutosCad, sizeof(int), 1, fp);
    
    //A capacidade deve ser maior ou igual a "n" (ex: n*2).
    *capProduto = (*numProdutosCad) * 2; 

    //Alocammos o vetor de estruturas de forma
    //dinamica conforme a capacidade.
    listaProduto = (Produto *)malloc(sizeof(Produto)* (*capProduto));

    //Leitura dos dados dos registros do arquivo para o vetor.
    fread(listaProduto, sizeof(Produto), *numProdutosCad, fp);

    //Fecha arquivo apos leitura.
    fclose(fp);
  	}
  	
  	return listaProduto;	
}

/**********************************************************
Funcao exibe todos os produtos
*/
void exibeProdutos(Produto *listaProduto, int numProdutosCad){
    //Exibe todos os produtos cadastrados.
    printf("*** Produto(s) salvo(s) ***\n\n");
    int i, c = 0;
    
    for(i=0; i<numProdutosCad; i++){
	    printf("*** Produto %d ***\n",i+1);
        printf("Nome: %s\n",listaProduto[i].nome);
	    printf("Descrição: %s\n",listaProduto[i].descricao);
	    printf("Valor pago: %.2f\n",listaProduto[i].valorPago);
	    printf("Valor venda: %.2f\n",listaProduto[i].valorVenda);
	    printf("Quantidade: %d\n",listaProduto[i].qtde);
	    c = 1;
    }
    if(c == 0){
    	printf("Não tem nenhum produto cadastrado.\n");
	}
}

/**********************************************************
Funcao apaga produto
*/
void apagaProduto (Produto *listaProduto, int *numProdutosCad){
	printf("*** Remover Produto ***\n\n");
	char nome[100];
    int j, i;
    fflush(stdin);
    printf("Digite o nome a ser removido: ");
    gets(nome);
    for(i=0; i < *numProdutosCad; i++){
        if (strcmp(listaProduto[i].nome, nome)==0){
            for(j=i; j < *numProdutosCad; j++){
                listaProduto[j] = listaProduto[j+1];
            }
        	(*numProdutosCad) --;
        	i  = *numProdutosCad;
        	printf("Produto removido com sucesso!\n\n");
        	return;
        }
    }
    printf("Produto não encontrado, erro ao remover o produto!\n\n");
    return;
}
/**********************************************************
Funcao cadastra novo produto
*/
void novoProduto(Produto *listaProduto, int  *numProdutosCad, int *capProduto){
	printf("*** Novo Produto ***\n\n");
    if(*numProdutosCad==*capProduto){
		//Capacidade esgotada, devemos aumentar o 
		//vetor usando "realloc" (ex: dobrar capacidade).
	    *capProduto = *capProduto * 2;
        listaProduto = (Produto*)realloc(listaProduto, sizeof(Produto) * (*capProduto));
    }
      
    //Leitura dos dados.
    printf("Digite o nome: ");
    fflush(stdin);
    gets(listaProduto[*numProdutosCad].nome);
    printf("Digite a descrição do produto: ");
    fflush(stdin);
    gets(listaProduto[*numProdutosCad].descricao);
    printf("Digite o valor pago: ");
    scanf("%f",&listaProduto[*numProdutosCad].valorPago);
	printf("Digite o valor da venda: ");
    scanf("%f",&listaProduto[*numProdutosCad].valorVenda);
    printf("Digite a quantidade: ");
    scanf("%d",&listaProduto[*numProdutosCad].qtde);
      //Incrementa numero de registros cadastrados.
	(*numProdutosCad) ++;
	printf("Produto salvo com sucesso!\n\n");
}
//===================================================================================================================================
/***************************************** funções salvar, exibir, remover o(s) Cliente(s) *****************************************/
//===================================================================================================================================
void salvarArquivoCliente(Cliente *listaCliente, int numClienteCad){
  
    if(numClienteCad>0){
	    //Se existe algum cliente cadastrado 
	    //entao grava para o disco.
	
	    //Abre arquivo em modo de gravacao ("w" = write).
	    FILE *fp = fopen("Cliente.dat","w");
	
	    //Grava o numero de produtos no inicio do arquivo.
	    fwrite(&numClienteCad, sizeof(int), 1, fp);
	    
	    //Grava os dados do vetor no arquivo.
	    fwrite(listaCliente, sizeof(Cliente), numClienteCad, fp);
	   
	    //Fecha arquivo apos a gravacao.
	    fclose(fp);
    }
}

/**********************************************************
Funcao abre arquivo
*/
Cliente * abrirArquivoCliente (int *numClienteCad, int *capCliente){
 
  	Cliente *listaCliente;
 	     
  	//Abrindo arquivo em modo de leitura ("r" = read).
  	FILE *fp = fopen("Cliente.dat","r");
  
  
  	//Se retorna NULL eh pq nao encontrou o arquivo.
  	//Isso acontece na primeira vez que rodamos o programa.
  	if(fp==NULL){
    	*numClienteCad = 0;    //Base de dados inicialmente vazia.
    	*capCliente = 20; //Fixamos uma capacidade inicial (ex: 20).
   		//Alocammos o vetor de estruturas de forma
    	//dinamica conforme a capacidade.
    	listaCliente = (Cliente *)malloc(sizeof(Cliente)* (*capCliente));
 	}
  	else{ //Arquivo encontrado, logo procedemos com a leitura.

    //Le o numero de registros.
    fread(numClienteCad, sizeof(int), 1, fp);
    
    //A capacidade deve ser maior ou igual a "n" (ex: n*2).
    *capCliente = (*numClienteCad) * 2; 

    //Alocammos o vetor de estruturas de forma
    //dinamica conforme a capacidade.
    listaCliente = (Cliente *)malloc(sizeof(Cliente)* (*capCliente));

    //Leitura dos dados dos registros do arquivo para o vetor.
    fread(listaCliente, sizeof(Cliente), *numClienteCad, fp);

    //Fecha arquivo apos leitura.
    fclose(fp);
  	}
  	
  	return listaCliente;	
}

/**********************************************************
Funcao exibe todos os clientes
*/
void exibeClientes(Cliente *listaCliente, int numClienteCad){
    //Exibe todos os produtos cadastrados.
    printf("*** Cliente(s) salvo(s) ***\n\n");
    int i, c = 0;
    
    for(i=0; i<numClienteCad; i++){
	    printf("*** Cliente %d ***\n",i+1);
        printf("Nome: %s\n",listaCliente[i].nome);
        printf("CPF: %s\n",listaCliente[i].cpf);
	    printf("CEP: %d\n",listaCliente[i].cep);
	    printf("Endereço: %s\n",listaCliente[i].endereco);
	    printf("E-mail: %s\n",listaCliente[i].email);
	    printf("CEP: %d\n",listaCliente[i].telefone);
	    c = 1;
    }
    if(c == 0){
    	printf("Não tem nenhum cliente cadastrado.\n");
	}
}

/**********************************************************
Funcao apaga cliente
*/
void apagaCliente (Cliente *listaCliente, int *numClienteCad){
	printf("*** Remover Cliente ***\n\n");
	char nome[100];
    int j, i;
    fflush(stdin);
    printf("Digite o nome a ser removido: ");
    gets(nome);
    for(i=0; i < *numClienteCad; i++){
        if (strcmp(listaCliente[i].nome, nome)==0){
            for(j=i; j < *numClienteCad; j++){
                listaCliente[j] = listaCliente[j+1];
            }
        	(*numClienteCad) --;
        	i  = *numClienteCad;
        	printf("Cliente removido com sucesso!\n\n");
        	return;
        } 

    }
     
	printf("Cliente não encontrado, erro ao remover o Cliente!\n");
	return;
}
/**********************************************************
Funcao cadastra novo produto
*/
void novoCliente(Cliente *listaCliente, int  *numClienteCad, int *capCliente){
	printf("*** Novo Cliente ***\n\n");
    if(*numClienteCad==*capCliente){
		//Capacidade esgotada, devemos aumentar o 
		//vetor usando "realloc" (ex: dobrar capacidade).
	    *capCliente = *capCliente * 2;
        listaCliente = (Cliente*)realloc(listaCliente, sizeof(Cliente) * (*capCliente));
    }
    
    //Leitura dos dados.
    printf("Digite o nome: ");
    fflush(stdin);
    gets(listaCliente[*numClienteCad].nome);
    printf("Digite o CPF do cliente: ");
    fflush(stdin);
    gets(listaCliente[*numClienteCad].cpf);
    printf("Digite o CEP do cliente: ");
    scanf("%d",&listaCliente[*numClienteCad].cep);
    printf("Digite o endereço do cliente: ");
    fflush(stdin);
    gets(listaCliente[*numClienteCad].endereco);
    printf("Digite o E-mail do cliente: ");
    fflush(stdin);
    gets(listaCliente[*numClienteCad].email);
    printf("Digite o telefone do cliente: ");
    scanf("%d",&listaCliente[*numClienteCad].telefone);
      //Incrementa numero de registros cadastrados.
	(*numClienteCad) ++;
	printf("Cliente salvo com sucesso!\n\n");
}
//===================================================================================================================================
/***************************************** funções salvar, exibir, remover o(s) Venda(s) *****************************************/
//===================================================================================================================================
void novaVenda(Venda *listaVenda, int  *numVendaCad, int *capVenda){
	printf("*** Nova Venda ***\n\n");
	char nome[100];
	char produto[100]; fflush(stdin);
	printf("Digite o nome do cliente: ");
    gets(nome);
    for(int i=0; i < *numVendaCad; i++){
        if (strcmp(listaVenda[i].nome, nome)==0){
//        	printf("Cliente encontrado com sucesso!\n\n");
//        	for(int j=0;j< *numProdutoCad; j++){
//        		if (strcmp(listaProduto[i].nome, produto)==0){
//        			printf("Produto encontrado com sucesso!\n\n");
//				} else printf("Produto não encontrado!\n");
//			}
        } else
	    	printf("Venda não encontrado!\n");
	    	return;
    } 
    printf("Venda salva com sucesso!\n\n");
}
