#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

void run() {
    int n;
    string s;

    cin >> n >> s;

    int first = find(s.begin(), s.end(), '8') - s.begin();

    cout << (n - first >= 11 ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        run();
    }

    return 0;
}
