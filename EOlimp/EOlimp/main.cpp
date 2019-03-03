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
	if (pos.x == goal.x && pos.y == goal.y) {
		// check on minWay;
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
	
}

int main() {
	//init();
	//nextStep(start);
	//printResult();

	vector<Pos> a;

	a.push_back({ 1, 1 });
	a.push_back({ 2, 2 });
	a.push_back({ 3, 3 });
	a.push_back({ 4, 4 });
	a.push_back({ 5, 5 });

	vector<Pos> b(a);
	
	a[0].x = 8;
	a[1].x = 8;
	a[2].x = 8;
	a[3].x = 8;
	a[4].x = 8;
	
	for (auto item : b) {
		cout << item.x << " ";
	}

	cout << endl;

	system("pause");
	return 0;
}