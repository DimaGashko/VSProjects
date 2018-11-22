﻿#include <iostream>
#include <windows.h>
#include <string>
#include <vector>

using namespace std;

vector<bool> decodeHamming(vector<bool> word);
string decodeStr(string str, int wordSize = 12);
vector<bool> getCodeWord(string str);

vector<bool> toWord(string strWord);
vector<bool> toWord(int val, int size = 32);

string toStrWord(vector<bool> word);
int toNumFromWord(vector<bool> word);

void printHello();

int main() {
	printHello();

	while (true) {
		string input, output;

		cout << "Input the Message: ";
		cin >> input;
		cout << endl;

		output = decodeStr(input);

		cout << "Input: " << input << endl;
		cout << "Output: " << output << endl << endl;

		cout << "Again? (1 - yes): ";
		string again; cin >> again;
		if (again != "1") break;

		cout << "- - - - - -" << endl << endl;
	}

	/*string input = "111000000100"; //"0010011101";
	auto output = decodeHamming(toWord(input));

	cout << input << endl;
	cout << toStrWord(output) << endl;

	system("pause");*/
	return 0;
}

string decodeStr(string str, int wordSize) {
	auto code = getCodeWord(str);
	cout << toStrWord(code) << endl;

	return str;
}

vector<bool> getCodeWord(string str) {
	const short BITS_IN_CHAR = 8;
	const int len = str.length();
	const int size = len * BITS_IN_CHAR;
	
	vector<bool> code(size);

	for (int i = 0; i < len; i++) {
		auto word = toWord(int(str[i]), BITS_IN_CHAR);

		for (int j = 0; j < BITS_IN_CHAR; j++) {
			code[i * BITS_IN_CHAR + j] = word[j];
		}
	}
	cout << "\a\a\a\a\a";
	return code;
}

//Возвращает вектор битов числа
//val - число, bits - требуемое количество битов
vector<bool> toWord(int val, int size) {
	vector<bool> word(size, 0);

	for (int bit = 0; bit < size; bit++) {
		word[size - bit - 1] = val & (1 << bit);
	}

	return word;
};

int toNumFromWord(vector<bool> word) {
	int size = word.size();
	int res = 0;

	for (int bit = size - 1; bit >= 0; bit--) {
		res = res * 2 + word[size - bit - 1];
	}

	return res;
};

vector<bool> decodeHamming(vector<bool> word) {
	int size = word.size();

	if (size < 3) {
		cerr << "Code word have to have least 3 bits" << endl;
		return word;
	}
	
	short errors = 0; // Количество несовпавших проверочных битов
	int errIndex = -1; // Индекс бита с ошибкой

	for (int r = 1; r <= size; r <<= 1) {
		int res = 0;

		for (int i = r; i <= size; i += 2 * r) {
			for (int j = 0; j < r; j++) {
				int index = i + j - 1;
				if (index >= size) break;

				res ^= (int)word[index];
			}
		}

		if (res != 0) {
			errors++;
			errIndex += r;
		}
	}

	if (errors >= 2) {
		if (errIndex >= size) return word; //Code word has more then 1 errors
		word[errIndex] = !word[errIndex];
	}
	
	//else if (errors == 1) cout << "Error in parity bit by index";

	vector<bool> res;
	for (int i = 1; i <= size; i++) {
		if ((i & (i - 1)) == 0) continue; //Проверочный бит
		res.push_back(word[i - 1]);
	}

	return res;
}

vector<bool> toWord(string strWord) {
	vector<bool> word;

	for (char strBit: strWord) {
		word.push_back(strBit == '1' ? 1 : 0);
	};

	return word;
}

string toStrWord(vector<bool> word) {
	string strWord;

	for (bool bit: word) {
		strWord += (bit == 1) ? "1" : "0";
	};

	return strWord;
}


void printHello() {
	cout << "* * * Hamming decode * * *" << endl << endl;
}