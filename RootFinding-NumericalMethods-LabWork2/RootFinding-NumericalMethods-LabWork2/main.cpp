#include <iostream>
#include <string>
#include <cmath>

const double DEF_EPSILON = 0.00001;
int iterativeCounter = 0;

double getF(double x) {
	return log10(x) - 7 / (2 * x + 6);
}

double getFPrime(double x) {
	return 1 / (x * log(10)) + 14 / ((2 * x + 6) * (2 * x + 6));
}

double getG(double x) {
	return x - 4.13 * getF(x);
}

double bisection(double l, double r, double eps = DEF_EPSILON);
double bisection_recursive(double l, double r, double eps = DEF_EPSILON);

double falsePosition(double l, double r, double eps = DEF_EPSILON);
double falsePosition_recursive(double l, double r, double eps = DEF_EPSILON);

double newtonRaphsan(double l, double r, double eps = DEF_EPSILON);
double newtonRaphsan_recursive(double l, double r, double eps = DEF_EPSILON);

double iterative(double x0, double eps = DEF_EPSILON);
double iterative_recursive(double x0, double eps = DEF_EPSILON);

void printResult(std::string method, double res);
void checkRoots(double l, double r);
void clearIterativeCounter();
void run();

template <typename T>
T prompt(const char label[]);

int main() {

	while (true) {
		run();

		if (prompt<std::string>("Repeat (0 - no): ") == "0") {
			break;
		}
	}

	return 0;
}

void run() {
	std::cout << "Enter [a, b]:" << std::endl;
	double l = prompt<double>("a: ");
	double r = prompt<double>("b: ");

	try {
		checkRoots(l, r);

		printResult("Bisection Method", bisection(l, r));
		clearIterativeCounter();

		printResult("Bisection Method", bisection(l, r));
		clearIterativeCounter();
	}
	catch (std::runtime_error err) {
		std::cout << err.what() << std::endl;
	}
}

void printResult(std::string method, double res) {
	std::cout << method << ": " << res << "; Iterative Counter: " << iterativeCounter << std::endl;
}

double bisection(double l, double r, double eps) {
	checkRoots(l, r);
	iterativeCounter++;

	double m = (l + r) / 2;
	double ym = getF(m);

	if (abs(ym) < eps || abs(r - l) < eps) return m;

	if (ym * getF(l) < 0) return bisection(l, m);
	else return bisection(m, r);
}

double bisection_iterative(double l, double r, double eps) {
	checkRoots(l, r);

	double m, mVal;

	while (true) {
		iterativeCounter++;

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

double falsePosition(double l, double r, double eps) {
	checkRoots(l, r);

	double ly = getF(l);
	double ry = getF(r);

	double mx = l - ly * (r - l) / (ry - ly);
	double my = getF(mx);

	if (abs(my) <= eps || abs(r - l) < eps) {
		return mx;
	}

	if (ly * my < 0) return falsePosition(l, mx);
	else return falsePosition(mx, r);
}


double falsePosition_iterative(double l, double r, double eps) {
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

double newtonRaphsan(double l, double r, double eps) {
	if (abs(r - l) < eps) return (l + r) / 2;

	if (getF(r) * getFPrime(r) > 0) std::swap(l, r);
	double x = l - getF(l) / getFPrime(l);

	if (abs(x - l) < eps) return x;
	return newtonRaphsan(x, r, eps);
}

double newtonRaphsan_iterative(double l, double r, double eps) {
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

double iterative(double x0, double eps) {
	double x1 = getG(x0);
	if (abs(x1 - x0) <= eps) return x0;

	return iterative(x1);
}

double iterative_iterative(double x0, double eps) {
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

void clearIterativeCounter() {
	iterativeCounter = 0;
}

template <typename T>
T prompt(const char label[]) {
	std::cout << label;

	while (true) {
		T val;
		std::cin >> val;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Wrong. Try again: ";
		}
		else {
			std::cin.ignore(32767, '\n');
			return val;
		}

	}

}