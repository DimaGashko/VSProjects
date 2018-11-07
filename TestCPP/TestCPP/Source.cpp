#include <iostream>
#include "Point.h"
#include "Line.h"

#include <vector>

using namespace std;

int main() {
	Line l1(0, 0, 5, 5);
	Line l2(-5, -5, 10, 10);

	l1.show();
	l2.show();

	cout << "- - - - -" << endl;

	l1.move(10, 10);
	l2.move(20, 20);

	l1.show();
	l2.show(); 

	system("pause");
	return 0;
}