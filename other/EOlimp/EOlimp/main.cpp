#include <iostream>
#include <vector>

using namespace std;

int n;
vector<pair<int, vector<vector<int>>>> res;
vector<int> currentTasks;

void init() {
	cin >> n;

	res = vector<pair<int, vector<vector<int>>>>(n);
}

void next(vector<vector<int>> arr, int m, int i) {
	currentTasks.push_back(i);


}

void run() {
	for (int m = 0; m < n; m++) {
		next(res[m].second, m, -1);
	}
}

int main() {
	init();
	run();
		
	system("pause");
	return 0;
}