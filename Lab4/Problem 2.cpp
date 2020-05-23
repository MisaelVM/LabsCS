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


/* --- PROBLEM 2 --- */
class ArregloDeCursos {
private:
	Curso *cursos;
	int tam;

	// - Funciones privadas -
	void redimensionar(int n);

public:
	// - Constructores/Destructor -
	ArregloDeCursos(const Curso cursos[], const int tam);
	ArregloDeCursos(const ArregloDeCursos &o);
	~ArregloDeCursos();

	// - Funciones -
	void push_back(const Curso &p);
	void insert(const int posicion, const Curso &p);
	void remove(const int pos);
	int getSize() const;
	void clear();
	
	// - Imprime los cursos -
	void print();
};

// -- ARREGLO DE CURSOS --
// - Funcion privada -
void ArregloDeCursos::redimensionar(int n) {
	Curso *temp = new Curso[n];

	for (int i = 0; i < n && i < tam; i++)
		temp[i] = cursos[i];

	delete[] cursos;
	cursos = temp;
	this->tam = n;
}

// - Constructores/Destructor -
ArregloDeCursos::ArregloDeCursos(const Curso cursos[], const int tam) {
	this->tam = tam;
	this->cursos = new Curso[tam];
	for (int i = 0; i < tam; i++)
		this->cursos[i] = cursos[i];
}

ArregloDeCursos::ArregloDeCursos(const ArregloDeCursos &o) {
	this->tam = o.tam;
	this->cursos = new Curso[tam];
	for (int i = 0; i < o.tam; i++)
		this->cursos[i] = o.cursos[i];
}

ArregloDeCursos::~ArregloDeCursos() { delete[] this->cursos; }

// - Funciones -
void ArregloDeCursos::push_back(const Curso &p) {
	redimensionar(tam + 1);
	cursos[tam - 1] = p;
}

void ArregloDeCursos::insert(const int posicion, const Curso &p) {
	redimensionar(tam + 1);
	for (int i = tam - 1; i > posicion; i--)
		cursos[i] = cursos[i - 1];
	cursos[posicion] = p;
}

void ArregloDeCursos::remove(const int pos) {
	for (int i = pos; i < tam - 1; i++)
		cursos[i] = cursos[i + 1];
	redimensionar(tam - 1);
}

int ArregloDeCursos::getSize() const {
	return tam;
}

void ArregloDeCursos::clear() {
	delete[] cursos;
	cursos = nullptr;
	tam = 0;
}

// - Imprime los cursos -
void ArregloDeCursos::print() {
	cout << "---------------------------------------------\n";
	for (int i = 0; i < tam; i++) {
		cout << "Nombre del curso: " << cursos[i].getNombre() << "\n";
		cout << "Codigo del curso: " << cursos[i].getCodigo() << "\n";
		cout << "Numero de estudiantes: " << cursos[i].getNroAlumnos() << "\n";
		cout << "---------------------------------------------\n";
	}
	cout << "\n=============================================\n\n";
}

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
	
	ArregloDeCursos arrCursos(arr, 5);
	arrCursos.print();

	arrCursos.push_back(c6);
	arrCursos.print();

	arrCursos.insert(4, c7);
	arrCursos.print();

	arrCursos.remove(3);
	arrCursos.print();

	arrCursos.clear();

	arrCursos.push_back(c4);
	arrCursos.print();

	return 0;
}
