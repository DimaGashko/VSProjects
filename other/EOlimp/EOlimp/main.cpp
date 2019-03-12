#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long num;

num getMinOfMatches(num n) {
	num a = (num)cbrt(n);
	n -= a * a * a;

	num res = ((a + 1) * (a + 1) * a * 3) + (n * 12);
	num twos, p;

	// Stage 1
	if (n == 0) return res;
	p = min(n, a);
	res -= (p - 1) * 7 + 4;
	n -= p;

	// Stage 2
	if (n == 0) return res;
	if (a != 1) {
		p = min(n, a * (a - 1));
		twos = (p - 1) / a + 1;
		res -= (p - twos) * 9 + twos * 7;
		n -= p;
	}

	// Stage 1
	if (n == 0) return res;
	p = min(n, a + 1);
	res -= (p - 1) * 7 + 4;
	n -= p;

	// Stage 2
	if (n == 0) return res;
	if (a != 1) {
		p = min(n, (a + 1) * (a - 1));
		twos = (p - 1) / (a + 1) + 1;
		res -= (p - twos) * 9 + twos * 7;
		n -= p;
	}

	// Stage 1
	if (n == 0) return res;
	p = min(n, a + 1);
	res -= (p - 1) * 7 + 4;
	n -= p;

	// Stage 2
	if (n == 0) return res;
	p = min(n, (a + 1) * (a));
	twos = (p - 1) / (a + 1) + 1;
	res -= (p - twos) * 9 + twos * 7;
	n -= p;

	return res;
}

int main() {
	//while (true) {
		num n;
		cin >> n;
		cout << getMinOfMatches(n) << endl;
	//}

	system("pause");
	return 0;
}