#include <iostream>

using namespace std;

// PROBLEM 4
int hallarTamIterativo(const char *cad) { // - Iterativo -
	int tam = 0;
	while (*cad++)
		tam++;
	return tam;
}

int hallarTamRecursivo(const char *cad) { // - Recursivo -
	if (!*cad)
		return 0;
	else
		return 1 + hallarTamRecursivo(++cad);
}

int main()
{
	char cad[] = "Hola Mundo!";
	
	cout << hallarTamIterativo(cad) << "\n";
	cout << hallarTamRecursivo(cad) << "\n";

	return 0;
}