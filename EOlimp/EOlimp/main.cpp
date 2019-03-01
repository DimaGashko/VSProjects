#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, bool> getPrimes(int a, int b) {
	vector<bool> numbers(b - 2); // 1 - не простое, каждый индек - на два меньше
	int p = 2;

	for (int p = 2; p * p <= b; p++) {

		for (int i = 2 * p; i < b; i += p) {
			numbers[i - 2] = true;
		}
	}

	unordered_map<string, bool> primesMap;

	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i]) continue;

		primesMap[to_string(i + 2)] = true;
	}

}

int main() {
	int a, b;
	cin >> a >> b;

	if (a > b) swap(a, b);

	auto primes = getPrimes(a, b);

	for (int i = 0; i < primes.size(); i++) {
		if (primes[i]) continue;

		cout << i + 2 << " ";
	}

	system("pause");
	return 0;
}