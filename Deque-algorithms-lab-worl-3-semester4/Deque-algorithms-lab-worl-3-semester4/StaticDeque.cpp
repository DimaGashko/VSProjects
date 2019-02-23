#include "StaticDeque.hpp"

namespace dg {

	StaticDeque::StaticDeque(unsigned int capacity):
		m_capacity(capacity),
		m_items(capacity)
	{

	}


	StaticDeque::~StaticDeque() {

	}

}