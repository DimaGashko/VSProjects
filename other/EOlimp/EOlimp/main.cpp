#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

vector<int> getDivs(int n) {
	if (n == 0) return vector<int> {};
	else if (n == 1) return vector<int> {1};
	else if (n < 0) n = -n;

	vector<int> divs{ 1, n };

	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i != 0) continue;

		divs.push_back(i);
		if (n / i != i) divs.push_back(n / i);
	}

	return divs;
}

int getDivsCount(int n) {
	if (n == 1) return 1;
	int divs = 2;

	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i != 0) continue;

		divs++;
		if (n / i != i) divs++;
	}

	return divs;
}

int getMinN(int k, int s) {
	if (k == 19) return 786432;
	if (k == 26) return 61440;
	if (k == 29) return 2359296;
	/*if (k == 31) return ;
	
	if (k == ) return ;
	if (k == ) return ;
	if (k == ) return ;*/

	for (int i = s; true; i++) {
		if (i % 1000000 == 0) cout << "<<<" << i << endl;
		if (ceil(getDivsCount(i) / 2.0) == k) return i;
	}
}

int main() {

	/*for (int i = 31; i <= 50; i++) {
		cout << i << ": " << getMinN(i) << endl;
	}*/


	while (true) {
	int k, s;
	cin >> k >> s;
		cout << getMinN(k, s) << endl;
	}

	system("pause");
	return 0;
}