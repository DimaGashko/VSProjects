#pragma once

#include "./List.hpp"
#include "IDeque.hpp"

namespace dg {

	class DinamicDeque : public IDeque {

	public:
		DinamicDeque();

		int front();
		int back();

		void pushFront(int value);
		void pushBack(int value);

		void popFront();
		void popBack();

		int size();

		void clear();

		~DinamicDeque();

	private:

		List m_list;

	};

}; // namespace dg

