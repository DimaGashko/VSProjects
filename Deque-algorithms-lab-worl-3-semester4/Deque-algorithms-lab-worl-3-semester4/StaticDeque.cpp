#include "StaticDeque.hpp"

namespace dg {

	StaticDeque::StaticDeque(unsigned int capacity):
		m_capacity(capacity),
		m_items(capacity)
	{

	}

	int StaticDeque::front() {
		return m_items[m_front];
	}

	int StaticDeque::back() {
		return m_items[m_back];
	}

	void StaticDeque::pushFront(int value) {
		_checkCanAdd();

		if (m_size != 0) {
			m_front = _toIndex(m_front - 1);
		}
		
		m_size++;
		m_items[m_front] = value;
	}

	void StaticDeque::pushBack(int value) {
		_checkCanAdd();

		if (m_size != 0) {
			m_back = _toIndex(m_back + 1);
		}

		m_size++;
		m_items[m_back] = value;
	}

	void StaticDeque::popFront() {
		if (m_size == 0) return;
		m_size--;
		if (m_size == 0) return;

		m_front = _toIndex(m_front + 1);
	}

	void StaticDeque::popBack() {
		if (m_size == 0) return;
		m_size--;
		if (m_size == 0) return;

		m_back = _toIndex(m_back - 1);
	}

	int StaticDeque::size() {
		return m_size;
	}

	inline
	int StaticDeque::_toIndex(int index) {
		if (index < 0) index = m_capacity + index;
		return index % m_capacity;
	}

	inline
	void StaticDeque::_checkCanAdd() {
		if (m_size < m_capacity) return;

		throw std::runtime_error("Capacity overflow");
	}

	StaticDeque::~StaticDeque() {

	}

}