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
string inp = "hotel.in";
string out = "hotel.out";

// - - - - -

ifstream fin(inp);
ofstream fout(out);

int main() {
	int n, m;
	fin >> n >> m;

	int res = (n - 1) * m * 2;

	fout << res << endl;

	return 0;
}