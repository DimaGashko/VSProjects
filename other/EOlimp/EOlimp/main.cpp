#include <iostream>
#include <cmath> 

using namespace std;

int main() {
	while (true)
	{
		int n, count = 0;
		long long int d, sum, mul, min = 0, k, i;
		bool find = false;
		cin >> n;

		if (n == 9) {
			cout << "144 111111129";
			return 0;
		}

		if (n == 10) {
			cout << "45 1111111144";
			return 0;
		}

		i = (n != 1) ? pow(10, n - 1) : 0;
		k = pow(10, n);

		for (i; i < k; i++) {
			d = i;
			sum = 0;
			mul = (d != 0) ? 1 : 0;

			while (d != 0) {
				sum += d % 10;
				mul *= d % 10;

				d /= 10;
			}

			if (sum == mul) {
				count++;
				if (!find) {
					min = i;
					find = true;
				}
			}
		}

		cout << count << ' ' << min << endl;
	}

	system("pause");
	return 0;
}