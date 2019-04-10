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
string inp = "rects.in";
string out = "rects.out";

// - - - - -

ifstream fin(inp);
ofstream fout(out);

struct Rect {
	int x1, y1, x2, y2;
	bool create() {
		if (!(fin >> x1 >> y1 >> x2 >> y2)) {
			return false;
		}
		if (x1 > x2) {
			int _x1 = x1;
			x1 = x2;
			x2 = _x1;
		}
		else if (y1 > y2) {
			int _y1 = y1;
			y1 = y2;
			y2 = _y1;
		}
		return true;
	}
	bool check(int x, int y) {
		return x >= x1 && x < x2 && y >= y1 && y < y2;
	}
};

int main() {
	vector<Rect> arr;

	while (true) {
		Rect next;
		if (next.create()) {
			arr.push_back(next);
		}
		else  break;
	}

	int res = 0;

	for (int x = 0; x <= 1000 + 1; x++) {
		for (int y = 0; y <= 1000 + 1; y++) {
			bool r = false;

			for (auto& a : arr) {
				if (a.check(x, y)) {
					r = true;
					break;
				}
			}

			if (r) res++;
		}
	}

	fout << res << endl;

	return 0;
}

