#include <iostream>
#include <cmath>

const double DEF_EPSILON = 0.00001;

double getF(double x) {
	return log10(x) - 7 / (2 * x + 6);
}

double getFPrime(double x) {
	return 1 / (x * log(10)) + 14 / ((2 * x + 6) * (2 * x + 6));
}

double getG(double x) {
	return x - 4.13 * getF(x);
}

double bisection(double l, double r, int& k, double eps = DEF_EPSILON);
double bisection_iterative(double l, double r, int& k, double eps = DEF_EPSILON);

double falsePosition(double l, double r, int& k, double eps = DEF_EPSILON);
double falsePosition_iterative(double l, double r, int& k, double eps = DEF_EPSILON);

double newtonRaphsan(double l, double r, int& k, double eps = DEF_EPSILON);
double newtonRaphsan_iterative(double l, double r, int& k, double eps = DEF_EPSILON);

double iterative(double x0, int& k, double eps = DEF_EPSILON);
double iterative_iterative(double x0, int& k, double eps = DEF_EPSILON);

void checkRoots(double l, double r);

int main() {

	while (true) {

		int k;
		double l, r, res;
		std::cin >> l >> r;

		try {
			//res = falsePosition(l, r);
			res = iterative_iterative((l + r) / 2, k);
			std::cout << res << std::endl;
		}
		catch (std::runtime_error err) {
			std::cout << err.what() << std::endl;
		}

	}

	system("pause");
	return 0;
}

double bisection(double l, double r, int& k, double eps) {
	checkRoots(l, r);

	double m = (l + r) / 2;
	double ym = getF(m);

	if (abs(ym) < eps || abs(r - l) < eps) return m;

	if (ym * getF(l) < 0) return bisection(l, m, k);
	else return bisection(m, r, k);
}

double bisection_iterative(double l, double r, int& k, double eps) {
	checkRoots(l, r);

	double m, mVal;

	while (true) {
		m = (l + r) / 2;
		mVal = getF(m);

		if (abs(mVal) <= eps || abs(r - l) < eps) {
			break;
		}

		if (mVal * getF(l) < 0) r = m;
		else l = m;
	}

	return m;
}

double falsePosition(double l, double r, int& k, double eps) {
	checkRoots(l, r);

	double ly = getF(l);
	double ry = getF(r);

	double mx = l - ly * (r - l) / (ry - ly);
	double my = getF(mx);

	if (abs(my) <= eps || abs(r - l) < eps) {
		return mx;
	}

	if (ly * my < 0) return falsePosition(l, mx, k);
	else return falsePosition(mx, r, k);
}


double falsePosition_iterative(double l, double r, int& k, double eps) {
	checkRoots(l, r);

	double ly, ry, mx, my;

	while (true) {
		ly = getF(l);
		ry = getF(r);

		mx = l - ly * (r - l) / (ry - ly);
		my = getF(mx);

		if (abs(my) <= eps || abs(r - l) < eps) {
			break;
		}

		if (ly * my < 0) r = mx;
		else l = mx;
	}

	return mx;
}

double newtonRaphsan(double l, double r, int& k, double eps) {
	if (abs(r - l) < eps) return (l + r) / 2;

	if (getF(r) * getFPrime(r) > 0) std::swap(l, r);
	double x = l - getF(l) / getFPrime(l);

	if (abs(x - l) < eps) return x;
	return newtonRaphsan(x, r, k, eps);
}

double newtonRaphsan_iterative(double l, double r, int& k, double eps) {
	checkRoots(l, r);
	double x;

	while (true) {
		if (abs(r - l) < eps) {
			x = (l + r) / 2;
			break;
		}

		if (getF(r) * getFPrime(r) > 0) std::swap(l, r);
		x = l - getF(l) / getFPrime(l);

		if (abs(x - l) < eps) break;
		l = x;
	}

	return x;
}

double iterative(double x0, int& k, double eps) {
	double x1 = getG(x0);
	if (abs(x1 - x0) <= eps) return x0;

	return iterative(x1, k);
}

double iterative_iterative(double x0, int& k, double eps) {
	while (true) {
		double x1 = getG(x0);
		if (abs(x1 - x0) <= eps) break;

		x0 = x1;
	}

	return x0;
}

void checkRoots(double l, double r) {
	if (getF(l) * getF(r) < 0) return;

	throw std::runtime_error("No roots on this range");
}