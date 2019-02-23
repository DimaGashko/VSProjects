#include <iostream>

#include "StaticDeque.hpp"
#include "DinamicDeque.hpp"

int main() {
	int size = 10;
	dg::StaticDeque deque(size + 1);

	deque.pushBack(55);
	deque.pushBack(55);
	deque.pushBack(55);
	deque.pushBack(55);
	deque.pushBack(55);

	deque.popFront();
	deque.popFront();
	deque.popFront();
	deque.popFront();

	for (int i = 0; i < size; i++) {
		deque.pushFront(i + 1);
	}

	while (deque.size()) {
		int item = deque.front();
		deque.popFront();

		std::cout << item << " ";
	}

	std::cout << std::endl;

	system("pause");
	return 1;
}