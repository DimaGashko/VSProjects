#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> maze;
int n = 0;

void writeMaze() {
	cin >> n;

	maze = vector<string>(n);

	for (int i = 0; i < n; i++) {
		cin >> maze[i];
	}
}

int main() {
	writeMaze();

	

	system("pause");
	return 0;
}
