#include <iostream>
#include "Point.h"

using namespace std;

Point::Point() {
	this->x = 0;
	this->y = 0;
}

Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
}

void Point::show() {
	cout << "x: " << x << "; y: " << y << endl;
}

void Point::move(int x, int y) {
	this->x += x;
	this->y += y;
}