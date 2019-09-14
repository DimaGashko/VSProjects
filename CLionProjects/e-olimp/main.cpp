#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define vi vector<int>
#define mii map<int, int>

// 7:40

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, res = 0, prev = -1, cur, realAi = -1;
    cin >> n;
    n *= 2;

    vi v(n);
    mii m;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        m[v[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        int a = (realAi != -1) ? v[realAi] : v[i];
        int b = v[i + 1];

        if (m[a] == i) cur = a;
        else if (m[b] == i + 1) cur = b;
        else if (m[a] - i > m[b] - i + 1) cur = a;
        else cur = b;

        cout << cur << ' ' << (cur == a) << endl;

        if (prev == cur) res++;

        if (realAi == -1) realAi = i;

        realAi = (cur == a) ? i + 1 : realAi;
        if (realAi == -1) realAi = i;

        prev = cur;
    }

    cout << endl << res << endl;

    return 0;
}
