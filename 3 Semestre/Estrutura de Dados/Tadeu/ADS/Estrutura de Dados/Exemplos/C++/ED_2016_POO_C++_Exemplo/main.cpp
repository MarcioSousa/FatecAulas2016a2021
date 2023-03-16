#include <iostream>
#include <cstdlib>

using namespace std;

class Vetor
{
private:
    // Atributos
    int tamanho;
    int * vetor;
protected:

public:
    // Métodos
    // Construtores
    Vetor();
    Vetor(int);
    // Gets e Sets
    int GetTamanho();
    int GetElemento(int);
    void SetElemento(int,int);
    // Gerais
    void Mostrar();
};

Vetor::Vetor()
{
    tamanho = 1;
    vetor = new int(tamanho);
}

Vetor::Vetor(int t)
{
    tamanho = t;
    vetor = new int(tamanho);
}

int Vetor::GetElemento(int pos)
{
    return vetor[pos];
}

int Vetor::GetTamanho()
{
    return tamanho;
}


void Vetor::SetElemento(int pos, int valor)
{
    vetor[pos] = valor;
}

void Vetor::Mostrar()
{
    int indx = 0;
    for (; indx < tamanho; indx++)
    {
        cout << "vetor[" << indx << "] = " << vetor[indx] << endl;
    }
}

int main()
{
    int indx = 0;
    int valor;
    Vetor v(10);
    Vetor * vd;

    vd = new Vetor(10);

    vd->GetTamanho();

    for (; indx < v.GetTamanho(); indx++)
    {
        cout << endl << "Digite [" << indx << "]: ";
        cin >> valor;
        v.SetElemento(indx,valor);
    }

    v.Mostrar();

    exit(0);
}
