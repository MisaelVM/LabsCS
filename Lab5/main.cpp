#include <sstream>

#include "LinkedList.h"

int main()
{
	LinkedList lnk;
	std::string stream;
	enum input { INSERT = 1, REMOVE, PRINT, KILL };
	int option = 0;
	while (option != KILL) {
		system("cls");
		std::cout << "1)Insert\n";
		std::cout << "2)Remove\n";
		std::cout << "3)Print\n";
		std::cout << "4)Kill\n";
		std::cin >> option;
		std::cout << "\n";
		switch (option) {
		case INSERT:
			std::cout << "You are now inserting elements. Press F to quit...\n";
			std::cout << "\nElement: ";
			std::cin >> stream;
			while (stream != "F") {
				int x;
				std::stringstream converter(stream);
				converter >> x;
				lnk.insert(x);
				lnk.print();
				std::cout << "\nElement: ";
				std::cin >> stream;
			}
			break;
		case REMOVE:
			std::cout << "You are now removing elements. Press F to quit...\n";
			std::cout << "\nElement: ";
			std::cin >> stream;
			while (stream != "F") {
				int x;
				std::stringstream converter(stream);
				converter >> x;
				lnk.remove(x);
				lnk.print();
				std::cout << "\nElement: ";
				std::cin >> stream;
			}
			break;
		case PRINT:
			std::cout << "The list has the following elements:\n";
			lnk.print();
			std::cout << "\nPress ENTER to continue...";
			std::cin.get(); std::cin.get();
			break;
		case KILL:
			break;
		default:
			std::cout << "Invalid input\n";
			std::cout << "\nPress ENTER to continue...";
			std::cin.get(); std::cin.get();
			break;
		}
	}
	return 0;
}