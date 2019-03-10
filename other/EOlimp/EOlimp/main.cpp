#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;

	int a = s[0] - '0';
	int b = s[1] - '0';
	int c = s[2] - '0';
	int d = s[3] - '0';
	int e = s[4] - '0';

	bool res = a < b && b < c && c < d && d < e;

	cout << (res ? "YES" : "NO") << endl;

	system("pause");
	return 0;
}