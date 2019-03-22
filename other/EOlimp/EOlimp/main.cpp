#include <iostream>

using namespace std;

int main() {
	int n, prev, next, max = 1;
	cin >> n >> prev;

	for (int i = 1; i < n; i++) {
		cin >> next;

		max = (prev + 1 == next) ? max + 1 : 1;
		prev = next;
	}

	cout << max << endl;

	system("pause");
	return 0;
}