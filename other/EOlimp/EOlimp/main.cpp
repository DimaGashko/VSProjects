#include <iostream>
#include <string>

using namespace std;

int main() {
	long long num;
	cin >> num;

	int max = 0;
	int count = 0;

	while (num) {
		int d = num % 10;
		if (d > max) {
			max = d;
			count = 1;
		}
		else if (d == max) {
			count++;
		}

		num /= 10;
	}

	cout << count << endl;

	system("pause");
	return 0;
}