#include <iostream>

using namespace std;

// PROBLEM 2
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

void invertirIterativo(int *A, int a) {
	int* ptrFinal = A + a - 1;
	for (int i = 0; i < a / 2; i++)
		intercambiar(A++, ptrFinal--);
}

void invertirRecursivo(int* A, int a) {
	int* ptrFinal = A + a - 1;
	if (a == 0 || a == 1)
		return;
	else {
		intercambiar(A, ptrFinal--);
		invertirRecursivo(++A, a - 2);
	}
}

int main()
{
	int A[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int tam = sizeof(A) / sizeof(*A);
	imprimirArray(A, tam);

	invertirRecursivo(A, tam);
	imprimirArray(A, tam);

	return 0;
}