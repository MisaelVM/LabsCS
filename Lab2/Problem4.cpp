#include <iostream>
#include <string>

using namespace std;

// PROBLEM 4
int hallarTamIterativo(char cad[]) { // -- Iterativo --
	int tam = 0;	// Declaramos e inicializamos el tamano en 0 para poder contar cuantos elementos hay en la cadena
	for (int i = 0; cad[i] != '\0'; i++, tam++); // Aumentamos el valor del contador en 1 siempre y cuando el char a analizar sea distinto de '\0'
	return tam;
}

int hallarTamRecursivo(char cad[]) { // -- Recursivo --
	if (cad[0] == '\0') // Caso base:
		return 0;		// Si el char a analizar es igual a '\0', es decir, NO hay un char, develve cero pues no añade al tamaño
	else
		return 1 + hallarTamRecursivo(cad + 1); // Se suma 1 con el "tamaño recursivo" de la siguiente subcadena
}												// "cad + 1" significa que pasamos al siguiente espacio de memoria de cad para poder analizar el siguiente elemento

int main()
{
	char cadena[] = "Hola Mundo!";
	int tamIterativo = hallarTamIterativo(cadena);
	int tamRecursivo = hallarTamRecursivo(cadena);
	cout << "Tamano de la cadena:\n";
	cout << "Iterativamente: " << tamIterativo << endl;
	cout << "Recursivamente: " << tamRecursivo << endl;
	return 0;
}