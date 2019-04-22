#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, res = 0;
    cin >> n;

    vector<int> arr{100, 20, 10, 5, 1};

    for (auto &item : arr) {
        res += n / item;
        n = n % item;
    }

    cout << res << endl;

    return 0;
}

