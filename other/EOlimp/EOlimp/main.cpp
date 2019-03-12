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

	if (n >= a * a * 3) {
		// Нужно только замкнуть куб
		return;
	}
	
	for (int i = 0; i < 3; i++) {
		if (n < a * a) break;

		res -= (a + 1) * (a + 1) * 2 * a;
		n -= a * a;
	}

	// Нужно замкнуть квадрат

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