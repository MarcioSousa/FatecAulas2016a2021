#include <iostream>

using namespace std;

class Pilha
{
private:
    char * vet;
    int topo;
public:
    Pilha()
    {
        vet = new char[1000];
        topo = -1;
    }
    ~Pilha()
    {
        delete[] vet;
    }
    void empilhar(char n)
    {
        vet[++topo] = n;
    }
    char get(int n){
        return vet[n];
    }
    char Topo()
    {
        return topo;
    }
};

int main()
{

    Pilha p1,p2;
	bool c;
	char n;

	cout << "Pilha 1" << endl;

	do{
            cout << "Escreva um numero: ";
            cin >> n;
            c = n != '0';
            if(c){
                p1.empilhar(n);
            }
            cout << endl;

	}while(c);

	cout << "Pilha 2" << endl;

	do{
            cout << "Escreva um numero: ";
            cin >> n;
            c = n != '0';
            if(c){
                p2.empilhar(n);
            }
            cout << endl;

	}while(c);

    bool v = true;

	for(int i = 0;i <= p1.Topo();i++){

            if(p1.get(i)>='a'){
                if(p2.get(i)>='a' && p2.get(i)<='z'){

                }
                else if(p2.get(i)>='A' && p2.get(i)<='Z'){
                    v = false;
                    break;
                }
            }
            else if(p1.get(i)>='A'){
                if(p2.get(i)>='a' && p2.get(i)<='z'){
                    v = false;
                    break;
                }
                else if(p2.get(i)>='A' && p2.get(i)<='Z'){

                }
            }


	}

	if(v){
        cout << "SIM";
	}
    else{
        cout << "NAO";
    }




}
