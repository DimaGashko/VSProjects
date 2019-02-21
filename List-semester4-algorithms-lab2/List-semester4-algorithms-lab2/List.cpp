#include "List.hpp"

namespace dg {

	List::List():
		m_size(0)
	{

	}

	List::Node* List::front() {
		return m_head.next;
	}

	List::Node* List::back() {
		return m_back;
	}

	List::~List() {

	}

}; // namespace dg
