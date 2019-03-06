#include <iostream>
#include <cmath>

const double DEF_EPSILON = 0.0001;

double getF(double x) {
	return sin(x);
}

double bisection(double l, double r, double eps = DEF_EPSILON);
double bisectionIterative(double l, double r, double eps = DEF_EPSILON);

double falsePosition(double l, double r, double eps = DEF_EPSILON);
double falsePositionIterative(double l, double r, double eps = DEF_EPSILON);

void checkRange(double l, double r);

int main() {

	while (true) {

		double l, r, res;
		std::cin >> l >> r;

		try {
			res = bisection(l, r);
			std::cout << res << std::endl;
		}
		catch (std::runtime_error err) {
			std::cout << err.what() << std::endl;
		}

	}

	system("pause");
	return 0;
}

double bisection(double l, double r, double eps) {
	checkRange(l, r);

	double m = (l + r) / 2;
	double ym = getF(m);

	if (abs(ym) <= eps) return m;

	if (ym * getF(l) < 0) return bisection(l, m);
	else return bisection(m, r);
}

double bisectionIterative(double l, double r, double eps) {
	checkRange(l, r);

	double m, mVal;

	while (true) {
		m = (l + r) / 2;
		mVal = getF(m);

		if (abs(mVal) <= eps) {
			break;
		}

		if (mVal * getF(l) < 0) r = m;
		else l = m;
	}

	return m;
}

double falsePosition(double l, double r, double eps = DEF_EPSILON) {
	checkRange(l, r);


}

void checkRange(double l, double r) {
	if (getF(l) * getF(r) < 0) return;

	throw std::runtime_error("No roots on this range");
}