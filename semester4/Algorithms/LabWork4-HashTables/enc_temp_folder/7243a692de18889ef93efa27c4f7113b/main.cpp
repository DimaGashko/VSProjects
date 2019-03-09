#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <regex>
#include <unordered_map>
#include <sstream>

std::vector<std::string> readWordsFromFile(const std::string url, int count);
std::unordered_map<std::string, int> getMapOfWords(std::vector<std::string> &words);
std::vector<std::pair<std::string, int>> getWordsFrequency(std::vector<std::string>& words);

void printTopOfWords(std::vector<std::string> &words, int wordsInTop = 20);

template <typename T>
T prompt(const char label[]);

int main() {
	auto words = readWordsFromFile("loremText100000.txt", 100000);

	std::cout << "Most common words in the text:\n";
	printTopOfWords(words, 20);

	system("pause");
	return  0;
}

void printTopOfWords(std::vector<std::string>& words, int wordsInTop) {
	const auto frequency = getWordsFrequency(words);
	const auto topSize = std::min(wordsInTop, static_cast<int>(frequency.size()));

	for (int i = 0; i < topSize; i++) {
		std::cout << "- " << frequency[i].first << ": " << frequency[i].second << std::endl;
	}
}

std::vector<std::pair<std::string, int>> getWordsFrequency(std::vector<std::string> &words) {
	auto mapOfWords = getMapOfWords(words);

	std::vector<std::pair<std::string, int>> frequency(
		mapOfWords.begin(), mapOfWords.end()
	);

	static auto comparator = [](
		const std::pair<std::string, int> &a, 
		const std::pair<std::string, int> b
	) {
		return a.second > b.second;
	};

	std::sort(frequency.begin(), frequency.end(), comparator);

	return frequency;
}

std::unordered_map<std::string, int> getMapOfWords(std::vector<std::string>& words) {
	std::unordered_map<std::string, int> mapOfWords;

	for (auto& word : words) {
		mapOfWords[word] = mapOfWords[word] + 1;
	}

	return mapOfWords;
}

std::vector<std::string> readWordsFromFile(const std::string url, int count) {
	static const std::regex wordRegex("[.,;-\?]");
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