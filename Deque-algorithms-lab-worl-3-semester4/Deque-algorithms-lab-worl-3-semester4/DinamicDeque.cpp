#include "DinamicDeque.hpp"

namespace dg {

	DinamicDeque::DinamicDeque() {

	}

	int DinamicDeque::front() {
		m_list.front();
	}

	int DinamicDeque::back() {
		m_list.back();
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
		m_list.size();
	}

	void DinamicDeque::clear() {
		m_list.clear();
	}

	DinamicDeque::~DinamicDeque() {
		
	}

}; // namespace dg