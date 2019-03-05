#include <iostream>
#include <cmath>

const double DEF_EPSILON = 0.0000000000000000000000001;

double getF(double x) {
	return sin(x);
}

double bisection(double l, double r, double eps = DEF_EPSILON);
double bisectionIterative(double l, double r, double eps = DEF_EPSILON);

int main() {

	while (true) {

		double l, r;
		std::cin >> l >> r;

		std::cout << bisectionIterative(l, r) << std::endl;

	}

	system("pause");
	return 0;
}

double bisection(double l, double r, double eps) {
	double m = (l + r) / 2;
	double mVal = getF(m);

	if (abs(mVal) <= eps) return m;

}

double bisectionIterative(double l, double r, double eps) {
	double m, mVal;

	do {
		m = (l + r) / 2;
		mVal = getF(m);

		if (mVal * getF(l) < 0) r = m;
		else l = m;

	} while (abs(mVal) > eps);

	return m;
}