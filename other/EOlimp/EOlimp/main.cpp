#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long num;

num getMinOfMatches(num n) {
	num a = (num)cbrt(n);
	n -= a * a * a;

	num res = ((a + 1) * (a + 1) * a * 3) + (n * 12);
	if (n == 0) return res;

	int fullSquares = n / (a * a);
	res -= ((a + 1) * (a + 1) * 2 * a) * fullSquares;
	n -= a * a * fullSquares;
	if (n == 0) return res;

	if (fullSquares < 3) {
		num b = (num)sqrt(n);
		n -= b * b;
		res -= ((b + 1) * (b + 1) * 2 * b) + (n * 12);

		int twos = (n - 1) / b + 1;
		res -= (n - twos) * 9 + twos * 7;
	}
	else {
		int twos = (n - 1) / a + 1;
		res -= (n - twos) * 9 + twos * 7;
	}

	return res;
}

int main() {
	while (true) {
		num n;
		cin >> n;
		cout << getMinOfMatches(n) << endl;
	}

	system("pause");
	return 0;
}