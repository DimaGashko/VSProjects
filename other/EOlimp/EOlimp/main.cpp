#include <iostream>
#include <vector>
#include <string>
#include <fstream>

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");

void fillMinesMap(std::vector<std::string>& minesMap);
void incrementMapCell(std::vector<std::vector<int>>& map, int i, int j);

void writeMinesMap(std::vector<std::string>& minesMap, int n, int m);
void printMinesMap(std::vector<std::string> &minesMap);

int main() {
	for (int fieldNumber = 1; true; fieldNumber++) {
		int n, m;

		fin >> n >> m;
		if (n == 0 && m == 0) break;

		std::vector<std::string> minesMap;

		writeMinesMap(minesMap, n, m);
		fillMinesMap(minesMap);
		
		if (fieldNumber != 1) fout << std::endl;
		fout << "Field #" << fieldNumber << ":" << std::endl;
		printMinesMap(minesMap);
	}

	//system("pause");
	return 0;
}

void fillMinesMap(std::vector<std::string>& minesMap) {
	if (minesMap.empty()) return;
	int iSize = minesMap.size();
	int jSize = minesMap[0].size();

	std::vector<std::vector<int>> digitsMap(iSize, std::vector<int>(jSize));

	for (int i = 0; i < iSize; i++) {
		for (int j = 0; j < jSize; j++) {
			if (minesMap[i][j] != '*') continue;

			incrementMapCell(digitsMap, i + 1, j - 1);
			incrementMapCell(digitsMap, i + 1, j + 1);
			incrementMapCell(digitsMap, i - 1, j + 1);
			incrementMapCell(digitsMap, i - 1, j - 1);
			incrementMapCell(digitsMap, i + 1, j);
			incrementMapCell(digitsMap, i - 1, j);
			incrementMapCell(digitsMap, i, j + 1);
			incrementMapCell(digitsMap, i, j - 1);
		}
	}

	for (int i = 0; i < iSize; i++) {
		for (int j = 0; j < jSize; j++) {
			if (minesMap[i][j] == '*') continue;

			minesMap[i][j] = digitsMap[i][j] + '0';
		}
	}
}

void incrementMapCell(std::vector<std::vector<int>>& map, int i, int j) {
	if (map.empty()) return;

	if (i < 0 || j < 0 || i >= (int)map.size() || j >= (int)map[0].size()) {
		return;
	}

	map[i][j]++;
}

void writeMinesMap(std::vector<std::string>& minesMap, int n, int m) {
	minesMap = std::vector<std::string>(n);

	for (int i = 0; i < n; i++) {
		fin >> minesMap[i];
	}
}

void printMinesMap(std::vector<std::string> &minesMap) {
	for (auto& row : minesMap) {
		fout << row << std::endl;
	}
}