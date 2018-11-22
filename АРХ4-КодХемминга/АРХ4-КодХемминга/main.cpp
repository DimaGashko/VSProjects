#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

vector<bool> decodeHamming(vector<bool> word);
void printWord(vector<bool> word);

int main() {
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
		
	cout << '|' << char(14) << char(4) << '|' << endl;
	cout << '|' << char(14) << char(0) << '|' << endl;

	vector<bool> input = { 0,0,1,0,1,1,1,1,0,1 };
	auto output = decodeHamming(input);

	printWord(input);
	printWord(output);

	cout << endl;
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

	/*for (int r = 1; r <= size; r *= 2) {
		int res = 0;

		for (int i = r; r <= size;) {
			
		}

		if (res != 0) {
			errors++;
			errIndex += r;
		}
	}

	if (errors >= 2) {
		word[errIndex] = !word[errIndex];
	}
	else if (errors == 1) {
		//Error in parity bit
	}*/

	return word;
}

void printWord(vector<bool> word) {
	for (int i = 0; i < word.size(); i++) {
		cout << (int)word[i];
	}

	cout << endl;
}


