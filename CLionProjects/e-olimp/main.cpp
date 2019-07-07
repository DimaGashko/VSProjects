#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, ones = 0;
    string s;

    cin >> n >> s;

    for (auto &c : s) {
        if (c == '1') ones++;
    }

    if (n % 2 != 0 || ones != n / 2.0) {
        cout << 1 << endl << s << endl;
        return 0;
    }

    string s2 = string(s.begin() + 1, s.end());

    cout << 2 << endl;
    cout << s[0] << ' ' << s2 << endl;

    return 0;
}
