#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

typedef vector<vector<int>> G;

G g;
vector<bool> vVal;
vector<bool> vs;
int n;

int a, b, max;

void writeG() {
	fin >> n;

	g = G(n, vector<int>(n));
	vVal = vector<bool>(n);
	vs = vector<bool>(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fin >> g[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		bool val;
		fin >> val;
		vVal[i] = val;
	}
}

void nextV(int v) {
	if (vs[v]) return;
	vs[v] = true;

	for (int i = 0; i < n; i++) {
		if (g[v][i] == 0 || vs[i] || vVal[v] == vVal[i]) continue;


	}

}

int main() {
	writeG();

	for (int i = 0; i < n; i++) {
		nextV(i);
	}

	fout << a << " " << b;

	return 0;
}