#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        long long a, b, c;
        cin >> a >> b >> c;

        cout << (a + b + c) / 2 << endl;
    }

    return 0;
}
