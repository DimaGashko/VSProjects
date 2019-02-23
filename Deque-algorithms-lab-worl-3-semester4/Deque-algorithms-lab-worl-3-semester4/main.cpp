#include <iostream>

#include "StaticDeque.hpp"

int main() {
	int size = 6;
	dg::StaticDeque deque(size);

	for (int i = 0; i < size; i++) {
		deque.pushBack(i);
	}

	while (deque.size()) {
		int item = deque.back();
		deque.popBack();

		std::cout << item << " ";
	}

	std::cout << std::endl;

	system("pause");
	return 1;
}