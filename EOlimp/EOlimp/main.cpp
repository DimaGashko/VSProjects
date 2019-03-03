#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Pos {
	int x = 0, y = 0;
};

int n;
Pos start;
Pos goal;
vector<string> taskMap;
vector<vector<bool>> visited;

vector<Pos> currentWay;
vector<Pos> minWay;

void init() {
	cin >> n;

	taskMap = vector<string>(n);
	visited = vector<vector<bool>>(n, vector<bool>(n));

	for (int i = 0; i < n; i++) {
		cin >> taskMap[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			auto item = taskMap[i][j];

			if (item != '@' && item != 'X') {
				continue;
			}

			Pos pos = { i, j };

			if (item == '@') start = pos;
			else if (item == 'X') goal = pos;

			taskMap[i][j] = '.';
		}
	}
}

bool isEmpty(Pos pos) {
	if (pos.x < 0 || pos.y < 0 || pos.x >= n || pos.y >= n) return false;

	return taskMap[pos.x][pos.y] == '.';
}

void nextStep(Pos pos) {

}

void printResult() {
	
}

int main() {
	init();
	nextStep(start);
	printResult();

	system("pause");
	return 0;
}