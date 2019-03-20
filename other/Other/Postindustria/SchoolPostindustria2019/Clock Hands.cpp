#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <cmath>

struct Time {
	int h, m;
};

double getAngleOfClockHands(Time time);
Time parseTime(std::string strTime);

int main() {
	while (true) {
		std::string strTime;
		std::cin >> strTime;

		if (strTime == "0:00") {
			break;
		}

		auto time = parseTime(strTime);
		double angle = getAngleOfClockHands(time);

		printf("%.3f\n", angle);
	}

	system("pause");
	return 0;
}

double getAngleOfClockHands(Time time) {
	double hAngle = (360 / 12) * (time.h % 12) +
		(360.f / 12 / 60) * time.m;

	double mAngle = (360 / 60) * (time.m % 60);

	double angle = abs(hAngle - mAngle);
	if (angle > 180) angle = 360 - angle;

	return angle;
}

Time parseTime(std::string strTime) {
	Time time;

	auto delimiter = std::find(strTime.begin(), strTime.end(), ':');

	time.h = atoi(std::string(strTime.begin(), delimiter).c_str());
	time.m = atoi(std::string(delimiter + 1, strTime.end()).c_str());

	return time;
}