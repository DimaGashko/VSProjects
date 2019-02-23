#pragma once

#include <iostream>
#include <vector>

#include "IDeque.hpp"

namespace dg {

	class StaticDeque: public IDeque {
	public:
		StaticDeque(unsigned int capacity = 16);

		int front();
		int back();

		void pushFront(int value);
		void pushBack(int value);

		void popFront();
		void popBack();

		int size();
		int capacity();

		~StaticDeque();

	private:

		int m_size = 0;
		int m_capacity;

		std::vector<int> m_items;

		int m_front = 0;
		int m_back = 0;

		int _toIndex(int index);
		void _checkCanAdd();

	};

}; // namespace dg

