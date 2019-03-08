#include <iostream>
#include <vector>
#include <string>

#include "Tree.hpp"

template <typename T>
T prompt(const char label[]);

int main() {
	
	dg::Tree tree;

	auto root = tree.getRoot();
	dg::Tree::Node *v1, *v2, *v3, *v4, *v5, *v6, *v7, *v8;

	v1 = new dg::Tree::Node(2);
	v2 = new dg::Tree::Node(4);
	v3 = new dg::Tree::Node(6);
	v4 = new dg::Tree::Node(8);
	v5 = new dg::Tree::Node(10);
	v6 = new dg::Tree::Node(12);
	v7 = new dg::Tree::Node(14);
	v8 = new dg::Tree::Node(16);

	root.value = 99;

	root.left = v2;
	root.right = v5;

	v2->left = v3;
	v2->right = v8;

	v5->left = v6;
	v5->right = v7;

	v7->left = v1;
	v7->right = v4;
	system("pause");
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