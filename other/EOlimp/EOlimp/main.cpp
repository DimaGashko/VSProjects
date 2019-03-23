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
string inp = "rect.in";
string out = "rect.out";

// - - - - -

ifstream fin(inp);
ofstream fout(out);


int main() {
	int k, n;
	fin >> k >> n;

	double d = pow(n - 2 * k + 2, 2) - 4 * (n - k + 1);
	double sd = sqrt(d);

	double y1 = (n - 2 * k + 2 + sd) / 2;
	double y2 = (n - 2 * k + 2 - sd) / 2;

	double y = (y1 > 0) ? y1 : y2;
	double x = (y + k - 1) / (y - 1);

	fout << x << " " << y << endl;

	return 0;
}

