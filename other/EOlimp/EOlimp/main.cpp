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
string inp = "numbers.in";
string out = "numbers.out";

// - - - - -

ifstream fin(inp);
ofstream fout(out);

int main() {
	int a, b, c, d;
	fin >> a >> b >> c >> d;

	vector<int> res{
		a * b + c * d,
		a * c + b * d,
		a * d + b * c,
	};

	sort(res.begin(), res.end());

	fout << res.back() << endl;

	return 0;
}