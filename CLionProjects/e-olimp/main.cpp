#include <bits/stdc++.h>

using namespace std;

#define endl "\n"


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();

    int w, h, k, res = 0;
    cin >> w >> h >> k;

    for (int i = 0; i < k; i++) {
        res += w * 2 + h * 2 - 4;
        w -= 4;
        h -= 4;
    }

    cout << res << endl;

    return 0;
}