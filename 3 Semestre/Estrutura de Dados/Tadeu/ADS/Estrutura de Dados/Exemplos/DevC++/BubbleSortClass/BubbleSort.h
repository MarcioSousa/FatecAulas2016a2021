#ifndef BUBBLESORT_H
#define BUBBLESORT_H

class BubbleSort
{
	public:
		// construtores
		BubbleSort();
		BubbleSort(int);
		// gets e sets
		void SetElemento(int,int);
		int GetElemento(int);
		int GetTamanho();
		// interface do objeto
		void Sort();
		void Mostrar();
	protected:
		// atributos
		int * vetor;
		int tamanho;
		// método
		void Trocar(int,int);
};

#endif
