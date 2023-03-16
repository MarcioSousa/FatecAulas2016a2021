#ifndef BUBBLESORT_H
#define BUBBLESORT_H

template <class T> class BubbleSort
{
	public:
		// construtores
		BubbleSort();
		BubbleSort(int);
		// gets e sets
		void SetElemento(int,T);
		T GetElemento(int);
		int GetTamanho();
		// interface do objeto
		void Sort();
		void Mostrar();
	protected:
		// atributos
		T * vetor;
		int tamanho;
		// método
		void Trocar(int,int);
};

#endif
