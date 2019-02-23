#include <iostream>

#include "StaticDeque.hpp"

int main() {
	dg::StaticDeque deque(6);

	deque.pushBack(1);
	deque.pushBack(2);
	deque.pushBack(3);
	deque.pushBack(4);
	deque.pushBack(5);
	deque.pushBack(6);
	deque.pushBack(7);

	return 1;
}