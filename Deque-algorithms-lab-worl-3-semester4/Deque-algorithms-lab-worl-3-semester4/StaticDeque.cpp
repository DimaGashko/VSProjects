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

	StaticDeque::~StaticDeque() {

	}

}