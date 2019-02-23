#pragma once

namespace dg {

	class IDeque {

	public:

		virtual int front() = 0;
		virtual int back() = 0;

		virtual void pushFront(int value) = 0;
		virtual void pushBack(int value) = 0;

		virtual void popFront() = 0;
		virtual void popBack() = 0;

		virtual int size() = 0;

	};

}

