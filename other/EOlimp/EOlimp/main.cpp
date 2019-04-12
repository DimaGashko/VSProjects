#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <ctime>
#include <cmath>
#include <string>

using namespace std;

int n, resLen = 0;
vector<int> arr;
vector<int> res;
map<int, int> numMap;

string correct;

void fInit() {
	srand((int)time(nullptr));

	n = 5500;
	arr = vector<int>(n);
	res = vector<int>(n / 2);
	vector<int> st(n / 2);
	vector<int> nw(n / 2);

	for (int i = 0; i < n / 2; i++) {
		st[i] = 4 * int(((double)rand() / RAND_MAX) * 1000000000 / 4) + 1;
		arr[i] = st[i];
	}

	for (int i = 0; i < n / 2; i++) {
		nw[i] = int(st[i] * 0.75);
		arr[n / 2 + i] = nw[i];
	}

	sort(st.begin(), st.end());
	sort(nw.begin(), nw.end());
	sort(arr.begin(), arr.end());

	for (auto& a : nw) {
		correct += to_string(a) + '\n';
	}

	for (auto& num : arr) {
		numMap[num]++;
	}
}

void init() {
	cin >> n;

	arr = vector<int>(n);
	res = vector<int>(n / 2);

	for (int i = n - 1; i >= 0; i--) {
		cin >> arr[i];
	}

	for (auto& num : arr) {
		numMap[num]++;
	}
}

void run() {
	for (auto& cur : arr) {
		if (numMap[cur] <= 0) continue;

		int newV = int(cur * 0.75);
		if (numMap[newV] <= 0) continue;

		res[resLen++] = newV;
		numMap[newV]--;
	}

	sort(res.begin(), res.end());
}

void printRes() {
	string r;

	for (auto& num : res) {
		r += to_string(num) + '\n';
	}

	cout << (r == correct) << endl << endl;

	//cout << r << endl << endl << correct;
}

int main() {
	fInit();
	run();
	printRes();

	return 0;
}