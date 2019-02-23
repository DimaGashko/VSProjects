#include "StaticDeque.hpp"

namespace dg {

	StaticDeque::StaticDeque(unsigned int capacity):
		m_capacity(capacity),
		m_items(capacity)
	{

	}

	int StaticDeque::size() {
		return m_size;
	}

	int StaticDeque::_toIndex(int index) {
		if (index < 0) index = m_capacity + index;
		return index % m_capacity;
	}

	StaticDeque::~StaticDeque() {

	}

}