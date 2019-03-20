#include <iostream>
#include <stdlib.h>
#include <string>
#include <cmath>

struct Time {
	int h;
	int m;
};

int getClockHandsAngle(Time time);
Time parseTime(std::string strTime);

int main() {
	while (true) {
		std::string strTime;
		std::cin >> strTime;

		if (strTime == "0:00") {
			break;
		}

		auto time = parseTime(strTime);
		auto angle = getClockHandsAngle(time);

		std::cout << 
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
	return angle;
}

Time parseTime(std::string strTime) {
	Time time;

	auto delimiter = std::find(strTime.begin(), strTime.end(), ':');

	time.h = atoi(std::string(strTime.begin(), delimiter).c_str());
	time.m = atoi(std::string(delimiter + 1, strTime.end()).c_str());

	return time;
}