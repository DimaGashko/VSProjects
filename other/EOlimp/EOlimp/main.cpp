#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int getMinOfMatches(int n) {
	int a = cbrt(n);
	n -= a * a * a;

	int res = 0;

	int twos, p;

	// Stage 1
	p = min(n, 2 * a + 1);
	twos = (p - 1 < a) ? 1 : 2;
	res -= (p - twos) * 7 + twos * 4;
	n -= p;

	// Stage 2
	if (n > 0) {
		p = min(n, (2 * a + 1) * (a - 1));
		twos = (p - 1) / (2 * a + 1) * 2 + ((p - 1) % (2 * a + 1) < a ? 1 : 2);
		res -= (p - twos) * 9 + twos * 7;
		n -= p;
	}

	// Stage 3
	if (n > 0) {
		p = min(n, a + 1);
		res -= (p - 1) * 7 + 4;
		n -= p;
	}

	// Stage 4
	if (n > 0) {
		p = n;
		twos = (p - 1) / (a + 1) + 1;
		res -= (p - twos) * 9 + twos * 7;
	}

	return res;
}

int main() {
	int n;
	cin >> n;

	cout << getMinOfMatches(n) << endl;

	return 0;
}