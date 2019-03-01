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

	int middle = (r - l) / 2;

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
	//cin >> a >> b;

	//if (a > b) swap(a, b);

	vector<int> d;

	d.push_back(1);
	d.push_back(3);
	d.push_back(5);
	d.push_back(7);
	d.push_back(9);
	d.push_back(12);
	d.push_back(13);
	d.push_back(16);
	d.push_back(17);
	d.push_back(19);
	d.push_back(21);
	d.push_back(23);
	d.push_back(29);
	d.push_back(31);
	d.push_back(32);
	d.push_back(58);
	d.push_back(66);
	d.push_back(73);
	d.push_back(85);

	cout << (hasItem(d, 1, 0, d.size() - 1) ? "YES" : "NO") << endl;
	cout << (hasItem(d, 3, 0, d.size() - 1) ? "YES" : "NO") << endl;
	cout << (hasItem(d, 3, 0, d.size() - 1) ? "YES" : "NO") << endl;
	cout << (hasItem(d, 7, 0, d.size() - 1) ? "YES" : "NO") << endl;
	cout << (hasItem(d, 9, 0, d.size() - 1) ? "YES" : "NO") << endl;
	cout << (hasItem(d, 12, 0, d.size() - 1) ? "YES" : "NO") << endl;
	cout << (hasItem(d, 13, 0, d.size() - 1) ? "YES" : "NO") << endl;
	cout << (hasItem(d, 16, 0, d.size() - 1) ? "YES" : "NO") << endl;
	cout << (hasItem(d, 17, 0, d.size() - 1) ? "YES" : "NO") << endl;
	cout << (hasItem(d, 19, 0, d.size() - 1) ? "YES" : "NO") << endl;
	cout << (hasItem(d, 21, 0, d.size() - 1) ? "YES" : "NO") << endl;
	cout << (hasItem(d, 23, 0, d.size() - 1) ? "YES" : "NO") << endl;
	cout << (hasItem(d, 29, 0, d.size() - 1) ? "YES" : "NO") << endl;
	cout << (hasItem(d, 31, 0, d.size() - 1) ? "YES" : "NO") << endl;
	cout << (hasItem(d, 32, 0, d.size() - 1) ? "YES" : "NO") << endl;
	cout << (hasItem(d, 58, 0, d.size() - 1) ? "YES" : "NO") << endl;
	cout << (hasItem(d, 66, 0, d.size() - 1) ? "YES" : "NO") << endl;
	cout << (hasItem(d, 73, 0, d.size() - 1) ? "YES" : "NO") << endl;
	cout << (hasItem(d, 85, 0, d.size() - 1) ? "YES" : "NO") << endl;

	/*
	auto primes = getPrimes(10000);
	int mirrorPrimesCount = 0;
	int primesSize = primes.size();

	for (auto prime : primes) {
		if (hasItem(primes, getReversed(prime), 0, primesSize - 1)) {
			mirrorPrimesCount++;
		}
	}

	cout << mirrorPrimesCount << endl;*/

	system("pause");
	return 0;
}