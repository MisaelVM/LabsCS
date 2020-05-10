#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// PROBLEM 3
void intercambiar(int &a, int &b) { // Funcion que intercambia el valor de dos variables usando una temporal "SWAP"
	int temp = a;
	a = b;
	b = temp;
}

void llenarArreglo(int A[], int a) { // Esta funcion nos permite llenar los elementos de un array con valores aleatorios
	srand(time(0));
	for (int i = 0; i < a; i++)
		A[i] = rand() % 100 + 1;
}

void imprimirArreglo(int A[], int a) { // Esta funcion nos permite imprimir los elementos de un array
	for (int i = 0; i < a; i++)
		cout << A[i] << "\t";
	cout << "\n";
}

void sortArray(int A[], int a) {   // -- SELECTION SORT -- Trabajamos con 2 subarrays, uno ordenado y otro que falta ordenar
	for (int i = 0; i < a - 1; i++) { // Establecemos los limites del subarray ordenado que ira incrementando con cada iteracion
		int min_index = i; // Este algoritmo busca el menor de los elementos del subarray no ordenado y lo agrega al array ordenado al terminar la iteracion
		for (int j = i + 1; j < a; j++)		// Asumiendo que el menor elemento es el primero del subarray no ordenado, procederemos a comparar en dicho subarray
			if (A[j] < A[min_index])		// bucando si hay elementos menores que ese para actualizar el indice del menor elemento
				min_index = j;
		intercambiar(A[min_index], A[i]);	// Una vez encontrado el menor de esos elementos, se procede a intercambiar con el primero de los elementos del subarray
	}										// de esta forma ordenaremos un elemento por iteracion, el cual pasara a formar parte del subarray ordenado
}

int main()
{
	int arreglo[7];
	int tam = sizeof(arreglo) / sizeof(arreglo[0]);

	llenarArreglo(arreglo, tam);
	cout << "Array desordenado:\n";
	imprimirArreglo(arreglo, tam);

	sortArray(arreglo, tam);
	cout << "Array ordenado:\n";
	imprimirArreglo(arreglo, tam);
	return 0;
}