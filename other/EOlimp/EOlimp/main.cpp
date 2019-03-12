#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long num;

num getMinOfMatches(num n) {
	int a = (int)cbrt(n);
	n -= a * a * a;

	num res = ((a + 1) * (a + 1) * a * 3);
	if (n == 0) return res;

	int fullSquares = n / (a * a);
	res += (3 * a * a + 4 * a + 1) * fullSquares;
	n -= a * a * fullSquares;
	if (n == 0) return res;

	if (fullSquares < 3) {
		int b = (int)sqrt(n);
		n -= b * b;
		res += 3 * b * b + 4 * b + 1;

		int twos = (n - 1) / b + 1;
		res += (n - twos) * 3 + twos * 5;
	}
	else {
		int twos = (n - 1) / a + 1;
		res += (n - twos) * 3 + twos * 5;
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