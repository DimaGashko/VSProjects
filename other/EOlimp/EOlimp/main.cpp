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

int main() {
	std::cout << toStandardForm("TUT-GLOP", baseAssociationMap) << std::endl;

	system("pause");
	return 0;
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