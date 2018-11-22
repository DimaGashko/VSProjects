﻿#include <iostream>
#include <windows.h>
#include <string>
#include <vector>

using namespace std;

vector<bool> decodeHamming(vector<bool> word);

vector<bool> toWord(string strWord);
string toStrWord(vector<bool> word);

int main() {
	string input = "0011011101";
	auto output = decodeHamming(toWord(input));

	cout << input << endl;
	cout << toStrWord(output) << endl;

	system("pause");
	return 0;
}

vector<bool> decodeHamming(vector<bool> word) {
	int size = word.size();

	if (size < 3) {
		cerr << "Code word have to have leat 3 bits";
		return word;
	}
	
	short errors = 0; //Количество несовпавших проверочных битов
	int errIndex = -1; //Индекс бита с ошибкой

	for (int r = 1; r <= size; r *= 2) {
		int res = 0;

		for (int i = r; i <= size; i += 2 * r) {
			for (int j = 0; j < r; j++) {
				int index = i + j - 1;
				if (index >= size) break;

				res ^= word[i + j - 1];
			}
		}

		if (res != 0) {
			errors++;
			errIndex += r;
		}
	}

	if (errors >= 2) {
		word[errIndex] = !word[errIndex];
		cout << "Error in a bit by index: " << errIndex << endl;
	}
	else if (errors == 1) {
		cout << "Error in parity bit by index: " << errIndex << endl;
	}



	return word;
}

vector<bool> toWord(string strWord) {
	vector<bool> word;

	for (char strBit : strWord) {
		word.push_back(strBit == '1' ? 1 : 0);
	};

	return word;
}

string toStrWord(vector<bool> word) {
	string strWord;

	for (bool bit : word) {
		strWord += (bit == 1) ? "1" : "0";
	};

	return strWord;
}


