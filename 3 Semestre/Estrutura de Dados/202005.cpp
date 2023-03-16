#include <iostream>

using namespace std;

class No
{
private:
	char v;
	No* prox;
public:
	No(char v)
	{
		this->v = v;
		this->prox = NULL;
	}

	char obterValor()
	{
		return v;
	}

	No* obterProx()
	{
		return prox;
	}

	void setProx(No* p)
	{
		prox = p;
	}

	void setValue(int p)
	{
		v = p;
	}
};

class Lista
{
private:
	No* cabeca;
	No* cauda;
public:
	Lista()
	{
		cabeca = NULL;
		cauda = NULL;
	}

	Lista(char v)
	{
		cabeca = new No(v);
		cauda = cabeca;
	}

	virtual ~Lista()
	{
		delete cabeca;
	}

	void mostrar()
	{
		cout << "\nImprimindo todos os elementos...\n";
		No* c = cabeca;

		if(vazia())
			cout << "A lista NAO possui elementos!!\n";
		else
		{
			while(c)
			{
				cout << c->obterValor() << endl;
				c = c->obterProx();
			}
			cout << endl;
		}
	}

	char obter(int n)
	{
		No* c = cabeca;

		if(vazia())
			cout << "A lista NAO possui elementos!!\n";
		else
		{
		    if(n > 1){

                for(int i = 0;i + 1 < n;i++){

                    c = c->obterProx();

                }

		    }
            return c->obterValor();
		}
	}

	bool vazia()
	{
		return (cabeca == NULL);
	}

	void inserir_final(char v)
	{
		No* novo_no = new No(v);

		if(vazia())
		{
			cabeca = novo_no;
			cauda = novo_no;
		}
		else
		{
			cauda->setProx(novo_no);
			cauda = novo_no;
		}
	}

};

int main(int argc, char *argv[])
{
	Lista l1, l2;
	bool c = true;
    char n;
    int q1 = 0;
    int q2 = 0;

    cout << "Lista 1" << endl;

    do{
            cout << "Escreva: ";
            cin >> n;
            if(n == '0'){

                    break;

            }
            else{
                l1.inserir_final(n);
                q1 = q1 + 1;
                cout << endl;
            }

	}while(c);

	cout << "Lista 2" << endl;

	do{
            cout << "Escreva: ";
            cin >> n;
            if(n == '0'){

                    break;

            }
            else{
                l2.inserir_final(n);
                q2 = q2 + 1;
                cout << endl;
            }

	}while(c);

    int q = 0,cro,jj;

    if(q1 < q2){

        for(int i = 1;i <= q2;i++){

                if(l2.obter(i) == l1.obter(1)){

                        jj = i;
                        cro = 0;

                        for(int j = 1;j <= q1;j++){


                                if(l2.obter(jj) == l1.obter(j)){
                                    cro++;
                                }
                                jj++;

                        }
                        if(cro == q1){

                                q++;

                        }

                }

        }
    }

    cout << "\n";
    cout << q;

	return 0;
}
