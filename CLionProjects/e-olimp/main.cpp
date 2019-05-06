#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m, tmp;
    cin >> n >> m;

    vector<int> arr(n), map(10), res;

    for (int &a : arr) cin >> a;
    for (int i = 0; i < m; i++) {
        cin >> tmp;
        map[tmp] = 1;
    }

    for (auto &a : arr) {
        if (!map[a]) continue;

        res.push_back(a);
        map[a] = 0;
    }

    for (int &a : res) {
        cout << a << " ";
    }

    cout << endl;

    return 0;
}