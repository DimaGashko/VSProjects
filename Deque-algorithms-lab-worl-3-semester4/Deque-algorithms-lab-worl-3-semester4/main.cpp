#include <iostream>

#include "StaticDeque.hpp"
#include "DinamicDeque.hpp"
#include "Deque.hpp"

void printHello();
dg::Deque* createDeque();

template <typename T>
T prompt(const char label[]);

int main() {
	printHello();

	dg::Deque* deque = createDeque();

	system("pause");
	return 0;
}

dg::Deque* createDeque() {
	int type = prompt<int>("Select Deque type\n(if 1 - static, otherwise - dinamic): ");

	if (type == 1) {
		int capacity = prompt<unsigned short>("Enter capacity: ");
		return new dg::StaticDeque(capacity);
	}
	else {
		return new dg::DinamicDeque;
	}
}

void printHello() {
	std::cout << "= = = Console Deque = = =\n\n";
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