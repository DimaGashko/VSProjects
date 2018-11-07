#pragma once

#include "Point.h"

class Line {
public:
	Line();
	Line(int x1, int y1, int x2, int y2);
	void show();
	void move(int dx, int dy);
	void scale(int scaleX, int scaleY);
	void rotate(double angle);
	double squereLen();
	~Line();
private: 
	Point *p1;
	Point *p2;
};
