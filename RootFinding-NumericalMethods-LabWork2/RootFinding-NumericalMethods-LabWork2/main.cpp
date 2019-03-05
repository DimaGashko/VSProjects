#include <iostream>
#include <cmath>

const double DEF_EPSILON = 0.0001;

double getF(double x) {
	return sin(x);
}

double bisection(double l, double r, double eps = DEF_EPSILON);

int main() {

	while (true) {

		double l, r;
		std::cin >> l >> r;

		std::cout << bisection(l, r) << std::endl;

	}

	system("pause");
	return 0;
}

double bisection(double l, double r, double eps) {
	double middle = getF((l + r) / 2);
	if (abs(middle) <= eps) return middle;

	if (middle * l < 0) return bisection(l, middle);
	else return bisection(middle, r);
}