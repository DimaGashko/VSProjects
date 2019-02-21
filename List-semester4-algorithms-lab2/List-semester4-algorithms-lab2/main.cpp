#include <iostream> // 2/21/2019 5:37 pm

#include "List.hpp"

int main() {

	dg::List list;

	int value = 0;

	while (std::cin >> value) {
		list.pushBack(value);
	}

	std::cout << "Size: " << list.size() << std::endl;

	auto next = list.front();

	while (next) {
		std::cout << next->value << " ";
		next = next->next;
	}

	std::cout << std::endl;

	system("pause");
	return 0;
}