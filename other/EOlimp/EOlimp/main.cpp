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
		
		return true;
	}
	bool check(int x, int y) {
		if (x1 > x2) {
			swap(x1, x2);
		}
		else if (y1 > y2) {
			swap(y1, y2);
		}
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

	for (int x = -1; x <= 1000 + 1; x++) {
		for (int y = -1; y <= 1000 + 1; y++) {
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

