#include <iostream>
#include "Point.h"

using namespace std;

Point::Point(): x(0), y(0) {

}

Point::Point(int x, int y): x(x), y(y) {
	
}

void Point::show() {
	cout << "(" << x << "; " << y  << ")";
}

void Point::move(int dx, int dy) {
	x += dx;
	y += dy;
}

void Point::setX(int x) {
	this->x = x;
}

void Point::setY(int y) {
	this->y = y;
}

int Point::getX() {
	return x;
}

int Point::getY() {
	return y;
}