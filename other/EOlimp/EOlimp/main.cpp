#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int getSumOfDigits(long long num) {
	int sum = 0;

	while (num) {
		sum += num % 10;
		num /= 10;
	}

	return sum;
}

int main() {
	while (true) {
		long long num;
		cin >> num;

		cout << getSumOfDigits(num) << endl;
	}

	system("pause");
	return 0;
}