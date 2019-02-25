#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef vector<vector<bool>> G;

ifstream fin("input.txt");
ofstream fout("output.txt");

void writeGraph();
void writeVs();
void run(int v);
void checkRes();

G g;
vector<bool> vs;
int n = 0;
bool isLoop = false;

int main() {
	writeGraph();
	writeVs();
	run(0);
	checkRes();
	
	return 0;
}

void run(int v) {
	if (isLoop) return;

	if (vs[v] == true) {
		isLoop = true;
		return;
	}

	vs[v] = true;

	for (int i = 0; i < n; i++) {
		if (g[v][i] == 0) continue;

		run(i);
	}
}

void checkRes() {
	bool isTree = true;

	for (auto item : vs) {
		if (item) continue;

		isTree = false;
		break;
	}

	fout << (isTree ? "YES" : "NO");
}

void writeGraph() {
	fin >> n;

	g = G(n, vector<bool>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			bool val;
			fin >> val;

			if (j <= i) continue;

			g[i][j] = val;
		}
	}
}

void writeVs() {
	vs = vector<bool>(g.size());
}