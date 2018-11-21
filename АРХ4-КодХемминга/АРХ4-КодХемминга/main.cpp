#include <iostream>
#include <windows.h>

using namespace std;

int main() {
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
		
	cout << '|' << char(14) << char(4) << '|' << endl;
	cout << '|' << char(14) << char(0) << '|' << endl;

	cout << endl;
	system("pause");
	return 0;
}