#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

void readWordsFromFile(std::vector<std::string> &words, const std::string url);

template <typename T>
T prompt(const char label[]);

int main() {
	std::vector<std::string> words(2000);
	readWordsFromFile(words, "loremText2000.txt");

	std::cout << words.size() << std::endl;

	system("pause");
	return  0;
}

void readWordsFromFile(std::vector<std::string>& words, const std::string url) {
	std::ifstream fin(url);

	if (!fin) {
		throw std::runtime_error("Can't open the file");
	}

	std::string nextWord;

	for (auto& word : words) {
		if (!(fin >> nextWord)) break;
		word = nextWord;
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