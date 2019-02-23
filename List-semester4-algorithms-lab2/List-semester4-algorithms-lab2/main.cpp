#include <iostream>
#include <string>

#include "List.hpp"

void writeList(dg::List &list);
void printList(dg::List &list);
void insert(dg::List& list);

template <typename T>
T prompt(const char label[]);

int main() {
	dg::List list;

	writeList(list);
	printList(list);
	insert(list);
	printList(list);

	system("pause");
	return 0;
}

void insert(dg::List& list) {
	int len = list.size();
	if (len % 2 == 0) len -= 1;

	std::cout << "Enter items to insert: " << std::endl;

	auto next = list.front();
	
	while (next) {
		auto current = next;
		next = next->next;
		list.insert(current, prompt<int>("> "));
	}
}

void writeList(dg::List &list) {
	unsigned int size = prompt<unsigned int>("Enter size of the List: ");

	std::cout << "Enter items:" << std::endl;

	for (int i = 0; i < size; i++) {
		list.pushBack(prompt<int>("> "));
	}
}

void printList(dg::List &list) {
	std::cout << "List: ";
	
	auto next = list.front();

	while (next) {
		std::cout << next->value << " ";
		next = next->next;
	}

	std::cout << std::endl;
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