#include <iostream>

using namespace std;

// PROBLEM 3
void intercambiar(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void imprimirArray(int *A, int a) {
	for (int i = 0; i < a; i++)
		cout << A[i] << "\t";
	cout << "\n";
}

void insertionSort(int *A, int a) {
	for (int i = 1; i < a; i++) {
		int key = *++A;
		int j = i - 1;
		int *ptrKey = A - i + j;
		// Compara key con cada elemento en la izquierda de el
		// hasta que se encuentre un elemento menor que el
		while (j >= 0 && *ptrKey > key) {
			ptrKey++;
			*ptrKey-- = *ptrKey--;
			j--;
		}
		*++ptrKey = key;
	}
}

int main()
{
	int A[] = { 5, 3, 2, 9, 1, 4, 7, 6, 8 };
	int tam = sizeof(A) / sizeof(*A);
	imprimirArray(A, tam);
	insertionSort(A, tam);
	imprimirArray(A, tam);
	return 0;
}