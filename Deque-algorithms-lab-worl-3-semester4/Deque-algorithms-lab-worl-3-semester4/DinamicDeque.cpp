#include "DinamicDeque.hpp"

namespace dg {

	DinamicDeque::DinamicDeque() {

	}

	int DinamicDeque::front() {
		return m_list.front()->value;
	}

	int DinamicDeque::back() {
		return m_list.back()->value;
	}

	void DinamicDeque::pushFront(int value) {
		m_list.pushFront(value);
	}

	void DinamicDeque::pushBack(int value) {
		m_list.pushBack(value);
	}

	void DinamicDeque::popFront() {
		m_list.popFront();
	}

	void DinamicDeque::popBack() {
		m_list.popBack();
	}

	int DinamicDeque::size() {
		return m_list.size();
	}

	void DinamicDeque::clear() {
		m_list.clear();
	}

	DinamicDeque::~DinamicDeque() {
		
	}

}; // namespace dg