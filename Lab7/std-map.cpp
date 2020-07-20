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
}