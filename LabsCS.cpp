#include <iostream>

// RVALUES - LVALUES

// Ejemplos de lvalues y rvalues
/*int main()
{
	int x = 2;			// lvalue: x	rvalue: 2
	int y = x + 2;		// lvalue: y	rvalue: x + 2
	int* p = &y;		// p y q tienen direccion de memoria identificable, p puede ser desreferenciado y y referenciado
	//int* ptr = &(x + 2);// ERROR: x + 2 no tiene una dirección de memoria identificable, es un rvalue
	//x + 2 = 4;			// ERROR: i + 2 no es un lvalue, no tiene identidad, no se le puede asignar contenido
	//2 = x;				// ERROR: 2 es un literal sin identidad, un rvalue, no se le puede asignar contenido

	return 0;
}*/

/*
// Ejemplos de referencias lvalue y rvalue

void lfoo(int& value) {} // Función de parámetro referencia lvalue
void rfoo(int&& value) {} // Función de parámetro referencia rvalue
void cfoo(const int& value) {} // Función de parámetro referencia lvalue constante

int main()
{
	int a = 8; // lvalue: a		rvalue: 8
	int& x = 8; // ERROR: referencia lvalue no puede tomar un rvalue
	int& y = a; // OK: referencia lvalue está tomando un lvalue
	const int& i = 8; // OK: referencia constante lvalue puede tomar un rvalue
	const int& j = a; // OK: referencia constante rvalue está tomando un lvalue
	lfoo(a); // OK: la funcion está tomando un lvalue
	lfoo(8); // ERROR: la función no puede tomar un rvalue
	rfoo(a); // ERROR: la función no puede tomar un lvalue
	rfoo(8); // OK: la función está tomando un rvalue
	cfoo(a); cfoo(8); // OK: la función puede tomar tanto lvalues como rvalues
	return 0;
}*/

/*
// std::move
#include <iostream>
#include <vector>

void printVector(std::vector<int>& vec) {
	for (auto i : vec)
		std::cout << i << " ";
	std::cout << "\n";
}

int main() {
	std::vector<int> vec1;
	std::vector<int> vec2;

	for (auto i = 0; i < 5; i++) vec1.push_back(i);
	for (auto i = 10; i < 15; i++) vec2.push_back(i);

	std::cout << "Vector1: "; printVector(vec1);
	std::cout << "Vector2: "; printVector(vec2);
	// vec2 = vec1; std::cout << "Copiado!\n";
	// vec2 = (std::vector<int>)vec1; std::cout << "Movido!\n";
	vec2 = std::move(vec1); std::cout << "Movido!\n";
	std::cout << "Vector1: "; printVector(vec1);
	std::cout << "Vector2: "; printVector(vec2);

	return 0;
}*/

// MOVE SEMANTICS

/*class String {
private:
	char *m_Data;
	uint32_t m_Size;

public:
	String() = default;
	String(const char *string) {
		printf("Created!\n");
		m_Size = strlen(string);
		m_Data = new char[m_Size];
		memcpy(m_Data, string, m_Size);
	}
	String(const String &other) {
		printf("Copied!\n");
		m_Size = other.m_Size;
		m_Data = new char[m_Size];
		memcpy(m_Data, other.m_Data, m_Size);
	}
	~String() {
		printf("Destroyed!\n");
		delete[] m_Data;
	}

	void Print() {
		for (uint32_t i = 0; i < m_Size; i++)
			printf("%c", m_Data[i]);
		printf("\n");
	}
};

class Entity {
private:
	String m_Name;

public:
	Entity(const String &name) : m_Name(name) {}

	void PrintName() {
		m_Name.Print();
	}
};

int main()
{
	Entity entity("Cherno");
	entity.PrintName();

	Entity entity2(String("Cherno2"));
	entity2.PrintName();

	return 0;
}*/

/*class String {
private:
	char *m_Data;
	uint32_t m_Size;

public:
	String() = default;

	String(const char *string) {
		printf("Created!\n");
		m_Size = strlen(string);
		m_Data = new char[m_Size];
		memcpy(m_Data, string, m_Size);
	}

	String(const String &other) {
		printf("Copied!\n");
		m_Size = other.m_Size;
		m_Data = new char[m_Size];
		memcpy(m_Data, other.m_Data, m_Size);
	}

	String(String&& other) noexcept {
		printf("Moved!\n");
		m_Size = other.m_Size;
		m_Data = other.m_Data;

		other.m_Size = 0;
		other.m_Data = nullptr;
	}

	~String() {
		printf("Destroyed!\n");
		delete[] m_Data;
	}

	void Print() {
		for (uint32_t i = 0; i < m_Size; i++)
			printf("%c", m_Data[i]);
		printf("\n");
	}
};

class Entity {
private:
	String m_Name;

public:
	Entity(const String &name) : m_Name(name) {}

	Entity(String&& name) : m_Name((String&&)name) {}

	void PrintName() {
		m_Name.Print();
	}
};

int main()
{
	Entity entity("Cherno");
	entity.PrintName();

	Entity entity2(String("Cherno2"));
	entity2.PrintName();

	return 0;
}*/

/*#include <iostream>

class String {
private:
	char *m_Data;
	uint32_t m_Size;

public:
	String() = default;

	String(const char *string) {
		printf("Created!\n");
		m_Size = strlen(string);
		m_Data = new char[m_Size];
		memcpy(m_Data, string, m_Size);
	}

	String(const String &other) {
		printf("Copied!\n");
		m_Size = other.m_Size;
		m_Data = new char[m_Size];
		memcpy(m_Data, other.m_Data, m_Size);
	}

	String(String &&other) noexcept {
		printf("Moved!\n");
		m_Size = other.m_Size;
		m_Data = other.m_Data;

		other.m_Size = 0;
		other.m_Data = nullptr;
	}

	~String() {
		printf("Destroyed!\n");
		delete[] m_Data;
	}

	void Print() {
		for (uint32_t i = 0; i < m_Size; i++)
			printf("%c", m_Data[i]);
		printf("\n");
	}
};

class Entity {
private:
	String m_Name;

public:
	Entity(const String &name) : m_Name(name) {}

	//Entity(String &&name) : m_Name((String&&)name) {}
	Entity(String &&name) : m_Name(std::move(name)) {}

	void PrintName() {
		m_Name.Print();
	}
};

int main()
{
	Entity entity("Cherno");
	entity.PrintName();

	// Entity entity2(String("Cherno2"));
	// entity2.PrintName();

	String string = "Hello";
	// String dest((String&&)string);
	// String dest = (String&&)string;
	// String dest = std::move(string);
	// String dest(std::move(string));

	return 0;
}*/

/*#include <iostream>

class String {
private:
	char* m_Data;
	uint32_t m_Size;

public:
	String() = default;

	String(const char* string) {
		printf("Created!\n");
		m_Size = strlen(string);
		m_Data = new char[m_Size];
		memcpy(m_Data, string, m_Size);
	}

	String(const String& other) {
		printf("Copied!\n");
		m_Size = other.m_Size;
		m_Data = new char[m_Size];
		memcpy(m_Data, other.m_Data, m_Size);
	}

	String(String&& other) noexcept {
		printf("Moved!\n");
		m_Size = other.m_Size;
		m_Data = other.m_Data;

		other.m_Size = 0;
		other.m_Data = nullptr;
	}

	String &operator = (String &&other) noexcept {
		printf("Moved!\n");
		
		if (this == &other) {
			delete[] m_Data;

			m_Size = other.m_Size;
			m_Data = other.m_Data;

			other.m_Size = 0;
			other.m_Data = nullptr;
		}
		return *this;
	}

	~String() {
		printf("Destroyed!\n");
		delete[] m_Data;
	}

	void Print() {
		for (uint32_t i = 0; i < m_Size; i++)
			printf("%c", m_Data[i]);
		printf("\n");
	}
};

class Entity {
private:
	String m_Name;

public:
	Entity(const String& name) : m_Name(name) {}

	//Entity(String &&name) : m_Name((String&&)name) {}
	Entity(String&& name) : m_Name(std::move(name)) {}

	void PrintName() {
		m_Name.Print();
	}
};

int main()
{
	// Entity entity("Cherno");
	// entity.PrintName();

	// // Entity entity2(String("Cherno2"));
	// // entity2.PrintName();

	// String string = "Hello";
	// // String dest((String&&)string);
	// // String dest = (String&&)string;
	// // String dest(std::move(string));
	// String dest = std::move(string);

	// // dest = std::move(string);

	String apple = "Apple";
	String dest;

	std::cout << "Apple: ";
	apple.Print();
	std::cout << "Dest: ";
	dest.Print();

	dest = std::move(apple);

	std::cout << "Apple: ";
	apple.Print();
	std::cout << "Dest: ";
	dest.Print();

	return 0;
}*/

#include <iostream>

class Name {
private:
	char* data;
	int size;

public:
	Name() = default;

	Name(const char* string) {
		std::cout << "Creado!\n";
		size = strlen(string);
		data = new char[size + 1];
		for (int i = 0; i < size; i++)
			data[i] = string[i];
		data[size] = '\0';
	}

	Name(const Name& other) {
		std::cout << "Copiado!\n";
		size = other.size;
		data = new char[size + 1];
		for (int i = 0; i < size; i++)
			data[i] = other.data[i];
		data[size] = '\0';
	}

	Name(Name&& other) noexcept {
		std::cout << "Movido!\n";
		size = other.size;
		data = other.data;

		other.size = 0;
		other.data = nullptr;
	}

	Name& operator = (Name&& other) noexcept {
		std::cout << "Movido!\n";

		if (this != &other) {
			delete[] data;

			size = other.size;
			data = other.data;

			other.size = 0;
			other.data = nullptr;
		}
		return *this;
	}

	~Name() {
		std::cout << "Destruido!\n";
		delete[] data;
	}

	void Print() {
		for (int i = 0; i < size; i++)
			std::cout << data[i];
		std::cout << "\n";
	}
};

class Person {
private:
	Name theirName;

public:
	Person(const Name& name) : theirName(name) {}

	//Person(Name &&name) : theirName((Name&&)name) {}
	Person(Name&& name) : theirName(std::move(name)) {}

	void PrintName() {
		theirName.Print();
	}
};

int main()
{
	 Person entity("Lewis");
	 entity.PrintName();

	 Name string = "Carl";
	 // Name other_string = std::move(string); // Move Constructor
	 Name other_string;

	 std::cout << "string: ";
	 string.Print();
	 std::cout << "other string: ";
	 other_string.Print();

	 other_string = std::move(string); // Assignment Operator 

	 std::cout << "string: ";
	 string.Print();
	 std::cout << "other string: ";
	 other_string.Print();

	return 0;
}