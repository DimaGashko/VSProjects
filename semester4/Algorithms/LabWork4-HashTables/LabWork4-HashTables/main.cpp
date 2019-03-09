#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <regex>
#include <sstream>

#include "Map.hpp"

std::vector<std::string> readWordsFromFile(const std::string url, int count);
dg::Map getMapOfWords(std::vector<std::string> &words);
std::vector<std::pair<std::string, int>> getWordsFrequency(std::vector<std::string>& words);

void printTopOfWords(std::vector<std::string> &words, int wordsInTop = 20);

void printHello();
void run();

template <typename T>
T prompt(const char label[]);

int main() {
	printHello();
	run();

	system("pause");
	return  0;
}

void run() {
	auto words = readWordsFromFile("loremText2000.txt", 2000);

	const int wordsInTop = prompt<unsigned short>("Enter the number of words in the TOP: ");
	std::cout << "The most common words in the text: \n";

	printTopOfWords(words, wordsInTop);
}

void printTopOfWords(std::vector<std::string>& words, int wordsInTop) {
	const auto frequency = getWordsFrequency(words);
	const auto topSize = std::min(wordsInTop, static_cast<int>(frequency.size()));

	for (int i = 0; i < topSize; i++) {
		std::cout << " - " << frequency[i].first << ": " << frequency[i].second << std::endl;
	}

	std::cout << std::endl;
}

std::vector<std::pair<std::string, int>> getWordsFrequency(std::vector<std::string> &words) {
	auto mapOfWords = getMapOfWords(words);
	auto frequency = mapOfWords.toVector();
	
	static auto comparator = [](
		const std::pair<std::string, int> &a, 
		const std::pair<std::string, int> b
	) {
		return a.second > b.second;
	};

	std::sort(frequency.begin(), frequency.end(), comparator);

	return frequency;
}

dg::Map getMapOfWords(std::vector<std::string>& words) {
	dg::Map mapOfWords;

	for (auto& word : words) {
		mapOfWords.set(word, mapOfWords.get(word) + 1);
	}

	return mapOfWords;
}

std::vector<std::string> readWordsFromFile(const std::string url, int count) {
	static const std::regex wordRegex("[.,;-\?!]");
	std::vector<std::string> words(count);
	std::ifstream fin(url);
	
	if (!fin.is_open()) {
		throw std::runtime_error("Can't open the file");
	}

	std::string fileText(
		(std::istreambuf_iterator<char>(fin)),
		std::istreambuf_iterator<char>()
	);

	fileText = std::regex_replace(fileText, wordRegex, "");
	std::transform(fileText.begin(), fileText.end(), fileText.begin(), ::tolower);

	std::istringstream textStream(fileText);

	std::string next;

	for (auto& word : words) {
		if (!(textStream >> next)) break;
		word = next;
	}

	fin.close();
	return words;
}

void printHello() {
	std::cout << "* * * Algorithms: Hash Tables * * *\n\n";
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