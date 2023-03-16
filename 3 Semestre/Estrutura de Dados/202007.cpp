#include <iostream>

using namespace std;

class Pilha
{
private:
    int * vet;
    int topo;
public:
    Pilha()
    {
        vet = new int[1000];
        topo = -1;
    }
    ~Pilha()
    {
        delete[] vet;
    }
    void empilhar(int n)
    {
        vet[++topo] = n;
    }
    int get(int n){
        return vet[n];
    }
    int Topo()
    {
        return topo;
    }
};

int main()
{

    Pilha f;
	bool c;
	int n;

	do{
            cout << "Escreva um numero: ";
            cin >> n;
            c = n >= 0;
            if(c){
                f.empilhar(n);
            }
            cout << endl;

	}while(c);

	int par = 0,impar = 0;

	for(int i = f.Topo();i >= 0;i--)
    {
        if(f.get(i)%2 == 0)
        {
            par++;
            impar--;
            if(par == 2)
            {
                break;
            }
        }
        else
        {
            par--;
            impar++;
            if(impar == 2)
            {
                break;
            }
        }

    }


    if(impar == 2 || par == 2)
    {
        cout << "NÃO";
    }
    else
    {
        cout << "SIM";
    }


}
