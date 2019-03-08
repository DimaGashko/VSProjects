#include <iostream>
#include <vector>
#include <string>

#include "Tree.hpp"

template <typename T>
T prompt(const char label[]);

void preOrder(dg::Tree::Node* node, std::vector<int>& way);
void printArr(std::vector<int> arr);
void printHello();

int main() {
	printHello();

	

	system("pause");
	return 0;
}

void preOrder(dg::Tree::Node * node, std::vector<int> & way) {
	if (!node) return;
	way.push_back(node->value);

	preOrder(node->left, way);
	preOrder(node->right, way);
}

void printArr(std::vector<int> arr) {
	for (auto& item : arr) {
		std::cout << item << " ";
	}

	std::cout << std::endl;
}

void printHello() {
	std::cout << "* * * Algorithms: Trees (part 2) * * *\n\n";
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