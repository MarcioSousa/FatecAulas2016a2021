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
    void print()
    {
        for(int i = topo;i >= 0;i--)
        {
            cout << vet[i] << endl;
        }
    }
    int Topo()
    {
        return topo;
    }
};

int main()
{

    Pilha f1, fp, fi;
	bool c;
	int n;

	do{
            cout << "Escreva um numero: ";
            cin >> n;
            c = n >= 0;
            if(c){
                f1.empilhar(n);
            }
            cout << endl;

	}while(c);

    for(int i = f1.Topo();i >= 0;i--)
    {
        if(f1.get(i)%2 == 0)
        {

            fp.empilhar(f1.get(i));

        }
        else
        {

            fi.empilhar(f1.get(i));

        }

    }

    fi.print();
    fp.print();


}
