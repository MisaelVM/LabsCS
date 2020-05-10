#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// PROBLEM 2
void intercambiar(int& a, int& b) { // Funcion que intercambia el valor de dos variables usando una temporal "SWAP"
	int temp = a;
	a = b;
	b = temp;
}

void invertirIterativo(int A[], int a) { // -- Iterativo --
	for (int i = 0; i < a / 2; i++)			// La funcion recorre desde el incio del array hasta la mitad, intercambiando los valores con sus opuestos para asi poder invertir el array
		intercambiar(A[i], A[a - i - 1]);	// Solo se recorre hasta la mitad del array porque recorrerlo todo resultaria en invertirlo 2 veces, es decir, no quedaría "invertido"
}

void invertirRecursivo(int A[], int a) { // -- Recursivo --
	if (a == 0 || a == 1)	// Caso base:
		return;				// La funcion se detiene si ya no queda array o el array tiene un solo elemento
	else {
		// Realiza el "swap" entre el numero que se tiene y su inverso
		// luego se sigue invirtiendo recursivamente los subarrays siguientes hasta llegar al centro (donde encontramos el caso base)
		intercambiar(A[0], A[a - 1]);		// "A + 1" nos permite pasar a la siguiente direccion de memoria, y por ende, al siguiente elemento.
		invertirRecursivo(A + 1, a - 2);	// "a - 2" nos permite acomodar el nuevo tamano de la subcadena y a analizar un indice menos en la funcion, es decir, obtener el inverso del siguiente elemento de la lista
	}
}

// Las siguientes 2 funciones nos ayudaran a manipular mejor los arrays

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

int main()
{
	int arreglo[7];
	int tam = sizeof(arreglo) / sizeof(arreglo[0]);
	llenarArreglo(arreglo, tam);
	cout << "Array normal:\n";
	imprimirArreglo(arreglo, tam);
	invertirIterativo(arreglo, tam);
	cout << "Array invertido iterativamente:\n";
	imprimirArreglo(arreglo, tam);
	cout << "\n";
	int arr[11];
	int taman = sizeof(arr) / sizeof(arr[0]);
	llenarArreglo(arr, taman);
	cout << "Array normal:\n";
	imprimirArreglo(arr, taman);
	invertirRecursivo(arr, taman);
	cout << "Array invertido recursivamente:\n";
	imprimirArreglo(arr, taman);

	return 0;
}