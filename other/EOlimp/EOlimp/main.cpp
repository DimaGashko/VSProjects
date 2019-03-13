#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

map<char, char> coBrackets { 
	{'(', ')'},
	{'[', ']'},
	{'{', '}'},
};

bool validate(string str) {
	stack<char> seq;

	for (auto& c : str) {
		if (c == '(' || c == '[' || c == '{') {
			seq.push(c);
		}

		else if (c == ')' || c == ']' || c == '}') {
			if (seq.empty()) return 0;
			if (coBrackets[seq.top()] != c) return 0;
			seq.pop();
		}
	}

	return seq.empty();
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		string str;
		cin >> str;

		if (str.empty()) cout << "Yes" << endl;
		else cout << (validate(str) ? "Yes" : "No") << endl;
	}
	
	system("pause");
	return 0;
}