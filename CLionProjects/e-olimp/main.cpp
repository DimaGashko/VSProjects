#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int n, resLen = 0;
vector<int> arr;
vector<int> res;
map<int, int> numMap;

void init() {
    cin >> n;

    arr = vector<int>(n);
    res = vector<int>(n / 2);

    for (int i = n - 1; i >= 0; i--) {
        cin >> arr[i];
    }

    for (auto &num : arr) {
        numMap[num]++;
    }
}

void run() {
    for (auto &cur : arr) {
        if (numMap[cur] <= 0) continue;

        int newV = int(cur * 0.75);
        if (numMap[newV] <= 0) continue;

        res[resLen++] = newV;
        numMap[newV]--;
    }

    sort(res.begin(), res.end());
}

void printRes() {
    for (auto &num : res) {
        cout << num << "\n";
    }
}

int main() {
    init();
    run();
    printRes();

    return 0;
}