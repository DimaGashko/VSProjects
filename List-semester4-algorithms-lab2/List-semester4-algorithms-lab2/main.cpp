#include <iostream>

#include "List.hpp"

void writeList(dg::List &list);
void printList(dg::List &list);

int main() {
	dg::List list;

	writeList(list);
	printList(list);

	system("pause");
	return 0;
}

void writeList(dg::List &list) {
	int nextValue = 0;

	std::cout << "Enter items of the list" << std::endl;
	std::cout << "(enter no number to complete the input)" << std::endl;

	for (int i = 0; i < 2; i++) {
		std::cin >> nextValue;
		list.pushBack(nextValue);
	}
}

void printList(dg::List &list) {
	auto next = list.front();

	while (next) {
		std::cout << next->value << " ";
		next = next->next;
	}

	std::cout << std::endl;
}