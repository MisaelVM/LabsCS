#include <iostream>

// MOVE SEMANTICS

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

	// COPY CONSTRUCTOR
	Name(const Name& other) {
		std::cout << "Copiado!\n";
		size = other.size;
		data = new char[size + 1];
		for (int i = 0; i < size; i++)
			data[i] = other.data[i];
		data[size] = '\0';
	}

	// MOVE CONSTRUCTOR
	Name(Name&& other) noexcept {
		std::cout << "Movido!\n";
		size = other.size;
		data = other.data;

		other.size = 0;
		other.data = nullptr;
	}

	// MOVE ASSIGNMENT OPERATOR
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

	// DESTRUCTOR
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