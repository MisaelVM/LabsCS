#include <iostream>

using namespace std;

// PROBLEM 5
void concatenar(char *cadA, char *cadB) {
	char *ptrconcataqui = cadB;
	while (*cadB++)
		ptrconcataqui++;
	while (*cadA) {
		*ptrconcataqui++ = *cadA++;
	}
	*ptrconcataqui = '\0';
}

int main()
{
	char cadenaA[] = "Mundo!";
	char cadenaB[15] = "Hola ";

	cout << cadenaA << "\n";
	cout << cadenaB << "\n";

	concatenar(cadenaA, cadenaB);
	cout << cadenaB;
	return 0;
}