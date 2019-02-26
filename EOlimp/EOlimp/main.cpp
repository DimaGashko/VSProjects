#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

typedef vector<vector<int>> G;

G g;
vector<bool> vs;
int n = 0;
int res = 0;

void writeG() {
	int m;
	fin >> n >> m;

	g = G(n, vector<int>(n));
	vs = vector<bool>(n);

	for (int i = 0; i < m; i++) {
		int a, b, c;
		fin >> a >> b >> c;
		a--; b--;

		g[a][b] = c;
		g[b][a] = c;
	}
}

int main() {

	writeG();

	for (auto row : g) {
		for (auto item : row) {
			fout << item << " ";
		}

		fout << endl;
	}

	return 0;
}