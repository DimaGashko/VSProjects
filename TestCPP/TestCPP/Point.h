#pragma once

class Point {
public: 
	Point();
	Point(int x, int y);
	void show();
	void move(int dx, int dy);
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
	~Point() {};
private:
	int x;
	int y;
};