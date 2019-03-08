#pragma once

namespace dg {

	class Tree {
	public:
		struct Node {
			int value;
			Node* left = nullptr;
			Node* right = nullptr;
		};

		Tree();

		Node* getLeft();
		Node* getRight();

		~Tree();

	private: 

		Node* m_left = nullptr;
		Node* m_right = nullptr;

	};

}; // namespace dg
