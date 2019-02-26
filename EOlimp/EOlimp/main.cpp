#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

typedef vector<vector<bool>> G;

G g;
int gN = 0;

void writeG() {
	int m, n;
	fin >> m >> n;

	vector<string> strMap(m);

	for (int i = 0; i < m; i++) {
		string row;
		fin >> row;

		if (row.empty()) {
			continue;
		}

		strMap[i] = row;
	}

	map<pair<int, int>, int> vsIndexes;

	for (int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if (strMap[i][j] == '.') continue;
			gN++;
			vsIndexes[pair<int, int>(i, j)] = gN;
		}
	}

	g = G(gN, vector<bool>(gN));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (strMap[i][j] == '.') continue;

			int aIndex = vsIndexes[pair<int, int>(i, j)] - 1;
			int lIndex = vsIndexes[pair<int, int>(i, j - 1)] - 1;
			int tIndex = vsIndexes[pair<int, int>(i - 1, j)] - 1;
			int rIndex = vsIndexes[pair<int, int>(i, j + 1)] - 1;
			int bIndex = vsIndexes[pair<int, int>(i + 1, j)] - 1;

			if (lIndex != -1) g[aIndex][lIndex] = 1;
			if (tIndex != -1) g[aIndex][tIndex] = 1;
			if (rIndex != -1) g[aIndex][rIndex] = 1;
			if (bIndex != -1) g[aIndex][bIndex] = 1;
		}
	}

}

void run(int v = 0, int prev = -1) {

}

int main() {
	writeG();
	run();

	return 0;
}