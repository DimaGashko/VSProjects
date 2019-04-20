#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, res = 0;
    cin >> n;

    vector<pair<int, int>> arr(n);
    vector<bool> visited(n);

    for (auto &p : arr) {
        cin >> p.first;
        cin >>p.second;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) continue;

                for (int p = 0; p < n; i++) {

                }

            }
        }
    }

    return 0;
}