#include "BubbleSort.h"
#include <cstring>
#include <iostream>

BubbleSort::BubbleSort()
{
	tamanho = 1;
	vetor = new int[tamanho];
	memset(vetor,0x0,tamanho * sizeof(int));
}
BubbleSort::BubbleSort(int t)
{
	tamanho = t;
	vetor = new int[tamanho];
	memset(vetor,0x0,tamanho * sizeof(int));
}
void BubbleSort::SetElemento(int posicao, int valor)
{
	vetor[posicao] = valor;
}
int BubbleSort::GetElemento(int posicao)
{
	return vetor[posicao];
}
int BubbleSort::GetTamanho()
{
	return tamanho;
}

void BubbleSort::Trocar(int i, int ii)
{
	int aux = vetor[i];
	vetor[i] = vetor[ii];
	vetor[ii] = aux;
}

void BubbleSort::Mostrar()
{
	int t = GetTamanho();
	for (int i=0; i < t; i++)
	{
		std::cout << GetElemento(i) << "\t"; 
	}
}

void BubbleSort::Sort()
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

