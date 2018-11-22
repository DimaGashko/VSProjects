#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

string decodeHamming(string word);

int main() {
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
		
	cout << '|' << char(14) << char(4) << '|' << endl;
	cout << '|' << char(14) << char(0) << '|' << endl;

	auto res = decodeHamming("0010111101");
	cout << res << endl;

	cout << endl;
	system("pause");
	return 0;
}

string decodeHamming(string word) {
	int size = word.length();
	if (size < 3) {
		cerr << "Code word have to have leat 3 bits";
		return "";
	}

	int errIndex = -1;


	return word;
}






