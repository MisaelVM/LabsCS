#include <iostream>

// RVALUES - LVALUES

// Ejemplos de lvalues y rvalues
int main()
{
	int x = 2;			// lvalue: x	rvalue: 2
	int y = x + 2;		// lvalue: y	rvalue: x + 2
	int* p = &y;		// p y q tienen direccion de memoria identificable, p puede ser desreferenciado y y referenciado
	//int* ptr = &(x + 2);// ERROR: x + 2 no tiene una dirección de memoria identificable, es un rvalue
	//x + 2 = 4;			// ERROR: i + 2 no es un lvalue, no tiene identidad, no se le puede asignar contenido
	//2 = x;				// ERROR: 2 es un literal sin identidad, un rvalue, no se le puede asignar contenido

	return 0;
}