#pragma once

#include "Point.h"

class Line {
public:
	Line();
	Line(Point p1, Point p2);
	Line(int x1, int y1, int x2, int y2);
	void show();
	void move(int x1, int y1, int x2, int y2);
	Point getP1();
	Point getP2();
	~Line() {};
private: 
	Point p1;
	Point p2;
};
