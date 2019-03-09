#pragma once

namespace dg {

	class Tree {
	public:
		struct Node {
			Node() : value(0) {}
			Node(int value) : value(value) {}

			int value;
			Node* left = nullptr;
			Node* right = nullptr;
		};

		Tree() {};

		Node* getRoot() {
			return m_root;
		}

		void setRoot(Node* node) {
			m_root = node;
		}

		~Tree() {};

	private:

		Node* m_root = nullptr;

	};

}; // namespace dg
