#include <iostream>

using namespace std;

// PROBLEM 5
int hallarTamIterativo(char cad[]) { // Haremos uso de la funcion para hallar el tamaño que programamos con anterioridad
	int tam = 0;
	for (int i = 0; cad[i] != '\0'; i++, tam++);
	return tam;
}

void concatenar(char cadA[], char cadB[]) { // Suponiendo que la cadena B tiene aun espacio para concatenarle la cadena A:
	int tamA = hallarTamIterativo(cadA); // Procedemos a hallar el tamano de nuestras cadenas para manipularlas más comodamente
	int tamB = hallarTamIterativo(cadB);
	for (int i = tamB, j = 0; i < tamA + tamB; i++, j++)	// Usando 2 índices (i para manipular la cadena B y j para la B)
		cadB[i] = cadA[j];									// procedemos a "transferir" los elementos de la cadena A (con j empezando en en su indice 0),
}															// a la cadena B (con i empezando en donde B ya no tenga mas elementos, es decir "el tamano de la cadena B")

int main()
{
	char cadenaA[] = "Mundo!";
	char cadenaB[15] = "Hola ";

	cout << "Cadena A: " << cadenaA << endl;
	cout << "Cadena B: " << cadenaB << endl;

	concatenar(cadenaA, cadenaB);
	cout << "Cadena B concatenada: " << cadenaB << endl;

	return 0;
}