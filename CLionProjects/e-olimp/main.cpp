#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    if (m < n || k < n) {
        cout << "no" << endl;
        return 0;
    }

    cout << "yes" << endl;
    return 0;
}
