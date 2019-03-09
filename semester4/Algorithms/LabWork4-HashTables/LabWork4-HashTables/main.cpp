#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <regex>

void readWordsFromFile(std::vector<std::string> &words, const std::string url);
std::map<std::string, int> getMapOfWords(std::vector<std::string> &words);

template <typename T>
T prompt(const char label[]);

int main() {
	std::vector<std::string> words(2000);
	readWordsFromFile(words, "loremText2000.txt");

	auto mapOfWords = getMapOfWords(words);

	system("pause");
	return  0;
}

std::map<std::string, int> getMapOfWords(std::vector<std::string>& words) {
	std::map<std::string, int> mapOfWords;

	for (auto& word : words) {
		mapOfWords[word] = mapOfWords[word] + 1;
	}

	return mapOfWords;
}

void readWordsFromFile(std::vector<std::string>& words, const std::string url) {
	static const std::regex wordRegex("[^a-zA-Z0-9_]+");
	std::ifstream fin(url);
	
	if (!fin.is_open()) {
		throw std::runtime_error("Can't open the file");
	}

	std::string nextWord;

	for (auto& word : words) {
		if (!(fin >> nextWord)) break;
		word = std::regex_replace(nextWord, wordRegex, "");
	}

	fin.close();
}

template <typename T>
T prompt(const char label[]) {
	std::cout << label;

	while (true) {
		T val;
		std::cin >> val;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Wrong. Try again: ";
		}
		else {
			std::cin.ignore(32767, '\n');
			return val;
		}

	}

}