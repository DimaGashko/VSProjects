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
void addNumbersToSearchTree(dg::Tree& tree, int num);
void printItemsOnLevel(dg::Tree::Node* node, int level, int curLevel = 0);

int main() {
	printHello();
	run();

	system("pause");
	return 0;
}

void run() {
	dg::Tree tree;
	auto numbers = getNumberToSort();

	for (auto& num : numbers) {
		addNumbersToSearchTree(tree, num);
	}

	std::vector<int> sortedNumbers;
	inOrder(tree.getRoot(), sortedNumbers);

	std::cout << "Sorted items:\n";
	printArr(sortedNumbers);

	while (true) {
		std::cout << std::endl;
		int level = prompt<int>("Enter a level: ") - 1;
		std::cout << "Elements on level " << level + 1 << ": ";

		printItemsOnLevel(tree.getRoot(), level);
		std::cout << std::endl;
	}
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

void addNumbersToSearchTree(dg::Tree& tree, int num) {
	auto newNode = new dg::Tree::Node(num);
	dg::Tree::Node* next = tree.getRoot();

	if (!next) {
		tree.setRoot(newNode);
		return;
	}

	dg::Tree::Node* prev = next;

	while (next) {
		prev = next;
		next = (num < next->value) ? next->left : next->right;
	}

	if (num < prev->value) {
		prev->left = newNode;
	}
	else {
		prev->right = newNode;
	}
}

void printItemsOnLevel(dg::Tree::Node* node, int level, int curLevel) {
	if (!node) return;
	bool hasNext = curLevel < level;

	if (hasNext) printItemsOnLevel(node->left, level, curLevel + 1);
	if (!hasNext) std::cout << node->value << " ";
	if (hasNext) printItemsOnLevel(node->right, level, curLevel + 1);
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