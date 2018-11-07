#include <iostream>

#include "Line.h"
#include "Point.h"

using namespace std;

Line::Line() {
	p1 = Point(0, 0);
	p2 = Point(0, 0);
}

Line::Line(Point p1, Point p2) {
	this->p1 = p1;
	this->p2 = p2;
}

Line::Line(int x1, int y1, int x2, int y2) {
	p1 = Point(x1, y1);
	p2 = Point(x2, y2);
}

void Line::move(int x1, int y1, int x2, int y2) {
	p1.move(x1, y1);
	p2.move(x2, y2);
}

void Line::show() {
	cout << "p1: ";
	p1.show();
	cout << "p2: ";
	p2.show();
}

Point Line::getP1() {
	return p1;
}

Point Line::getP2() {
	return p2;
}
