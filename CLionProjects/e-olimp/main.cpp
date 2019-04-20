#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    vector<pair<int, int>> res;

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

    cout << firstCommon << endl;

   /* for (int i = n - 2; i >= 0; i--) {
        if (arr[i] == arr[i + 1]) continue;

        int d = arr[i + 1] - arr[i];
        int op = (d > 0) ? 1 : 2;

        arr[i] += d;

        res.emplace_back(op, i + 1);
    }*/

    cout << res.size() << "\n";

    for (auto &item : res) {
        cout << item.first << " " << item.second << " " << item.second + 1 << "\n";
    }

    return 0;
}