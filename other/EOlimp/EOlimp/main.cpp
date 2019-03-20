#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

namespace dg {

	class Map {
	public:

		typedef std::pair<std::string, int> Slot;

		Map();
		Map(int capacity);

		void set(std::string& key, int val);
		int get(std::string& key);

		std::vector<Slot> toVector();

		~Map();

	private:
		int m_capacity;

		std::vector<Slot> m_slots;

		int hash(std::string& key, int i) const;

		static void checkKey(std::string& key);
	};

};

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

		std::string standardNum = toStandardForm(number, baseAssociationMap);
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
		else if (c == 'a' || c == 'b' || c == 'c') c = '3';
		else if (c == 'a' || c == 'b' || c == 'c') c = '4';
		else if (c == 'a' || c == 'b' || c == 'c') c = '5';
		else if (c == 'a' || c == 'b' || c == 'c') c = '6';
		else if (c == 'a' || c == 'b' || c == 'c') c = '7';
		else if (c == 'a' || c == 'b' || c == 'c') c = '8';
		else if (c == 'a' || c == 'b' || c == 'c') c = '9';
	}

	return resNum;
}


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

// dg::Map
#include <stdexcept>

namespace dg {

	Map::Map() :
		Map(98317)
	{

	}

	Map::Map(int capacity) :
		m_capacity(capacity),
		m_slots(m_capacity)
	{

	}

	void Map::set(std::string& key, int val) {
		checkKey(key);

		for (int i = 0; i < m_capacity; i++) {
			auto& item = m_slots[hash(key, i)];

			if (item.first == key || item.first.empty()) {
				item.first = key;
				item.second = val;

				return;
			}

		}

		throw std::runtime_error("Map is full");
	}

	int Map::get(std::string& key) {
		checkKey(key);

		for (int i = 0; i < m_capacity; i++) {
			const auto& item = m_slots[hash(key, i)];

			if (item.first == key || item.first.empty()) {
				return item.second;
			}
		}

		return 0;
	}

	int Map::hash(std::string& key, int i) const {
		static int d = 256;
		int hash = 0;

		for (auto c : key) {
			hash += c * d;
		}

		hash = hash % m_capacity;

		return (hash + i) % m_capacity;
	}

	std::vector<Map::Slot> Map::toVector() {
		std::vector<Slot> vec;

		for (auto& slot : m_slots) {
			if (slot.first.empty()) continue;

			vec.push_back(slot);
		}

		return vec;
	}

	void Map::checkKey(std::string & key) {
		if (key.empty()) throw std::runtime_error("The key can't be empty");
	}

	Map::~Map() = default;
}
