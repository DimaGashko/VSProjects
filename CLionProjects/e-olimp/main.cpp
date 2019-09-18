#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    string s;
    cin >> s;

    char min = s[0];

    for (auto c : s) {
        if (c > min) {
            cout << "Ann" << endl;
        } else {
            cout << "Mike" << endl;
        }

        if (c < min) min = c;
    }

    return 0;
}

/**
// B

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int n;
    cin >> n;

    vector<vector<ll>> m(n, vector<ll>(n));
    vector<ll> a(n);

    for (auto &row : m) {
        for (auto &item : row) {
            cin >> item;
        }
    }

    a[n - 2] = (ll)sqrt((m[n - 3][n - 2] * m[n - 2][n - 1]) / m[n - 3][n - 1]);
    a[n - 1] = m[n - 2][n - 1] / a[n - 2];
    a[n - 3] = m[n - 3][n - 2] / a[n - 2];

    for (int i = n - 4; i >= 0; i--) {
        a[i] = m[i + 1][i] / a[i + 1];
    }

    for (auto &item : a) {
        cout << item << ' ';
    }

    cout << endl;
    return 0;
}

*/
