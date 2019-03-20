#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> fillMinesMap(std::vector<std::string>& emptyMap);
void incrementMapCell(std::vector<std::vector<int>>& map, int i, int j);

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

void incrementMapCell(std::vector<std::vector<int>>& map, int i, int j) {
	if (map.empty()) return;

	if (i < 0 || j < 0 || i >= map.size() || j >= map[0].size()) {
		return;
	}

	map[i][j]++;
}

void printMinesMap(std::vector<std::string> minesMap) {
	for (auto& row : minesMap) {
		std::cout << row << std::endl;
	}

	std::cout << std::endl;
}