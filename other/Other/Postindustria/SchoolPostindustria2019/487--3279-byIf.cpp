#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

std::string toStandardForm(std::string number);
void printFrequency(std::map<std::string, int>& frequencyMap);

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

		std::string standardNum = toStandardForm(number);
		frequencyOfWords[standardNum]++;
	}

	printFrequency(frequencyOfWords);
}

std::string toStandardForm(std::string number) {
	std::string resNum = number;

	resNum.erase(
		std::remove_if(resNum.begin(), resNum.end(), [](char c) {return c == '-'; }),
		resNum.end()
	);

	std::transform(resNum.begin(), resNum.end(), resNum.begin(), ::tolower);
	resNum.insert(resNum.begin() + 3, '-');

	for (auto& c : resNum) {
		if (c == 'a' || c == 'b' || c == 'c') c = '2';
		else if (c == 'a' || c == 'b' || c == 'c') c = '2';
		else if (c == 'd' || c == 'e' || c == 'f') c = '3';
		else if (c == 'g' || c == 'h' || c == 'i') c = '4';
		else if (c == 'j' || c == 'k' || c == 'l') c = '5';
		else if (c == 'm' || c == 'n' || c == 'o') c = '6';
		else if (c == 'p' || c == 'r' || c == 's') c = '7';
		else if (c == 't' || c == 'u' || c == 'v') c = '8';
		else if (c == 'w' || c == 'x' || c == 'y') c = '9';
	}

	return resNum;
}

void printFrequency(std::map<std::string, int>& frequencyMap) {
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
