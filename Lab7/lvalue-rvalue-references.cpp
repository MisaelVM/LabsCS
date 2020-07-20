#include <iostream>

// LVALUES - RVALUES REFERENCES

// Ejemplos de referencias lvalue y rvalue

void lfoo(int& value) {} // Funci�n de par�metro referencia lvalue
void rfoo(int&& value) {} // Funci�n de par�metro referencia rvalue
void cfoo(const int& value) {} // Funci�n de par�metro referencia lvalue constante

int main()
{
	int a = 8; // lvalue: a		rvalue: 8
	// int& x = 8; // ERROR: referencia lvalue no puede tomar un rvalue
	int& y = a; // OK: referencia lvalue est� tomando un lvalue
	const int& i = 8; // OK: referencia constante lvalue puede tomar un rvalue
	const int& j = a; // OK: referencia constante rvalue est� tomando un lvalue
	lfoo(a); // OK: la funcion est� tomando un lvalue
	// lfoo(8); // ERROR: la funci�n no puede tomar un rvalue
	// rfoo(a); // ERROR: la funci�n no puede tomar un lvalue
	rfoo(8); // OK: la funci�n est� tomando un rvalue
	cfoo(a); cfoo(8); // OK: la funci�n puede tomar tanto lvalues como rvalues
	return 0;
}