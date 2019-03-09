#include <iostream>
#include <vector>
#include <string>

#include "Tree.hpp"

template <typename T>
T prompt(const char label[]);

void preOrderSearch(dg::Tree::Node* node, int item, std::vector<int>& way);
void preOrder(dg::Tree::Node* node, std::vector<int>& way);
void getTree(dg::Tree& tree);
void printArr(std::vector<int> arr);
void printHello();

int main() {
	printHello();
	
	dg::Tree tree;

	getTree(tree);
	
	std::vector<int> items;
	preOrder(tree.getRoot(), items);

	std::cout << "Items of the tree (pre-order):\n";
	printArr(items);

	std::cout << std::endl;

	while (true) {
		int num = prompt<int>("Enter the number to search: ");
		std::vector<int> wayToNum;

		preOrderSearch(tree.getRoot(), num, wayToNum);
		printArr(wayToNum);

		std::cout << "\n- - - - - -\n\n";
	}

	system("pause");
	return 0;
}

void preOrderSearch(dg::Tree::Node* node, int item, std::vector<int>& way) {
	if (!node || (!way.empty() && way.back() == item)) return;
	way.push_back(node->value);

	preOrderSearch(node->left, item, way);
	preOrderSearch(node->right, item, way);
}

void preOrder(dg::Tree::Node* node, std::vector<int>& way) {
	if (!node) return;
	way.push_back(node->value);

	preOrder(node->left, way);
	preOrder(node->right, way);
}

void getTree(dg::Tree& tree) {
	auto root = tree.getRoot();

	auto* v1 = new dg::Tree::Node(1);
	auto* v2 = new dg::Tree::Node(2);
	auto* v3 = new dg::Tree::Node(3);
	auto* v4 = new dg::Tree::Node(4);
	auto* v5 = new dg::Tree::Node(5);
	auto* v6 = new dg::Tree::Node(6);
	auto* v7 = new dg::Tree::Node(7);
	auto* v8 = new dg::Tree::Node(8);

	root->value = 10;

	root->left = v2;
	root->right = v5;

	v2->left = v3;
	v2->right = v8;

	v5->left = v6;
	v5->right = v7;

	v7->left = v1;
	v7->right = v4;
}

void printArr(std::vector<int> arr) {
	for (auto &item : arr) {
		std::cout << item << " ";
	}

	std::cout << std::endl;
}

void printHello() {
	std::cout << "* * * Algorithms: Trees (part 1) * * *\n\n";
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