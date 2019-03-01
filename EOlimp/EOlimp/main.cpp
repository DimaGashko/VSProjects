#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

map<string, bool> getPrimesMap(int n) {
	vector<bool> numbers(n - 2); // 1 - не простое, каждый индек - на два меньше
	int p = 2;

	for (int p = 2; p * p <= n; p++) {

		for (int i = 2 * p; i < n; i += p) {
			numbers[i - 2] = true;
		}
	}

	map<string, bool> primesMap;

	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i]) continue;

		primesMap[to_string(i + 2)] = true;
	}

	return primesMap;
}

int main() {
	int a, b;
	cin >> a >> b;

	if (a > b) swap(a, b);

	auto primesMap = getPrimesMap(10000);
	int mirrorPrimesCount = 0;

	for (int i = a; i <= b; i++) {
		string n = to_string(i);
		//if (primesMap[n] == false) continue;

		//string reversed = n;
		//reverse(reversed.begin(), reversed.end());

		//if (primesMap[reversed] == false) continue;

		mirrorPrimesCount++;
	}

	cout << mirrorPrimesCount << endl;

	system("pause");
	return 0;
}