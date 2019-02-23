#pragma once

#include <iostream>
#include <vector>

namespace dg {

	class StaticDeque {
	public:
		StaticDeque(unsigned int capacity);

		int front();
		int back();

		int popFront();
		int popBack();

		void pushFront(int value);
		void pushBack(int value);

		int size();

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

