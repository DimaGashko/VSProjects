#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void getPrimesTo(vector<int>& res, int to) {
	const int offset = 2;
	double maxP = sqrt(to);
	int _to = to - offset;

	// Если использовать вектор getPrimesTo на 10^6 занимает ~280ms, с массивом - 40
	bool* primes = new bool[_to];
	for (int i = 0; i < _to; i++) {
		primes[i] = true;
	}

	for (int p = 2; p <= maxP; p++) {
		for (int i = 2 * p - offset; i <= _to; i += p) {
			primes[i] = false;
		}
	}

	res.reserve(_to);
	for (int i = 0; i < _to; i++) {
		// push_back почти не влияет на скорость, так как простых чисел максимум 80000
		if (primes[i]) res.push_back(i + offset);
	}
}

void getColumnSizes(vector<int>& nums, vector<int>& colSizes) {
	int rSize = (int)nums.size();

	vector<int> rowSizes(rSize);
	for (int i = 0; i < rSize; i++) {
		rowSizes[i] = nums[i] / 2;
	}

	int cSize = rowSizes.back();
	colSizes = vector<int>(cSize);

	for (int i = 0; i < rSize; i++) {
		int cur = rowSizes[i] - 1;

		if (colSizes[cur] == 0) {
			colSizes[cur] = rSize - i;
		}

		if (cur == 0) {
			continue;
		}

		for (int prev = cur - 1; colSizes[prev] == 0; prev--) {
			colSizes[prev] = colSizes[cur];
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long k = 23;
	//cin >> k;

	vector<int> primes;
	vector<int> colSizes;
	getPrimesTo(primes, 18);
	getColumnSizes(primes, colSizes);

	cout << primes.size() << endl << colSizes.size() << endl;

	cin >> k;
	return 0;
}