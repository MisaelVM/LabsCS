#include <iostream>

using namespace std;

// PROBLEM 6
void copiarAaB(char *cadA, char *cadB) {
	while (*cadA)
		*cadB++ = *cadA++;
	*cadB = '\0';
}

int main()
{
	char cadenaA[] = "Mundo!";
	char cadenaB[15] = "Hola ";

	cout << cadenaA << "\n";
	cout << cadenaB << "\n";

	copiarAaB(cadenaA, cadenaB);
	cout << cadenaB;
	return 0;
}