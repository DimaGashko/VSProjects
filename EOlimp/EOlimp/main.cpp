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
vector<string> taksMap;
vector<vector<bool>> visited;

vector<Pos> currentWay;
vector<Pos> minWay;

void init() {

}

bool isEmpty(Pos pos) {
	if (pos.x < 0 || pos.y < 0 || pos.x >= n || pos.y >= n) return false;

	return taksMap[pos.x][pos.y] == '.';
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