#include "DinamicDeque.hpp"

namespace dg {

	DinamicDeque::DinamicDeque() {

	}

	int DinamicDeque::front() {
		auto item = m_list.front();
		return (item) ? item->value : 0;
	}

	int DinamicDeque::back() {
		auto item = m_list.back();
		return (item) ? item->value : 0;
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