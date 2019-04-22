#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    int sf = 0;
    int fs = 0;

    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) continue;

        if (s[i] == 'F') sf++;
        else fs++;
    }

    cout << (sf > fs ? "YES" : "NO") << endl;

    return 0;
}

