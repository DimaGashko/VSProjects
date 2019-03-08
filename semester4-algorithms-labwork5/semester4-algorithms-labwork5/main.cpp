#include <iostream>
#include <vector>
#include <string>

#include "Tree.hpp"

template <typename T>
T prompt(const char label[]);

int main() {
	
	dg::Tree tree;

	auto root = tree.getRoot();
	dg::Tree::Node v1, v2, v3, v4, v5, v6, v7, v8;

	v1 = dg::Tree::Node(2);
	v2 = dg::Tree::Node(4);
	v3 = dg::Tree::Node(6);
	v4 = dg::Tree::Node(8);
	v5 = dg::Tree::Node(10);
	v6 = dg::Tree::Node(12);
	v7 = dg::Tree::Node(14);
	v8 = dg::Tree::Node(16);

	root.value = 2;

	root.left

	return 0;
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