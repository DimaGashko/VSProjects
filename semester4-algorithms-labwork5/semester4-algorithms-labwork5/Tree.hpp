#pragma once

namespace dg {

	class Tree {
	public:
		struct Node {
			int value = 0;
			Node* left = nullptr;
			Node* right = nullptr;
		};

		Tree();

		Node* getRoot();

		~Tree();

	private: 

		Node* m_root;

	};

}; // namespace dg
