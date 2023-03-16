#include <iostream>
//#include <cstdlib>

using namespace std;

class Vetor
{
private:
    int tamanho;
    int * vetor;
public:
    Vetor();
    Vetor(int);
    void SetElemento(int,int);
    int GetTamanho();
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

int Vetor::GetTamanho()
{
    return tamanho;
}

void Vetor::SetElemento(int pos, int valor)
{
    if (pos >= tamanho)
    {
        throw string("Excecao: limite de indice excedido");
    }
    vetor[pos] = valor;
}

void Vetor::Mostrar()
{
    int indx = 0;
    int tam  = tamanho;
    for (; indx < tam; indx++)
    {
        cout << "[" << indx << "] = " << vetor[indx] << endl;
    }
}

int main()
{
    Vetor v1(10);
    Vetor * v2;
    int indx = 0;
    int tam;

    v2 = new Vetor(10);
    tam = v1.GetTamanho();
    try
    {
        for (; indx < tam; indx++)
        {
            v1.SetElemento(indx,indx * 10);
            v2->SetElemento(indx,indx * 15);

        }

        v1.Mostrar();
        cout << "----";
        v2->Mostrar();
    }
    catch (string ex)
    {
        cout << ex << endl;
    }

    exit(0);
}
