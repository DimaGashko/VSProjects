#include <bits/stdc++.h>

using namespace std;

int step(int n) {
    if (n == 2) return 2;

    int r1 = ceil(n / 2.);
    int res1 = r1 * 2 - n;

    int r2 = n / 2;
    int res2 = n - r2 * 2;

    return min(res1, res2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;

        cout << step(k) << endl;
    }

    return 0;
}