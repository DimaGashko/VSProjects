#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    vector<array<int, 3>> res;

    for (auto &item : arr) {
        cin >> item;
    }

    unordered_map<int, int> numMap;

    for (auto &item : arr) {
        numMap[item] = numMap[item] + 1;
    }

    int common = -1;
    int commonCount = -1;

    for (auto &item : numMap) {
        if (item.second <= commonCount) continue;

        common = item.first;
        commonCount = item.second;
    }

    int firstCommon = 0;
    while (arr[firstCommon] != common) firstCommon++;

    for (int i = firstCommon - 1; i >= 0; i--) {
        if (arr[i] == common) continue;

        int d = common - arr[i];
        int op = (d > 0) ? 1 : 2;

        res.push_back(array<int, 3>{{op, i + 1, i + 2}});
    }

    for (int i = firstCommon + 1; i < n; i++) {
        if (arr[i] == common) continue;

        int d = common - arr[i];
        int op = (d > 0) ? 1 : 2;

        res.push_back(array<int, 3>{{op, i + 1, i}});
    }

    cout << res.size() << "\n";

    for (auto &item : res) {
        cout << item[0] << " " << item[1] << " " << item[2] << "\n";
    }

    return 0;
}