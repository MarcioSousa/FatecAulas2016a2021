#include "BubbleSort.h"
#include <cstring>
#include <iostream>

template <class T>
BubbleSort<T>::BubbleSort()
{
	tamanho = 1;
	vetor = new T[tamanho];
	memset(vetor,0x0,tamanho * sizeof(T));
}
template <class T>
BubbleSort<T>::BubbleSort(int t)
{
	tamanho = t;
	vetor = new T[tamanho];
	memset(vetor,0x0,tamanho * sizeof(T));
}

template <class T>
void BubbleSort<T>::SetElemento(int posicao, T valor)
{
	vetor[posicao] = valor;
}

template <class T>
T BubbleSort<T>::GetElemento(int posicao)
{
	return vetor[posicao];
}
template <class T>
int BubbleSort<T>::GetTamanho()
{
	return tamanho;
}

template <class T>
void BubbleSort<T>::Trocar(int i, int ii)
{
	T aux = vetor[i];
	vetor[i] = vetor[ii];
	vetor[ii] = aux;
}
template <class T>
void BubbleSort<T>::Mostrar()
{
	int t = GetTamanho();
	for (int i=0; i < t; i++)
	{
		std::cout << GetElemento(i) << "\t"; 
	}
}
template <class T>
void BubbleSort<T>::Sort()
{
	int i = 0;
	int t = tamanho;
	for (; t > 0; t--)
	{
		for (i=0; i < (t - 1); i++)
		{
			if (vetor[i] > vetor[i+1])
			{
				Trocar(i,i+1);
			}
		}
	}
}

template class BubbleSort<int>;
template class BubbleSort<float>;
template class BubbleSort<double>;
template class BubbleSort<long double>;
template class BubbleSort<long int>;
template class BubbleSort<short int>;
template class BubbleSort<long long>;
template class BubbleSort<char>;




