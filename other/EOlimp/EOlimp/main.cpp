#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int p, d1, d2, d3;
		cin >> p >> d1 >> d2 >> d3;

		printf("%.2f\n", ((d1 * 5 + d2 * 3 + d3) / (double)p));
	}

	system("pause");
	return 0;
}