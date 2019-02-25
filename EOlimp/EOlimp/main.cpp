#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef vector<vector<int>> G;

ifstream fin("input.txt");
ofstream fout("output.txt");

void writeGraph(G &g);

int main() {

	G g;
	writeGraph(g);

	for (auto& row : g) {
		for (auto& item : row) {
			fout << item << " ";
		}

		fout << endl;
	}
	
	return 0;
}

void writeGraph(G &g) {
	int n = 0;
	fin >> n;

	g = G(n, vector<int>(n));

	for (auto &row : g) {
		for (auto &item : row) {
			fin >> item;
		}
	}
}