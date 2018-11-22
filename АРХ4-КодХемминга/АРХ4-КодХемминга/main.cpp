#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Получает строку данных. Возвращает строку с исправленными ошибками
// wordSize - размер кодовых слов
string decode(string str, int wordSize = 12);

// Получает вектор закодированных битов и возвращает
// Массив исправленных информационых битов
// wordSize - размер кодовых слов
vector<bool> decode(vector<bool> code, int wordSize = 12);

// Преобразует переданную строку в массив битов
vector<bool> getCode(string str);

// Преобразует массив битов в строку
string getStrOfCode(vector<bool> code);

// Получает кодовое слово и возвращает разшифрованное
vector<bool> decodeHamming(vector<bool> word);

// Преобразует массив битов в число
int toNumFromWord(vector<bool> word);

// Преобразует переданное число в вектор битов
// size - разрядность числа
// (то есть переводит число из 10 СЧ в 2
vector<bool> toWord(int val, int size = 32);

// Преобразует слово в виде строки в слово в виде битов
vector<bool> toWord(string strWord);

// Преобразует слово в виде битов в слово в виде строки
string toStrWord(vector<bool> word);

/**
* Запрашивает от пользователя значение нужного типа
* @param{char[]} label - текст, что будет показанно пользователю
*
* Пример работы:
* prompt<int>("Введите целое число: ");
* prompt<char>("Введите символ: ");
* prompt<string>("Введите строку: ");
*/
template <typename T>
T prompt(const char label[]);

void printHello();

int main() {
	printHello();

	while (true) {
		int wordSize = prompt<int>("Enter the size of the code word: ");
		string input = prompt<string>("Enter the Message: ");
		cout << endl;

		string output = decode(input, wordSize);

		cout << " Input: " << input << endl;
		cout << "Output: " << output << endl << endl;

		if (prompt<string>("Again? (1 - yes): ") != "1") break;
		cout << "- - - - - -" << endl << endl;
	}

	return 0;
}

string decode(string str, int wordSize) {
	vector<bool> code = getCode(str);
	return getStrOfCode(decode(code, wordSize));
}

vector<bool> decode(vector<bool> code, int wordSize) {
	if (wordSize < 3) wordSize = 3;

	vector<bool> decode;

	for (int i = code.size(); i >= wordSize; i -= wordSize) {
		vector<bool> word(code.begin() + i - wordSize, code.begin() + i);
		vector<bool> wordDecode = decodeHamming(word);

		decode.insert(decode.begin(), wordDecode.begin(), wordDecode.end());
	}

	return decode;
}

vector<bool> getCode(string str) {
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

	return code;
}

string getStrOfCode(vector<bool> code) {
	const short BITS_IN_CHAR = 8;
	const int size = code.size();

	string str;

	for (int i = 0; i <= size - BITS_IN_CHAR; i += BITS_IN_CHAR) {
		vector<bool> charWord(code.begin() + i, code.begin() + i + BITS_IN_CHAR);
		str += (char)toNumFromWord(charWord);
	}

	return str;
}

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

template <typename T>
T prompt(const char label[]) {
	cout << label;

	while (true) {
		T val;
		cin >> val;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Wrong. Try again: ";
		}
		else {
			cin.ignore(32767, '\n');
			return val;
		}

	}

}