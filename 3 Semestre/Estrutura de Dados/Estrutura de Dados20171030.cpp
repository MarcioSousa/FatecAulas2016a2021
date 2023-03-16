Encadeamento de Estruturs

--> Encadeamento:
	*Simples.
	*Duplo.

--> Encadeamento Simples:
	#100				#200             #300
	Dado | Ponteiro		Dado | Ponteiro	 Dado | Ponteiro
			#100				#200			    /	

Estrutura de Dados
	Struct SDado
	{
		//Informações: Dados
		//Ponteiro
		TDado *prox;
	};
	typedef struct SDado TDado;
	
Ex: Encadeamento de trÊs valores reais
#include <dtdio.h>

struct SDado
{
	double valor;
	TDado *prox;
}

typedef struct SDado TDado;
int main(void){
	TDado e1;
	TDado e2;
	TDado e3;
	TDado *aux;
	e1.prox = &e2;
	e2.prox = &e3;
	e3.prox = null;
	aux = &e1;
	
	while(aux != null){
		scanf("%f", &(aux.valor));
		aux = aux -> prox;
	}
	aux = &e1;
	while(aux != null){
		printf("%f", aux.valor);
		aux = aux -> prox;
	}
}
