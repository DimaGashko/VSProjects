#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	float base = ceil(float(n) / k) * 4 - 2;

	cout << base;

	/*if ((n% k) > k / 2) {
		cout << base - 2;
	}
	else {
		cout << base;
	}*/


	system("pause");
	return 0;
}
