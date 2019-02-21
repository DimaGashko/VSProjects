#include <iostream> // 2/21/2019 5:37 pm

#include "List.hpp"

int main() {

	dg::List list;

	list.pushBack(5);
	list.pushBack(15);
	list.pushBack(12);
	list.pushBack(13);
	list.pushBack(20);

	std::cout << "Hello, World" << std::endl;

	system("pause");
	return 0;
}