#pragma once

class Point {
public: 
	Point();
	Point(int x, int y);
	void show();
	void move(int x, int y);
	~Point() {};
private:
	int x;
	int y;
};