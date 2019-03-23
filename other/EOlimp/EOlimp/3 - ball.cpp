#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <deque>
#include <cmath>

using namespace std;

string inp_ = "input.txt";
string out_ = "output.txt";
string inp = "ball.in";
string out = "ball.out";

// - - - - -

ifstream fin(inp);
ofstream fout(out);

vector<int> getDigits(int n) {
	vector<int> res;

	while (n) {
		res.push_back(n % 10);
		n /= 10;
	}

	return res;
}

long long getMul(vector<int> vec) {
	long long res = 1;

	for (auto& a : vec) {
		res *= a;
	}

	return res;
}

int main() {
	int n;
	fin >> n;

	auto digits = getDigits(n);
	vector<long long> res;

	res.push_back(getMul(digits));
	
	for (int i = 0; i < digits.size() - 1; i++) {
		if (digits[i + 1] == 0) continue;
		digits[i + 1]--;
		digits[i] = 9;
		res.push_back(getMul(digits));
	}

	sort(res.begin(), res.end());

	fout << res.back() << endl;

	return 0;
}

