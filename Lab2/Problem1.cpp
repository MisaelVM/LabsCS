#include <iostream>

using namespace std;

// PROBLEM 1
int sumarElementosIterativo(int A[], int a) { // -- Iterativo --
	int sum = 0; // Declaramos e inicializamos el valor de la suma

	for (int i = 0; i < a; sum += A[i++]);	// Dara tantas iteraciones como elementos haya en el array
											// Se ira sumando el valor del elemento en el indice actual a la vez que se actualiza este indice
	return sum;
}

int sumarElementosRecursivo(int A[], int a) { // -- Recursivo --
	if (a == 1) // Caso base:
		return A[0]; // Devuelve el elemento
	else
		return A[a - 1] + sumarElementosRecursivo(A, a - 1); // Suma el ultimo elemento con la "suma de elementos" del subarray que queda
}

int main()
{
	int arreglo[] = { 45, 21, -9, 16, 33, -27 };
	int tam = sizeof(arreglo) / sizeof(arreglo[0]);

	int suma_iterativa = sumarElementosIterativo(arreglo, tam);
	int suma_recursiva = sumarElementosRecursivo(arreglo, tam);

	cout << "El tamano del array es:\n";
	cout << "Iterativamente: " << suma_iterativa << endl;
	cout << "Recursivamente: " << suma_recursiva << endl;
	return 0;
}