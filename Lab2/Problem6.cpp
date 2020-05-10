#include <iostream>

using namespace std;

// PROBLEM 6
int hallarTamIterativo(char cad[]) { // Haremos uso de la funcion para hallar el tamaño que programamos con anterioridad
	int tam = 0;
	for (int i = 0; cad[i] != '\0'; i++, tam++);
	return tam;
}

void copiarContenido(char cadA[], char cadB[]) { // 
	int tamA = hallarTamIterativo(cadA); // Procedemos a hallar el tamano de nuestra cadena para manipularla más comodamente
	for (int i = 0; i < tamA; i++) // "Copiamos" los elementos de la cadena A a la cadena B, reemplazandolos
		cadB[i] = cadA[i];
	cadB[tamA] = '\0'; // Finalmente "cerramos" la cadena cuando todos los elementos de A hayan sido copiados en caso la cadena B tenga mas caracteres que la cadena A
}

int main()
{
	char cadenaA[] = "Mundo!";
	char cadenaB[15] = "Hola ";

	cout << "Cadena A: " << cadenaA << endl;
	cout << "Cadena B: " << cadenaB << endl;

	copiarContenido(cadenaA, cadenaB);
	cout << "Cadena B con elementos copiados de la cadena A: " << cadenaB << endl;

	return 0;
}