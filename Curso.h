#pragma once

#include <iostream>
#include <string>

class Curso {
private:
	std::string nombre;
	std::string codigo;
	int nroAlumnos;

public:
	// - Constructores -
	Curso();
	Curso(std::string name, std::string code, int nbrStudents);

	// - Funciones -
	// Getters
	std::string getNombre() const;
	std::string getCodigo() const;
	int getNroAlumnos() const;

	// Setters
	void setNombre(const std::string nombre);
	void setCodigo(const std::string codigo);
	void setNroAlumnos(const int nroAlumnos);

	bool operator == (const Curso &o) const;

	bool operator != (const Curso &o) const;

	friend std::ostream &operator << (std::ostream &stream, const Curso &o);
};