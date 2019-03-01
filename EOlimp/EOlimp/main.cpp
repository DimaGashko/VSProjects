#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> getPrimes(int n) {
	vector<bool> numbers(n - 2); // 1 - не простое, каждый индек - на два меньше
	int p = 2;

	for (int p = 2; p * p <= n; p++) {

		for (int i = 2 * p; i < n; i += p) {
			numbers[i - 2] = true;
		}
	}

	vector<int> primes;

	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i]) continue;
		primes.push_back(i + 2);
	}

	return primes;
}

bool hasItem(vector<int> arr, int item, int l, int r) {
	if (l >= r) return arr[l] == item;

	int middle = (l + r) / 2;

	if (arr[middle] > item) return hasItem(arr, item, l, middle - 1);
	if (arr[middle] < item) return hasItem(arr, item, middle + 1, r);
	if (arr[middle] == item) return true;
}

int getReversed(int n) {
	string reversed = to_string(n);
	reverse(reversed.begin(), reversed.end());

	return atoi(reversed.c_str());
}

int main() {
	int a, b;
	cin >> a >> b;

	if (a > b) swap(a, b);

	auto primes = getPrimes(10000);
	int mirrorPrimesCount = 0;
	int primesSize = primes.size();

	for (int i = a; i <= b; i++) {
		cout << primes[i] << " " << getReversed(primes[i]) << hasItem(primes, getReversed(primes[i]), 0, primesSize - 1);

		if (hasItem(primes, getReversed(primes[i]), 0, primesSize - 1)) {
			mirrorPrimesCount++;
		}
	}

	cout << mirrorPrimesCount << endl;

	system("pause");
	return 0;
}