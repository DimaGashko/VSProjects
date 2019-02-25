#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

typedef vector<vector<bool>> G;

void writeG();

G g;
vector<bool> vs;

int n = 0, m = 0;

int main() {

	writeG();

	return 0;
}

void writeG() {
	fin >> n >> m;

	g = G(n, vector<bool>(n));
	vs = vector<bool>(n);

	for (int i = 0; i < m; i++) {
		int a, b;
		fin >> a >> b;
		a--; b--;

		g[a][b] = 1;
		g[b][a] = 1;
	}

}
