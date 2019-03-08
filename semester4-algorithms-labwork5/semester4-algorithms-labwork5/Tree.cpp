#include "Tree.hpp"

namespace dg {

	Tree::Tree(): 
		m_root(new Node())
	{

	}

	Tree::Node* Tree::getRoot() {
		return m_root;
	}

	Tree::~Tree() {
	
	}

}; // namespace dg