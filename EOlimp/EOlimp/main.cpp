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
int vUsed = 1;
int resW = 0;

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

void next() {
	int index = -1;
	int minW = 1e10;

	for (int v = 1; v < n; v++) {
		if (vs[v] == true) continue;

		for (int i = 0; i < n; i++) {
			int w = g[v][i];
			//cout << (w == 0 || vs[i] == false || w >= minW) << endl;
			if (w == 0 || vs[i] == false || w >= minW) continue;
			cout << "A ";
			index = v;
			minW = w;
		}
	}

	if (index = -1) return;

	vs[index] = true;
	resW += minW;
	vUsed++;
}

int main() {
	writeG();

	vs[0] = true;

	//while (vUsed <= n) {
		next();
	//}
	
	fout << resW;
	system("pause");
	return 0;
}