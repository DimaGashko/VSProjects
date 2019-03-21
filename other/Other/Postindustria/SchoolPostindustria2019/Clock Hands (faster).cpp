#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <cmath>

double getAngleOfClockHands(int h, int m);

int main() {
	while (true) {
		std::string strTime;
		std::cin >> strTime;

		if (strTime == "0:00") {
			break;
		}

		auto delimiter = strTime.begin();
		delimiter += (strTime[1] == ':') ? 1 : 2;

		int h = atoi(std::string(strTime.begin(), delimiter).c_str());
		int m = atoi(std::string(delimiter + 1, strTime.end()).c_str());

		double angle = getAngleOfClockHands(h, m);

		printf("%.3f\n", angle);
	}

	system("pause");
	return 0;
}

double getAngleOfClockHands(int h, int m) {
	double hAngle = (360 / 12) * (h % 12) +
		(360.f / 12 / 60) * m;

	double mAngle = (360 / 60) * (m % 60);

	double angle = abs(hAngle - mAngle);
	if (angle > 180) angle = 360 - angle;

	return angle;
}