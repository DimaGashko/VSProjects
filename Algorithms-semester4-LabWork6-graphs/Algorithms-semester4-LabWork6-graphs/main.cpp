#include <iostream>
#include <vector>
#include <string>
#include <list>

void printHello();

template <typename T>
T prompt(const char label[]);

int main() {
	printHello();

	while (true) {
		std::cout << "App" << std::endl;

		if (prompt<std::string>("\nRepeat? (0 to exit): ") == "0") {
			break;
		}

		std::cout << "\n- - - - - - - - - -\n\n";
	}

	return 0;
}

void printHello() {
	std::cout << "* * * Algorithms: Dijkstra's algorithm * * *\n\n";
}

template <typename T>
T prompt(const char label[]) {
	std::cout << label;

	while (true) {
		T val;
		std::cin >> val;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Wrong. Try again: ";
		}
		else {
			std::cin.ignore(32767, '\n');
			return val;
		}

	}

}