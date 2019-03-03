#include <iostream>
#include <vector>
#include <list>
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

list<Pos> currentWay;
list<Pos> minWay;

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
		}
	}
}

bool isEmpty(Pos pos) {
	if (pos.x < 0 || pos.y < 0 || pos.x >= n || pos.y >= n) return false;

	return taskMap[pos.x][pos.y] != 'O';
}

void updateMinWay() {
	if (currentWay.size() >= minWay.size() && !minWay.empty()) {
		return;
	}

	minWay = currentWay;
}

void nextStep(Pos pos) {
	if (pos.x == goal.x && pos.y == goal.y) {
		currentWay.push_back(pos);
		updateMinWay();
	}

	if (visited[pos.x][pos.y]) return;
	visited[pos.x][pos.y] = true;

	currentWay.push_back(pos);

	Pos left = { pos.x - 1, pos.y };
	Pos top = { pos.x, pos.y - 1 };
	Pos right = { pos.x + 1, pos.y };
	Pos bottom = { pos.x, pos.y + 1 };

	if (isEmpty(left)) nextStep(left);
	if (isEmpty(top)) nextStep(top);
	if (isEmpty(right)) nextStep(right);
	if (isEmpty(bottom)) nextStep(bottom);

	currentWay.pop_back();
}

void printResult() {
	if (minWay.empty()) {
		cout << "N" << endl;
		return;
	}

	cout << "Y" << endl;

	minWay.pop_front();

	for (auto pos : minWay) {
		taskMap[pos.x][pos.y] = '+';
	}

	for (auto row : taskMap) {
		cout << row << endl;
	}
}

int main() {
	init();
	nextStep(start);
	printResult();

	system("pause");
	return 0;
}