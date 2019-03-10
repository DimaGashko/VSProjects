#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int func(int n) {
	if (n = 0) return 0;
	return func(n - 1) + n;
}

int main() {
	int n = 0;
	cin >> n;

	cout << func(n) << endl;

	system("pause");
	return 0;
}