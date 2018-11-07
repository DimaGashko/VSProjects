#include <iostream>

#include "Line.h"
#include "Point.h"

using namespace std;

Line::Line() {
	p1 = new Point(0, 0);
	p2 = new Point(0, 0);
}

Line::Line(int x1, int y1, int x2, int y2) {
	p1 = new Point(x1, y1);
	p2 = new Point(x2, y2);
}

void Line::move(int dx, int dy) {
	p1->move(dx, dy);
	p2->move(dx, dy);
}

void Line::scale(int scaleX, int scaleY) {
	int newX1 = scaleX * p1->getX();
	int newX2 = scaleX * p2->getX();
	int newY1 = scaleY * p1->getY();
	int newY2 = scaleY * p2->getY();

	p1->setX(newX1);
	p2->setX(newX2);
	p1->setY(newY1);
	p2->setY(newY2);
}

void Line::rotate(double angle) {
	int _x2 = p2->getX() - p1->getX();
	int _y2 = p2->getY() - p1->getY();

	p2->setX(_x2 * cos(angle) - _y2 * sin(angle) + p1->getX());
	p2->setY(_y2 * cos(angle) + _x2 * sin(angle) + p1->getX());
}

double Line::squereLen() {
	int dx = p1->getX() - p2->getX();
	int dy = p1->getY() - p2->getY();

	return dx * dx + dy * dy;
}

Line::~Line() {
	if (this->p1) delete this->p1;
	if (this->p2) delete this->p2;
}



void Line::show() {
	cout << "[";
	p1->show();
	cout << ", ";
	p2->show();
	cout << "]" << endl;
}

