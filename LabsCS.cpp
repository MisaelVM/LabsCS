#include "Lab6/LinkedList.h"
#include "Lab6/Curso.h"

int main()
{
	LinkedList<float> lnk;
	LinkedList<std::string> lnkString;
	LinkedList<Curso> lnkCurso;
	
	lnk.insert(lnk.begin(), 7.9);
	lnk.insert(lnk.begin(), 8.4);
	lnk.insert(lnk.begin(), 9.2);
	for (LinkedList<float>::Iterator iter = lnk.begin(); iter != lnk.end(); ++iter)
		std::cout << *iter << " ";
	std::cout << "\n";

	LinkedList<float> lnkCopy(lnk);
	for (LinkedList<float>::Iterator iter = lnkCopy.begin(); iter != lnkCopy.end(); ++iter)
		std::cout << *iter << " ";
	std::cout << "\n";

	lnk.erase(lnk.end());
	lnk.pop_back();
	lnk.erase(lnk.end());
	lnk.pop_front();
	lnk.erase(lnk.end());
	lnk.insert(lnk.end(), 5.7);
	lnk.insert(lnk.end(), 4.3);
	lnk.insert(lnk.end(), 0.9);
	for (LinkedList<float>::Iterator iter = lnk.begin(); iter != lnk.end(); ++iter)
		std::cout << *iter << " ";
	lnk.clear();
	std::cout << "\n";

	lnkString.insert(lnkString.begin(), "Marcos");
	lnkString.insert(lnkString.begin(), "Julio");
	lnkString.insert(lnkString.begin(), "Salazar");
	for (LinkedList<std::string>::Iterator iter = lnkString.begin(); iter != lnkString.end(); ++iter)
		std::cout << *iter << " ";
	std::cout << "\n";
	lnkString.erase(lnkString.end());
	lnkString.pop_back();
	lnkString.erase(lnkString.end());
	lnkString.pop_front();
	lnkString.erase(lnkString.end());
	lnkString.insert(lnkString.end(), "Marcos");
	lnkString.insert(lnkString.end(), "Julio");
	lnkString.insert(lnkString.end(), "Salazar");
	for (LinkedList<std::string>::Iterator iter = lnkString.begin(); iter != lnkString.end(); ++iter)
		std::cout << *iter << " ";
	lnkString.clear();
	std::cout << "\n";

	Curso c1("Ciencias de la Computacion II", "3428195", 28),
		c2("Trabajo Interdisciplinar I", "4273196", 25),
		c3("Arquitectura de Computadores", "3924586", 37),
		c4("Desarrollo Basado en Plataformas", "3487632", 24),
		c5("Calculo en Varias Variables", "4136849", 27),
		c6("Ingles Tecnico Profesional I", "4361234", 22),
		c7("Ciudadania e Interculturalidad", "4592866", 20);

	lnkCurso.insert(lnkCurso.begin(), c1);
	lnkCurso.insert(lnkCurso.begin(), c2);
	lnkCurso.insert(lnkCurso.begin(), c3);
	for (LinkedList<Curso>::Iterator iter = lnkCurso.begin(); iter != lnkCurso.end(); ++iter)
		std::cout << *iter << "\n";
	std::cout << "\n";
	lnkCurso.erase(lnkCurso.end());
	lnkCurso.pop_back();
	lnkCurso.erase(lnkCurso.end());
	lnkCurso.pop_front();
	lnkCurso.erase(lnkCurso.end());
	lnkCurso.insert(lnkCurso.end(), c4);
	lnkCurso.insert(lnkCurso.end(), c5);
	lnkCurso.insert(lnkCurso.end(), c7);
	for (LinkedList<Curso>::Iterator iter = lnkCurso.begin(); iter != lnkCurso.end(); ++iter)
		std::cout << *iter << "\n";
	lnkCurso.clear();
	std::cout << "\n";
	return 0;
}