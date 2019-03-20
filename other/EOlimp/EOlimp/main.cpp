#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> fillMinesMap(std::vector<std::string>& emptyMap);
void incrementMinesMapCell(std::vector<std::vector<int>>& minesMap, int i, int j);

void printMinesMap(std::vector<std::string> minesMap);

int main() {
	std::vector<std::string> testMap = {
		"*...",
		"....",
		".*..",
		"...."
	};

	std::vector<std::string> resMap = fillMinesMap(testMap);
	printMinesMap(resMap);

	system("pause");
	return 0;
}

std::vector<std::string> fillMinesMap(std::vector<std::string>& emptyMap) {
	
}

void incrementMinesMapCell(std::vector<std::vector<int>>& minesMap, int i, int j) {
	if (minesMap.empty()) return;

	if (i < 0 || j < 0 || i >= minesMap.size() || j >= minesMap[0].size()) {
		return;
	}

	minesMap[i][j]++;
}

void printMinesMap(std::vector<std::string> minesMap) {
	for (auto& row : minesMap) {
		std::cout << row << std::endl;
	}

	std::cout << std::endl;
}