#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <cmath>
#include <map>

using namespace std;

vector<int> arr;
vector<int> res;
map<int, int> numMap;
int n, len = 0;

void init() {
	cin >> n;

	arr = vector<int>(n);

	for (auto& item : arr) {
		cin >> item;
		numMap[item]++;
	}
}


int main() {
	init();

	for (int i = n - 1; i >= 0; i--) {
		int item = arr[i];

		if (item % 4 != 0) {
			res.push_back(item);
			continue;
		}

		int newv = item / 4;
		
		numMap[item]--;

		if (numMap[newv] > 0) {
			res.push_back(newv);
			numMap[newv]--;
		}
	}

	for (int i = res.size() - 1; i >= 0; i--) {
		cout << res[i] << endl;
	}

	//system("pause");
	return 0;
}