#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	float base = ceil(float(n) / k) * 4;

	if ((n % k) >= k / 2.f) {
		cout << base;
	}
	else {
		cout << base - 2;
	}

	system("pause");
	return 0;
}
