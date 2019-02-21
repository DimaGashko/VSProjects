#include <iostream> // 2/21/2019 5:37 pm

#include "List.hpp"

int main() {

	dg::List list;

	list.pushBack(5);
	list.pushBack(15);
	list.pushBack(12);
	list.pushBack(13);
	list.pushBack(20);

	auto a = list.getByIndex(-1);
	int b = 5;
	auto c = list.getByIndex(0)->value;
	b = 10;
	c = list.getByIndex(1)->value;
	b = 10;
	c = list.getByIndex(2)->value;
	b = 10;
	c = list.getByIndex(3)->value;
	b = 10;
	c = list.getByIndex(4)->value;
	b = 10;
	a = list.getByIndex(5);

	std::cout << "Hello, World" << std::endl;

	system("pause");
	return 0;
}