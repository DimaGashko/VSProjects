#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

std::map<char, char> baseAssociationMap{
	{'a', '2'}, {'b', '2'}, {'c', '2'},
	{'d', '3'}, {'e', '3'}, {'f', '3'},
	{'g', '4'}, {'h', '4'}, {'i', '4'},
	{'j', '5'}, {'k', '5'}, {'l', '5'},
	{'m', '6'}, {'n', '6'}, {'o', '6'},
	{'p', '7'}, {'r', '7'}, {'s', '7'},
	{'t', '8'}, {'u', '8'}, {'v', '8'},
	{'w', '9'}, {'x', '9'}, {'y', '9'}
};

std::string toStandardForm(std::string number, std::map<char, char> associationMap);
void printFrequency(std::map<std::string, int> & frequencyMap);

void runTest();

int main() {
	int numberOfTests;
	std::cin >> numberOfTests;

	for (int testIndex = 0; testIndex < numberOfTests; testIndex++) {
		runTest();

		if (testIndex != numberOfTests - 1) {
			std::cout << std::endl;
		}
	}

	system("pause");
	return 0;
}

void runTest() {
	int numsCount;
	std::cin >> numsCount;

	std::map<std::string, int> frequencyOfWords;

	for (int i = 0; i < numsCount; i++) {
		std::string number;
		std::cin >> number;

		std::string standardNum = toStandardForm(number, baseAssociationMap);
		frequencyOfWords[standardNum]++;
	}

	printFrequency(frequencyOfWords);
}

std::string toStandardForm(std::string number, std::map<char, char> associationMap) {
	std::string resNum = number;

	resNum.erase(
		std::remove_if(resNum.begin(), resNum.end(), [](char c) {return c == '-'; }),
		resNum.end()
	);

	std::transform(resNum.begin(), resNum.end(), resNum.begin(), ::tolower);
	resNum.insert(resNum.begin() + 3, '-');

	for (auto& c : resNum) {
		if (!associationMap[c]) continue;
		c = associationMap[c];
	}

	return resNum;
}

void printFrequency(std::map<std::string, int> &frequencyMap) {
	std::vector<std::pair<std::string, int>> frequency(frequencyMap.begin(), frequencyMap.end());

	frequency.erase(
		std::remove_if(frequency.begin(), frequency.end(), [](std::pair<std::string, int> item) {
		return item.second <= 1;
	}), frequency.end());

	if (frequency.empty()) {
		std::cout << "No duplicates." << std::endl;
		return;
	}

	std::sort(frequency.begin(), frequency.end());

	for (auto& item : frequency) {
		std::cout << item.first << " " << item.second << std::endl;
	}
}