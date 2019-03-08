#include <iostream>
#include <vector>
#include <string>

#include "Tree.hpp"

template <typename T>
T prompt(const char label[]);

void preOrder(dg::Tree::Node* node, int item, std::vector<int>& way);
void getTree(dg::Tree& tree);

int main() {
	
	dg::Tree tree;
	getTree(tree);

	std::vector<int> way;
	preOrder(tree.getRoot(), 7, way);

	for (auto& item : way) {
		std::cout << item << " ";
	}

	system("pause");
	return 0;
}

void preOrder(dg::Tree::Node* node, int item, std::vector<int>& way) {
	if (!node || (!way.empty() && way.back() == item)) return;
	way.push_back(node->value);

	preOrder(node->left, item, way);
	preOrder(node->right, item, way);
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