#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long num;

num getMinOfMatches(num n) {
	num a = (num)cbrt(n);
	n -= a * a * a;

	num res = ((a + 1) * (a + 1) * a * 3);
	if (n == 0) return res;

	num fullSquares = min(n / (a * a), (num)2);
	res += (3 * a * a + 4 * a + 1) * fullSquares;
	n -= a * a * fullSquares;
	if (n == 0) return res;

	if (fullSquares > 1) {
		num p = min(n, a);
		res += (p - 1) * 3 + 5;
		n -= p;
		if (n == 0) return res;
	}

	num fullSquares2 = min(n / (a * a), (num)1);
	res += (3 * a * a + 4 * a + 1) * fullSquares2;
	n -= a * a * fullSquares2;
	if (n == 0) return res;

	if (fullSquares + fullSquares2 < 3) {
		num b = (num)sqrt(n);
		n -= b * b;
		res += 3 * b * b + 4 * b + 1;

		num twos = (n - 1) / b + 1;
		res += (n - twos) * 3 + twos * 5;
	}
	else {
		num twos = (n - 1) / a + 1;
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