#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

typedef vector<vector<bool>> G;

G g;

void writeG() {
	int m, n;
	fin >> m >> n;

	vector<string> map(m);

	for (int i = 0; i < m; i++) {
		string row;
		fin >> row;

		if (row.empty()) {
			continue;
		}

		map[i] = row;
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			fout << map[i][j];
		}

		fout << endl;
	}
}

int main() {

	writeG();

	return 0;
}