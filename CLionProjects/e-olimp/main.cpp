#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);

    for (auto &item : arr) {
        cin >> item;
    }

    int max = 1, curSize = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            curSize++;
            continue;
        }

        if (curSize > max) {
            max = curSize;
        }

        curSize = 1;
    }

    if (curSize > max) {
        max = curSize;
    }

    cout << max << "\n";

    return 0;
}