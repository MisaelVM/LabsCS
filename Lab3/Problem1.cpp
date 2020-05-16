#include <iostream>

using namespace std;

// PROBLEM 1
int sumarElementosIterativo(int *A, int a) { // -- Iterativo --
	int sum = 0;
	for (int i = 0; i < a; i++)
		sum += *A++;
	return sum;
}

int sumarElementosRecursivo(int *A, int a){ // -- Recursivo --
	if (a == 1)
		return *A;
	else
		return *A + sumarElementosRecursivo(++A, --a);
}

int main()
{
	int A[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int tam = sizeof(A) / sizeof(*A);
	cout << sumarElementosIterativo(A, tam) << "\n";
	cout << sumarElementosRecursivo(A, tam) << "\n";
	return 0;
}