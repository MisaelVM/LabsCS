#include "Curso.h"

// - Constructores -
Curso::Curso() { nombre = "o"; codigo = "o"; nroAlumnos = 0; }
Curso::Curso(std::string name, std::string code, int nbrStudents) { nombre = name; codigo = code; nroAlumnos = nbrStudents; }

// - Funciones -

// Getters
std::string Curso::getNombre() const { return nombre; }
std::string Curso::getCodigo() const { return codigo; }
int Curso::getNroAlumnos() const { return nroAlumnos; }
// Setters
void Curso::setNombre(const std::string nombre) { this->nombre = nombre; }
void Curso::setCodigo(const std::string codigo) { this->codigo = codigo; }
void Curso::setNroAlumnos(const int nroAlumnos) { this->nroAlumnos = nroAlumnos; }

bool Curso::operator == (const Curso &o) const {
	return (nombre == o.nombre) && (codigo == o.codigo) && (nroAlumnos == o.nroAlumnos);
}

bool Curso::operator!=(const Curso& o) const {
	return !(*this == o);
}


std::ostream &operator << (std::ostream &stream, const Curso &o) {
	stream << "Curso: " << o.nombre << "\tCodigo: " << o.codigo << "\tNro. alumnos: " << o.nroAlumnos;
	return stream;
}