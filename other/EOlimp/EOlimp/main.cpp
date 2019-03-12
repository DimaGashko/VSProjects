#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

vector<int> getDivs(int n) {
	vector<int> divs;
	if (n == 0) return divs;

	divs.push_back(1);
	if (n == 1) return divs;

	divs.push_back(n);
	if (n == 2) return divs;

	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i != 0) continue;

		divs.push_back(i);
		if (n / i != i) divs.push_back(n / i);
	}

	sort(divs.begin(), divs.end());
	return divs;
}

int main() {
	for (int i = 0; i < 1000; i++) {
		for (auto& div : getDivs(i)) {
			cout << div << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}