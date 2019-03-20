#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct Time {
	int h;
	int m;
};

int getClockHandsAngle(Time time);
Time parseTime(std::string strTime);

int main() {
	

	while (true) {


	}

	system("pause");
	return 0;
}

int getClockHandsAngle(Time time) {
	// hAngle & mAndle are always int if h & m are int
	// That's why result angle is int too
	int hAngle = 360 / 12 * (time.h % 12);
	int mAngle = 360 / 60 * (time.m % 60);

	int angle = abs(hAngle - mAngle) % 180;
}

Time parseTime(std::string strTime) {

}