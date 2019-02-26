#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

typedef vector<vector<bool>> G;

G g;

void writeG() {
	int n, m;
	fin >> n >> m;

	vector<string> map(m);

	for (int i = 0; i < m; i++) {
		fin >> map[i];
	}

	for (auto row : map) {
		fout << row << endl;
	}
}

int main() {

	writeG();

	return 0;
}