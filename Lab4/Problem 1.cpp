#include <iostream>
#include <string>

using namespace std;

/* --- PROBLEM 1 --- */
class Curso {
private:
	string nombre;
	string codigo;
	int nroAlumnos;

public:
	// - Constructores -
	Curso();
	Curso(string name, string code, int nbrStudents);

	// - Funciones -
	// Getters
	string getNombre() const;
	string getCodigo() const;
	int getNroAlumnos() const;

	// Setters
	void setNombre(const string nombre);
	void setCodigo(const string codigo);
	void setNroAlumnos(const int nroAlumnos);
};

// -- CURSO --

// - Constructores -
Curso::Curso() { nombre = "o"; codigo = "o"; nroAlumnos = 0; }
Curso::Curso(string name, string code, int nbrStudents) { nombre = name; codigo = code; nroAlumnos = nbrStudents; }

// - Funciones -

// Getters
string Curso::getNombre() const { return nombre; }
string Curso::getCodigo() const { return codigo; }
int Curso::getNroAlumnos() const { return nroAlumnos; }
// Setters
void Curso::setNombre(const string nombre) { this->nombre = nombre; }
void Curso::setCodigo(const string codigo) { this->codigo = codigo; }
void Curso::setNroAlumnos(const int nroAlumnos) { this->nroAlumnos = nroAlumnos; }

int main()
{
	Curso c1("Ciencias de la Computacion II", "3428195", 28),
		c2("Trabajo Interdisciplinar I", "4273196", 25),
		c3("Arquitectura de Computadores", "3924586", 37),
		c4("Desarrollo Basado en Plataformas", "3487632", 24),
		c5("Calculo en Varias Variables", "4136849", 27),
		c6("Ingles Tecnico Profesional I", "4361234", 22),
		c7("Ciudadania e Interculturalidad", "4592866", 20);

	Curso arr[] = { c1, c2, c3, c4, c5 };

	return 0;
}
