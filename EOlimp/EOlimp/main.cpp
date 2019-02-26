#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, q, w;
	cin >> n;

	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cin >> q >> w;
	q--; w--;

	int replaceVal = arr[q];
	int toVal = arr[w];

	for (auto& item : arr) {
		if (item != replaceVal) continue;
		item = toVal;
	}

	for (auto& item : arr) {
		cout << item << " ";
	}

	system("pause");
	return 0;
}