#include <iostream>
#include <vector>
#include <string>

#include "Tree.hpp"

template <typename T>
T prompt(const char label[]);

void inOrder(dg::Tree::Node* node, std::vector<int>& way);
void printArr(std::vector<int> arr);
void printHello();
void run();

std::vector<int> getNumberToSort();

int main() {
	printHello();
	run();

	system("pause");
	return 0;
}

void run() {
	dg::Tree tree;
	
	auto numbers = getNumberToSort();

	printArr(numbers);
}

std::vector<int> getNumberToSort() {
	auto size = prompt<int>("Enter the number of a numbers to sort: ");
	std::vector<int> numbers(size);

	std::cout << "Enter numbers to sort:\n";

	for (auto& num : numbers) {
		std::cin >> num;
	}

	return numbers;
}

void inOrder(dg::Tree::Node * node, std::vector<int> & way) {
	if (!node) return;

	inOrder(node->left, way);
	way.push_back(node->value);

	inOrder(node->right, way);
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